#include <stdio.h>
#include <stdlib.h>
#include <pilha.h>

_Bool abertura(char temp){
	return (temp == '(' || temp == '[' || temp == '{');
}

_Bool mesmoFechamento(char temp, Pilha P){
	return (int)topo(P) == (int)temp-1 || (int)topo(P) == (int)temp-2;	//Verifica se o símbolo do frase[i] de fechamento corresponde ao símbolo de abertura no topo da pilha
}

_Bool verificaBalanceamento(Pilha P, char frase[100]){
	for (int i = 0; frase[i]; ++i){
		if (frase[i] == ' ') continue; 	//Pula espaços em branco
		if (abertura(frase[i]))						empilha(frase[i], P);
		else if (mesmoFechamento(frase[i], P))		desempilha(P);
		else return 0; 					//Quer dizer que não corresponde ao fechamento
	}
	return 1;
}

void resposta(Pilha P, char frase[100]){
	static short int  i = 1;
	verificaBalanceamento(P, frase) ? printf("\nExpressao %i - %s - Expressao balanceada!", i, frase) : printf("\nExpressao %i - %s - Expressao desbalanceada!", i, frase);
	++i;
}

int main(void){
	Pilha P = pilha (100);
	char frase1[100] = {"[ { ( ) ( ) } { } ]"};
	char frase2[100] = {"{ [ ( [ { } ] ) ] }"};
	char frase3[100] = {"{ [ ( } ]"};
	char frase4[100] = {"{ [ ) ( ) ( ] }"};
	resposta(P, frase1);
	resposta(P, frase2);
	resposta(P, frase3);
	resposta(P, frase4);

	puts("\n");
	return 0;
}
