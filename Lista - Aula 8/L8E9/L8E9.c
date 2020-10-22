#include <stdio.h>
#include <stdlib.h>
#include <fila.h>

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

Lista add(Lista *L, Item valor){
	while(L){
		L = (L->prox);
	}

}


Lista inversa(Lista L){
	Lista temp,temp2;
	int tam = tamanho(L);
	Fila valores = fila(tam);

	while(L){
		enfileira(L->item, valores);
		L = L->prox;
	}

	while(!vaziaf(valores)){
		temp2 = no(desenfileira(valores),NULL);
		anexa(&temp2, temp);
	}
	return temp;
}

int main(void){
	Lista I = no(3,no(1,no(5,NULL)));
	Lista Inversa = inversa(I);
	exibe(Inversa);
	puts("Finalizado!");
	_getch();
	return 0;
}

