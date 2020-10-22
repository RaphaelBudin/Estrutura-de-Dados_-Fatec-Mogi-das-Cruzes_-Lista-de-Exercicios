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

int pertence(Item x, Lista L){
	while (L != NULL && L->item < x)
		L = L->prox;
	return (L != NULL && L->item == x);	
}


int main(void){
	Lista I = NULL; //Inicia uma lista com endereço NULL (o tipo Lista é um ponteiro por definição, então atribuições são sobre seu endereço de memória, e não ao Item)
	insercao(4, &I);	insercao(1, &I);
	insercao(3, &I);	insercao(5, &I);
	insercao(2, &I);
	exibe(I);	
	puts("O item pertence a lista? [1 - sim / 0 - nao]:"); 
	printf("%i - %i\n", 2, pertence(2,I));
	printf("%i - %i\n", 4, pertence(4,I));
	printf("%i - %i\n", 5, pertence(5,I));
	printf("%i - %i\n", 7, pertence(7,I));
	printf("%i - %i\n", 9, pertence(9,I));
	printf("%i - %i\n", 11, pertence(11,I));
	puts("");
	return 0;	
}
