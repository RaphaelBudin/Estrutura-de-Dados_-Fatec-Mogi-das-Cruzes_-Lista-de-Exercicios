#include <stdio.h>
#define DIM 5

void exibe(int v[], int n){
	for (int i = 0; i < n; i++)		printf("%i ", v[i]);
}

//Explicação dessa função no exercício anterior
void empurra(int v[], int n, int posDestino){
	int menorValor = v[0], menorPosicao = 0, i = 0;
	for (i = 0; i < n; i++)	if (v[i] < menorValor)	{menorValor = v[i];	menorPosicao = i;}
	for (i = menorPosicao; i < posDestino; i++)		v[i] = v[1+i];
	v[i] = menorValor;
}

void bsr(int v[], int n){
	
	if (n == 1) return;
	empurra(v,n,n-1);
	bsr(v,n-1);
}

int main(void){
	int v[DIM] = {48,52,31,19,27};
	bsr(v,DIM);
	exibe(v,DIM);
	puts("");
	return 0;
}
