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

int soma(Lista L){
	int sum = 0;
	while(L){
		sum += L->item;
		L = L->prox;
	}
	return sum;
}

void anexa(Lista *origem, Lista destino){
	//origem == Lista que fornecerá os valores para serem inseridos na lista destino
	//destino == Lista que receberá os valores fornecidos pela lista de origem
	if (!destino) return;
	while (*origem){
		origem = &(*origem)->prox;
	}
	*origem = destino;
}

int main(void){
	Lista H = no(4,no(2,NULL));
	Lista I = no(3,no(1,no(5,NULL)));
	printf("H = "); exibe(H);
	printf("I = "); exibe(I);
	printf("Pressione enter"); getchar();
	anexa(&I, H);
	printf("H = "); exibe(H);
	printf("I = "); exibe(I);
	puts("");
	_getch();
	return 0;
}

