#include <stdio.h>
#define DIM 10

void exibe(int v[], int n ){
	for (int i = 0; i < n; i++) printf("%i ", v[i]);
}

//Ordena o vetor divido usando a intercala��o
void intercala(int vetor[], int p, int m, int u){
	//p = "primeira posi��o do vetor"
	//m = "posi��o m�dia do vetor"
	//u = "�ltima posi��o do vetor"
	//vTemp = "vetor tempor�rio para ordenar antes de passar para o vetor[]
	//pv1 = "primeira posi��o do primeiro vetor (primeira posi��o da primeira metade do vetor completo)
	//pv2 = "primeira posi��o do segundo vetor (primeira posi��o da segunda metade do vetor completo)

	int vTemp[u-p+1];		//vTemp[�ltimaPosi��o-primeiraPosi��o+1]
	int pv1 = p;
	int pv2 = m+1;
	int posLivre = 0;

	//While que compara os valores de ambas as metades do vetor[] e os organiza
	while (pv1 <= m && pv2 <= u){ //Garante que as posi��es n�o ultrapassaram seus limites superiores
		if(vetor[pv1] < vetor[pv2])
			vTemp[posLivre++] = vetor[pv1++];
		else
			vTemp[posLivre++] = vetor[pv2++];
	}
	
	//Caso uma das metades tenha acabado e a outra n�o, um dos dois whiles ser� executado
		//Caso a segunda metade tenha acabado antes...
			while (pv1 <= m)
				vTemp[posLivre++] = vetor[pv1++];
		//Caso a primeira metade tenha acabado antes...
			while (pv2 <= u)
				vTemp[posLivre++] = vetor[pv2++];

	//For que atribui os valores ordenados do vetor tempor�rio para o vetor original
	for (posLivre = 0; posLivre <=u-p; posLivre++)
		vetor[p+posLivre] = vTemp[posLivre];
}

void intercalad(int vetor[], int vcp, int vcm, int vcu){
	//vcp == "vetor completo primeira posi��o"
	//vcm == "vetor completo m�dia posi��o"
	//vcu == "vetor completo �ltima posi��o"

	int pv1 = vcp;
	int pv2 = vcm+1;
	int vetorOrdenado[vcu-vcp+1]; //� importante declarar o n�mero de posi��es dessa forma, pois abrange a recursividade
	int posLivre = 0;			  //Posi��o livre dentro do vetorOrdenado
	
	while (pv1 <= vcm && pv2 <= vcu){
		if (vetor[pv1] >= vetor[pv2])
			vetorOrdenado[posLivre++] = vetor[pv1++];
		else
			vetorOrdenado[posLivre++] = vetor[pv2++];
	}

	while(pv1 <= vcm)
		vetorOrdenado[posLivre++] = vetor[pv1++];
	while(pv2 <= vcu)
		vetorOrdenado[posLivre++] = vetor[pv2++];

	for (int i = 0; i <= vcu; ++i)
		vetor[i] = vetorOrdenado[i];
}

//primeira = primeira posi��o do Vetor a ser ordenada
//�ltima = �ltima posi��o do Vetor a ser ordenada
//meio = posi��o m�dia do Vetor para separar
void ms (int vetor[], int primeira, int ultima){
	if (primeira == ultima) return;
	int meio  = (primeira + ultima)/2;	// Este algotimo ir� chamar recursivamente a fun��o, dividindo o vetor1 em 2 at� o momento em que haja apenas 1 valor
	ms(vetor, primeira, meio);			
	ms(vetor,meio+1,ultima);					// Quando isso acontecer,far� o mesmo processo com o vetor2
	intercala(vetor, primeira, meio, ultima);	//Quando a execu��o chegar nesta linha, o m�todo de intercalar ser� executado, partindo das menores vers�es dos vetores at� o vetor completo
}

void msort(int vetor[], int tamanho){
	ms(vetor,0,tamanho-1);
}

int main(void){
	int v[DIM] = {83,31,91,46,27 ,20,96,25,96,80};
	intercalad(v,0,DIM/2,DIM-1);
	//intercala(v,0,DIM/2,DIM-1);
	exibe(v,DIM);
	puts("");
	return 0;
}
