#include <stdio.h>
#include "pilha.h"

int main(void){
	int decimal;
	Pilha P = pilha(32);
	printf("Decimal? ");
	scanf("%d", &decimal);
	do{
		empilha(decimal%2,P);
		decimal/=2;
	}while(decimal!=0);

	printf("Binario: ");
	while (!vaziap(P))
		printf("%d", desempilha(P));
	destroip(&P );
	puts("");
	return 0;
}
