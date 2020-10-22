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

void destroi(Lista *L){
	while (*L){
		Lista n = *L;
		*L = n->prox;
		free(n);
	}
}

int ultimo(Lista L){
	int ultimo = 0;
	while (L->prox != NULL){
		L = L->prox;
	}
	ultimo = L->item;
	return (int)ultimo;
}

_Bool pertence(Item valor, Lista L){
	while (L->prox != NULL){
		if (L->item == valor) return 1;
		L = L->prox;	
	}
	return 0;
}

int main(void){
	Lista I = no(3,no(1,no(5,NULL)));
	printf("3 Pertence: %d\n", pertence(3,I));
	printf("7 Pertence: %d\n", pertence(7,I));

	puts("");
	_getch();
	return 0;
}

