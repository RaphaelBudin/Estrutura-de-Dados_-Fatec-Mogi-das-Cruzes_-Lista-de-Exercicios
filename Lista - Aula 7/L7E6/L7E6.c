#include <stdio.h>
#define DIM 10

void exibe(int v[], int n ){
	puts("");
	for (int i = 0; i < n; i++) printf("%i ", v[i]);
}

void intercalad(int vetor[], int p, int m, int u){
	//vcp == "vetor completo primeira posição"
	//vcm == "vetor completo média posição"
	//vcu == "vetor completo última posição"
	int pv1 = p;
	int pv2 = m+1;
	int vetorOrdenado[u-p+1]; //É importante declarar o número de posições dessa forma, pois abrange a recursividade
	int posLivre = 0;			  //Posição livre dentro do vetorOrdenado
	
	while (pv1 <= m && pv2 <= u){
		if (vetor[pv1] >= vetor[pv2])
			vetorOrdenado[posLivre++] = vetor[pv1++];
		else
			vetorOrdenado[posLivre++] = vetor[pv2++];
	}

	while(pv1 <= m)
		vetorOrdenado[posLivre++] = vetor[pv1++];
	while(pv2 <= u)
		vetorOrdenado[posLivre++] = vetor[pv2++];

	for (int i = 0; i <= u-p; ++i)
		vetor[p+i] = vetorOrdenado[i];
		
}

//Merge Sort - Decrescente
void msd(int vetor[], int pPos, int uPos){
	//pPos = primeira posição
	//uPos = segunda posição
	if (pPos == uPos) return;	//Caso base
	int mPos = (pPos+uPos)/2;
	msd(vetor,pPos,mPos);		//Primeira metade
	msd(vetor,mPos+1,uPos);		//Segunda metade
	intercalad(vetor,pPos,mPos,uPos);
}

void msortd(int vetor[], int tamanho){
	msd(vetor,0,tamanho-1);
}

int main(void){
	int v[DIM] = {83,31,91,46,27,20,96,25,96,80};
	//int v[DIM] = {45,34,30,26,10,44,40,26};
	intercalad(v,0,DIM/2,DIM-1);
	msortd(v,DIM);
	exibe(v,DIM);
	puts("\nFinalizado!\n");
	return 0;
}


// EXPLICAÇÃO PESSOAL
//  As funções Merge Sorte funcionam da seguinte maneira:
//		Elas primeiro separam todos os valores em vetores com metade do tamanho do vetor anterior, até chegar a vetores individuais
//		Quando isso acontece, elas chamam as funções de intercalação nesses vetores individuais, depois vão regressando até o vetor completo
