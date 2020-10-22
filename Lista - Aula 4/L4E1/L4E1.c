#include <stdio.h>
#include <ctype.h>
#include <pilha.h>
#include <fila.h>

int main(void){
	char frase[256], palavra;
	Fila F = fila(256); //seguindo o princípio de que os nomes devem ser significativos, queria usar o nome da variável como fila, mas como não vai ser possível, deixa como F mesmo
	Pilha P = pilha(256); //idem
	printf("\nFrase? ");
	gets(frase);
	for (int i = 0; frase[i]; ++i){
		palavra = frase[i];
		if (isalpha(palavra)){ //Verifica se o item iterado é alfanumérico
			enfileira(toupper(palavra), F);
			empilha(toupper(palavra), P);
		}	
	}
	//A pilha P está com a string inversa, e a Fila com a string original
	//Um palíndromo precisa ter a mesma sequência de caracteres em ambos os sentidos
	//Logo, o último caractere deve ser igual ao primeiro, o segundo igual ao penúltimo e assim por adiante...
	//Pilha e Fileira são Estruturas de Dados perfeitas para esse tipo de operação
	while (!vaziaf(F) && desenfileira(F)==desempilha(P)); //Se for um palíndromo, esse while deve ser executado até a Fila (e pilha) estiver vazia
	if (vaziaf(F)) printf("Eh um palindromo! \n");
	else printf("Nao eh um palindromo! \n");
	puts("");
	return 0;
}
