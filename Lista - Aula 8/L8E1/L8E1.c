#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no{
	int item;
	struct no *prox;
} *Lista;

Lista no(Item itemAdicionado, Lista ponteiro){
	Lista listaTemp = malloc(sizeof(struct no));
	listaTemp->item = itemAdicionado;
	listaTemp->prox = ponteiro;
	return listaTemp;
}

void exibe (Lista L){
	while(L != NULL){
		printf("%d\n", L->item);
		L=L->prox;
	}
}

int main(void){
	Lista I = no(3,no(1,no(5,NULL)));
	exibe(I);
	puts("");
	_getch();
	return 0;
}
