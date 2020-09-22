#include <stdio.h>
#include "pilha.h"

int main(void){
	Pilha P = pilha (100);
	Pilha Aux = pilha (100);	
	int numero = 0;

	while (1){
		printf("Insira um numero (ou -1 para cancelar): ");
		scanf("%i", &numero);
		if (numero == -1) break;
		if (vaziap(P) || numero > topo(P))		
			empilha(numero, P);
		else{
			//Verificação de Vaziap deve ser feita sempre primeiro!
			//Caso contrário o programa vai abortar a execução por conta checagem de erro feita na função topo
			while (!vaziap(P) && numero < topo(P)) {
				empilha(desempilha(P), Aux);
			}
			empilha(numero,P);
			while (!vaziap(Aux))
				empilha(desempilha(Aux),P);
		}
	}

	puts("Ordenado: ");
	while (!vaziap(P)){
		printf("%i ", desempilha(P));
	}
	puts("");
	return 0;
}
