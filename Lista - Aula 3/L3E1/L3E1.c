#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"
#define dim 256;


char *posfixa(char *expInfixa){
	static char stringFinal;		//String que será retornada pela função
	int posicaoLivre = 0;			//Posição livre da string
	Pilha Pilhosa = pilha(dim);
	for (int i = 0; expInfixa[i]; ++i){
		if (isdigit(e[i])){			//Se for um número, adiciona na string merda direto
			stringMerda[posicaoLivreStringMerda] = expInfixa[i];
			posicaoLivreStringMerda++;				//Próxima posição vazia
		}
		else if (strchr("+-*/", expInfixa[i])){
			empilha(expInfixa[i], Pilhosa);		//Pilha recebe o operador
		}
		else if (expInfixa[i] == ')'){
			stringMerda[posicaoLivreStringMerda] = desempilha(Pilhosa);
			++posicaoLivreStringMerda;
		}
	}
	stringMerda[posicaoLivreStringMerda] = '\0';
	destroip(&Pilhosa);
	return stringFinal;
}

int main(void){
	
	return 0;
}
