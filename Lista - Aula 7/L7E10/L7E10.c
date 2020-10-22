#include <stdio.h>
#define DIM 8

_Bool rbsearch(int alvo, int v[], int primeiraP, int ultimaP){
	if (ultimaP == primeiraP && v[primeiraP] != alvo) 
		return 0;
	int m = (ultimaP+primeiraP)/2;
	if (v[m] == alvo) return 1;
	if (v[m] < alvo){
		rbsearch(alvo,v,primeiraP,m-1);
	}
	if (v[m] > alvo){
		rbsearch(alvo,v,m+1,ultimaP);
	}
}

int main(void){
	int v[DIM] = {0,1,2,3,4,5,6,7};
	printf("3: %d\n", rbsearch(3,v,0,DIM-1));
	printf("12: %d\n", rbsearch(12,v,0,DIM-1));
	puts("");
	return 0;
}
