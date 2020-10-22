#include <stdio.h>
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

void insercao_sr(Item itemX, Lista *L){
	while (*L != NULL && (*L)->item < itemX){
		L = &(*L)->prox;
	}
	if (*L == NULL || (*L)->item != itemX)	//Se for NULL, estamos no último elemento da lista, então pode ser adicionado sem problemas. Se não existir nessa posição, também
		*L = no(itemX,*L);
}

int main(void){
	Lista I = NULL; //Inicia uma lista com endereço NULL (o tipo Lista é um ponteiro por definição, então atribuições são sobre seu endereço de memória, e não ao Item)
	insercao(4, &I);
	insercao(1, &I);
	insercao(3, &I);
	insercao(5, &I);
	insercao(2, &I);
	insercao_sr(4, &I);	//Repetido
	insercao_sr(5, &I); //Repetido
	insercao_sr(7, &I); //Novo
	insercao_sr(8, &I);	//Novo
	insercao_sr(7, &I);	//Repetido
	insercao_sr(8, &I);	//Repetido
	exibe(I);
	return 0;	
}
