#include <stdio.h>
#include <conio.h>
#include "fila.h"
#include "dim.h"
.
int main(void) {
	int i, j, n;
	while( 1) {
		exiba(I);
		printf("\n\nNova cor (ou -1 para sair)? ");
		scanf("%d",&n);
		if( n<0) break;
		do{

			printf("Posicao? ");
			scanf("%d %d",&i,&j);
		} while( i<0 ||i>=dim||j<0||j>=dim);
		colori(I,i,j,n);
	}
	return 0;
}
