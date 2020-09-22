#include <stdio.h>
#include <pilha.h>

int main(void){
	Pilha P = pilha (100);
	char frase[100];
	printf("Insira a frase: ");
	gets(frase);
	for (int i = 0; frase[i]; ++i){
		empilha(frase[i], P);
	}
	puts("Frase reversa:");
	for (int i = 0; !vaziap(P); ++i){
		printf("%c", desempilha(P));
	}
	puts("");
	return 0;
}
