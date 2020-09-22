#include <stdio.h>
#include "pilha.h" // pilha de char *

//Código da apostila alterado, pois o mesmo não funcionou no Pelles C sem modificações

int main(void) {
	Pilha P = pilha(5);
	char s[11];
	for(int i=1; i<=3; i++) {
		printf("? ");
		gets(s);
		empilha(s,P);
		printf("(int): %i\n", (int)s);
	}
	while( !vaziap(P) ) printf("%c\n",desempilha(P));
return 0;
}
