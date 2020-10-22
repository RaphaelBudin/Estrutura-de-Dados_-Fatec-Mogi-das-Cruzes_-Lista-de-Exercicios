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

void rem(Item x, Lista *L){
	while (*L != NULL && (*L)->item < x)
		L = &(*L)->prox;
	if (*L == NULL || (*L)->item > x) return;	//Item x não existe na lista, logo não precisa fazer nada
	Lista n = *L;
	*L = n->prox;
	free(n);
}

void rem_todo(Item x, Lista *L){
	while (*L != NULL){
		if ((*L)->item == x){
			Lista temp = *L;	//Recebe Nó atual, armazenando o endereço para ser liberado depois da atualização dos ponteiros
			*L = temp->prox;	//Nó atual passa a apontar para o próximo item da lista
			free(temp);			//Libera endereço apontado pela lista temporária
		}
		else		
			L = &(*L)->prox;	//Caso não tenha atualizado o Nó atual por ter encontrado o item correspondente, atualiza por aqui
	}
}

int main(void){
	Lista I = NULL; //Inicia uma lista com endereço NULL (o tipo Lista é um ponteiro por definição, então atribuições são sobre seu endereço de memória, e não ao Item)
	insercao(4, &I);
	insercao(1, &I);
	insercao(3, &I);
	insercao(5, &I);
	insercao(2, &I);
	//Repetidos
	insercao(4, &I);
	insercao(4, &I);
	insercao(4, &I);
	insercao(4, &I);	
	insercao(4, &I);
	rem_todo(4, &I);
	exibe(I);	
	puts("");
	return 0;	
}
