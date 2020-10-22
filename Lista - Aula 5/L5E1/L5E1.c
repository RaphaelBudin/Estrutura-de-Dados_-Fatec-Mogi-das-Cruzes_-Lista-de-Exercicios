#include <stdio.h>
#include <conio.h>
#include <fila.h>

#define dim 9
#define cor(i,j) 	(i>=0 && i<dim && j>=00 && j<dim ? I[i][j] : -1)
#define par(i,j)	((i)*100+(j))
#define lin(p)		((p)/100)
#define col(p)		((p)%100)

int I[dim][dim] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,1,1,1,0,0,0},
		{0,0,1,1,1,1,1,0,0},
		{0,1,1,1,1,1,1,1,0},
		{0,0,2,0,0,0,2,0,0},
		{0,0,2,0,0,0,2,0,0},
		{0,0,2,2,2,2,2,0,0},
		{0,0,0,0,0,0,0,0,0}
};

//Exiba Matriz
void exiba(int I[dim][dim]){
	//Tanto 'i' como 'j' são inicializados com -1 para fornecer o espaçamento correto na exibição
	for (int i =-1; i < dim; i++){
		_textcolor(8);	//Cinza escuro, padrão para o plano de fundo
		for (int j =-1; j<dim; j++){
			if (i<0 && j<0) printf(" ");		//deixa a primeira célula em branco, deixando a exibição correta
			else if (i<0) printf("%2d",j);		//
			else if (j<0) printf("\n%2d",i);	//idem
			else {
				_textcolor(I[i][j]);
				printf("%c%c",219,219);
			}
		}
	}
	_textcolor(8);
}

void colorir(int I[dim][dim], int linha, int coluna, int novaCor){
	Fila F = fila(dim*dim); //Fila capaz de conter a matriz inteira
	int corAtual = I[linha][coluna]; //Guarda cor atual para futuas referências
	
	if (novaCor == corAtual) return;

	I[linha][coluna] = novaCor;
	enfileira(par(linha,coluna),F);
	
	

	while(!vaziaf(F)){
		int pixelAtual = desenfileira(F);
		linha = lin(pixelAtual);
		coluna = col(pixelAtual);

		if (cor(linha-1,coluna)==corAtual){
			I[linha-1][coluna]=novaCor;
			enfileira(par(linha-1,coluna),F);
		}
		if( cor(linha,coluna+1)==corAtual ) {
			I[linha][coluna+1]=novaCor; 
			enfileira(par(linha,coluna+1),F); 
		}
		if( cor(linha+1,coluna)==corAtual ) { 
			I[linha+1][coluna]=novaCor; 
			enfileira(par(linha+1,coluna),F); 
		}
		if (cor(linha,coluna-1)==corAtual) {
			I[linha][coluna-1]=novaCor;
			enfileira(par(linha,coluna-1),F);
		}
	}
	destroif(&F);
}


int main(void){
	int linha, coluna, cor;
	while (1){
		exiba(I);
		printf("\n\nNova cor (ou -1 para sair)? ");
		scanf("%d", &cor);
		if (cor<0) break;
		do {
			printf("Posicao? ");
			scanf("%d %d", &linha, &coluna);
		}while(linha<0 || linha>=dim || coluna<0 || coluna>=dim);
		colorir(I,linha,coluna,cor);
	}
	puts("");
	return 0;
}


/* ############## Algoritmo de Coloração #################
	1 - Crie uma fila vazia F
	2 - Obtenha a cor atual (corAtual_p) do ponto (pixel)
	3 - Mude a cor do (pixel) para (novaCor_p)
	4 - Insira (pixel) na fila F
	5 - Enquanto F não estiver vazia:
		5.1 - Remova um ponto(pixel) de F
		5.2 - Para cada (vizinho) de (pixel), que tenha a (corAtual_p), faça:
			5.2.1 - Mude a cor de (vizinho) para (novaCor_p)
			5.2.2 - Insira (vizinho) na fila F
*/
