#include <stdio.h>
#define DIM 8

_Bool rlsearch(int alvo, int v[], int ultimaPosicao){
	//Caso base - chegar ao fim do vetor
	if (ultimaPosicao < 0) 
		return 0;
	if (v[ultimaPosicao] == alvo) 
		return 1;
	rlsearch(alvo,v,ultimaPosicao-1);
}

int main(void){
	int v[DIM] = {0,1,2,3,4,5,6,7};
	printf("0: %d\n", rlsearch(0,v,DIM-1));
	printf("12: %d\n", rlsearch(12,v,DIM-1));
	puts("");
	return 0;
}

