/*#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pilha.h>

const int DIM = 256;

char *converter_posfixa(char *expInfixa){	//Recebe a expressão Infixa como parâmetro. Ela precisa estar com os parêntesis corretos para funcionar nesta versão do programa
	static char str_Final[256];					//Cria a string que será retornada pela função
	int posicao_livre_string = 0;			//Guarda a posição livre da String Final
	Pilha pilha_Operadores = pilha(256);	//Cria a pilha de operadores

	for (int i = 0; expInfixa[i]; ++i){		//Iterar por todos os caracteres da expressão Infixa

		if (isdigit(expInfixa[i])){			//Se for um número... Adiciona na posição livre da String Final
			str_Final[posicao_livre_string] = expInfixa[i]; 	
			posicao_livre_string++;			//Posição vazia atualizada
		}									//Próxima iteração...

*/
		//else if (strchr("+-*/", expInfixa[i])){ //Se for um operador...
		//	empilha(expInfixa[i], pilha_Operadores);	//Pilha recebe o operador da expressão Infixa
		//}										//Próxima iteração...

/*
		else if (expInfixa[i] == ')' || expInfixa[i] == '\0'){		//Se for um ')'...
			str_Final[posicao_livre_string] = desempilha(pilha_Operadores);	//stringFinal na sua posição vazia recebe o operador que estava na pilha_Operadores
			posicao_livre_string++;			//Posição vazia da string atualizada
		}									//Próxima iteração...
	}
	str_Final[posicao_livre_string] = '\0';	//Marca o fim da string
	destroip(&pilha_Operadores);
	return str_Final;
}*/

/*

int main(void){
	char expressaoInfixa[DIM];
	printf("Expressao Infixa: ");
	gets(expressaoInfixa);		//Precisa com os parêntesis para que funcione corretamente
	printf("Posfixa: %s\n", converter_posfixa(expressaoInfixa));
	return 0;
}
*/

#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
#include "pilha.h" 

int prio(char o) { 
	switch( o ) { 
		case '(': return 0; 
		case '+':  
		case '-': return 1; 
		case '*':  
		case '/': return 2; 
	} 
	return -1; // operador inválido! 
} 

char *posfixa(char *e) { 
	static char s[256]; 
	int j = 0; 
	Pilha P = pilha(256); 
	for(int i=0; e[i]; i++) {
		if( e[i]=='(' ) empilha('(',P); 
		else if( isdigit(e[i]) ) s[j++] = e[i]; 
		else if( strchr("+-/*",e[i]) ) { 
			while( !vaziap(P) && prio(topo(P))>=prio(e[i]) )  s[j++] = desempilha(P); 
			empilha(e[i],P); 
		} 
		else if( e[i] == ')' ) { 
			while( topo(P)!='(' )  
			s[j++] = desempilha(P); 
			desempilha(P); 
		}
	}
	while( !vaziap(P) ) 
		s[j++] = desempilha(P); 
	s[j] = '\0'; 
	destroip(&P); 
	return s; 
} 

int valor(char *e) { 
	Pilha P = pilha(256); 
	for(int i=0; e[i]; i++){
		if( isdigit(e[i]) ) empilha(e[i]-'0',P); 
		else { 
			int y = desempilha(P); 
			int x = desempilha(P); 
			switch( e[i] ) { 
				case '+': empilha(x+y,P); break; 
				case '-': empilha(x-y,P); break; 
				case '*': empilha(x*y,P); break; 
				case '/': empilha(x/y,P); break; 
			} 
		}
	} 
	int z = desempilha(P); 
	destroip(&P); 
	return z; 
} 


int main(void) { 
	char e[256]; 
	printf("Infixa? "); 
	gets(e); 
	printf("Posfixa: %s\n", posfixa(e)); 
	return 0; 
} 



