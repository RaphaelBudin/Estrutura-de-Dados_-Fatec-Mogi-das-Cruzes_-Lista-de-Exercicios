#include <stdio.h>
#include <fila.h>

int main(void){
	Fila F = fila(5);
	for (int i = 0; i <= 3; i++)
		enfileira('A'+i,F);	//ao somar o 'i' com o 'A', iremos percorrer o alfabeto
	while(!vaziaf(F))
		printf("%c\n", desenfileira(F));
	destroif(&F);
	puts("");
	return 0;	
}
