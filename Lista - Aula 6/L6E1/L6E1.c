#include <stdio.h>

int fat(int numero){
	if (numero == 0) return 1;
	return numero*fat(numero-1);	
}

int main(void){
	int numero;
	printf("Num? ");
	scanf("%d", &numero);
	printf("Fat = %d\n", fat(numero));
	puts("");
	return 0;	
}
