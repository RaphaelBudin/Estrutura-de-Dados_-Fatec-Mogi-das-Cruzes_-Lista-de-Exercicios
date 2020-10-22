#include <stdio.h>
#define DIM 8
int lsearch(int v[], int dim, int alvo){
	for (int i = 0; i < dim; ++i)
		if (v[i] == alvo)
			return 1;
	return 0;
}

int main(void){
	int v[DIM] = {66,80,31,48,27,75,19,52};
	printf("27: %d\n", lsearch(v,DIM,27));
	printf("51: %d\n", lsearch(v,DIM,51));
	puts("");
	return 0;
}
