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
	printf("[");
	while(L != NULL){
		printf("%d", L->item);
		L=L->prox;
		if (L!=NULL) printf(",");
	}
	printf("]\n");
}

int tamanho(Lista L){
	int tam = 0;
	while (L){
		tam++;
		L = L->prox;
	}
	return tam;
}


int main(void){
	Lista I = no(3,no(1,no(5,NULL)));
	exibe(I);
	printf("Tamanho = %d\n", tamanho(I));
	puts("");
	_getch();
	return 0;
}

