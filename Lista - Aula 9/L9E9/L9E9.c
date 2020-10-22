#include <stdio.h>
#include <stdlib.h>
#define DIM 5
typedef int Item;		//Por padrão é um int, mas ser redefinido para abranger outros tipos
typedef struct no{	
	Item item;			//Armazena o valor em si
	struct no *prox;	//Aponta para o próximo nó da lista
} *Lista;				//Tipo Lista é usado para declarar um ponteiro de lista (que aponta o primeiro nó)

Lista no(Item itemX, Lista endereco){
	Lista novoNo = malloc(sizeof(struct no));	//n é do tipo Lista, que é um ponteiro, por isso não é necessário o uso de '*'
	novoNo->item = itemX;
	novoNo->prox = endereco;
	return novoNo;
}

void insercao(Item itemX, Lista *L){
	//Enquanto o endereço de memória da Lista L (*L) não for NULL e o atributo item desse endereço de memória for menor que o inserido...
	while (*L != NULL && (*L)->item < itemX)
		L = &(*L)->prox;	//L recebe o endereço de memória que L aponta como próximo
	*L = no(itemX,*L);		//Finalmente, atribui
}

void exibe(Lista L){
	puts("Itens: ");
	while (L){
		printf("%i ", L->item);
		L = L->prox;
	}
	puts("");
}

int pertence(Item x, Lista L){
	while (L != NULL && L->item < x)
		L = L->prox;
	return (L != NULL && L->item == x);	
}

int pertence_rec(Item x, Lista L){
	if (L == NULL) return 0;		//Tem que vir primeiro, pois tentar acessar o atributo item em um Nó NULL gerará uma exceção
	if (L->item == x) return 1;
	return pertence_rec(x, L->prox);
}


int main(void){
	Lista I = NULL; //Inicia uma lista com endereço NULL (o tipo Lista é um ponteiro por definição, então atribuições são sobre seu endereço de memória, e não ao Item)
	insercao(4, &I);	insercao(1, &I);
	insercao(3, &I);	insercao(5, &I);
	insercao(2, &I);
	exibe(I);	
	int v[DIM] = {2,4,6,8,1};
	for (int i = 0; i < DIM; i++){
		printf("O numero %i pertence a lista? [1-sim/0-nao]: %i\n",v[i], pertence_rec(v[i],I));	
	}
	puts("");
	return 0;	
}
