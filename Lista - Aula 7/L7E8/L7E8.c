#include <stdio.h>
#define DIM 8

_Bool binbusca(int v[], int dim, int alvo){
	int p = 0; //Primeira posi��o
	int u = dim-1;	//�ltia posi��o
	int m;	//posi��o m�dia
	
	while(p<=u){	//Garante que est� dentro do escopo do vetor
		m = (p+u)/2;
		if (alvo == v[m]) 	return 1; //Achou-se o alvo
		if (alvo < v[m]) 	u = m-1; //Estabelece a metade como limite superior do "novo" vetor
		else p = m+1;				//Estabelece a metade como limite inferir do "novo" vetor
	}
	return 0;
}

int main(void){
	int v[DIM] = {19,27,31,48,52,66,75,80};
	printf("27: %d\n", binbusca(v,DIM, 27));
	printf("51: %d\n", binbusca(v,DIM, 51));
	puts("");
	return 0;
}
