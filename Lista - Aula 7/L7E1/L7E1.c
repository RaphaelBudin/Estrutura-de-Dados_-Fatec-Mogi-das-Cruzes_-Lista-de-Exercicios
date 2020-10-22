#include <stdio.h>

void troca(int v[], int pos1, int pos2){
	int temp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = temp;
}

void bsort(int v[], int n){
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <n-i; j++)
			if(v[j]>v[j+1])
				troca(v,j,j+1);
}

void exibe(int v[], int n){
	for (int i = 0; i < n; ++i)
		printf("%i ", v[i]);
	puts("");	
}

int main(void){
	int v[10] = {83,31,91,46,27,20,96,25,96,80};
	bsort(v,10);
	exibe(v,10);
	puts("");
	return 0;	
}
