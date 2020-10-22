﻿#include <stdio.h>
#include <stdlib.h>
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

void ins_rec(Item itemX, Lista *L){
	if (*L == NULL || (*L)->item > itemX){ //Casos bases: Nó endereço NULL ou item da lista ordnada ou ->item > que itemX
		*L = no(itemX, *L);	//Pode adicionar o nó
		return;		
	}
	ins_rec(itemX, &(*L)->prox); //Chama a função recursivamente com o endereço do próximo nó
}


int main(void){
	Lista I = NULL; //Inicia uma lista com endereço NULL (o tipo Lista é um ponteiro por definição, então atribuições são sobre seu endereço de memória, e não ao Item)
	ins_rec(4, &I);
	ins_rec(1, &I);
	ins_rec(3, &I);
	ins_rec(5, &I);
	ins_rec(2, &I);
	exibe(I);
	return 0;	
}
