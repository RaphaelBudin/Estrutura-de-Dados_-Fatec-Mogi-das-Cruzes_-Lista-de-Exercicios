/*#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pilha.h>

const int DIM = 256;

char *converter_posfixa(char *expInfixa){	//Recebe a express�o Infixa como par�metro. Ela precisa estar com os par�ntesis corretos para funcionar nesta vers�o do programa
	static char str_Final[256];					//Cria a string que ser� retornada pela fun��o
	int posicao_livre_string = 0;			//Guarda a posi��o livre da String Final
	Pilha pilha_Operadores = pilha(256);	//Cria a pilha de operadores

	for (int i = 0; expInfixa[i]; ++i){		//Iterar por todos os caracteres da express�o Infixa

		if (isdigit(expInfixa[i])){			//Se for um n�mero... Adiciona na posi��o livre da String Final
			str_Final[posicao_livre_string] = expInfixa[i]; 	
			posicao_livre_string++;			//Posi��o vazia atualizada
		}									//Pr�xima itera��o...

*/
		//else if (strchr("+-*/", expInfixa[i])){ //Se for um operador...
		//	empilha(expInfixa[i], pilha_Operadores);	//Pilha recebe o operador da express�o Infixa
		//}										//Pr�xima itera��o...

/*
		else if (expInfixa[i] == ')' || expInfixa[i] == '\0'){		//Se for um ')'...
			str_Final[posicao_livre_string] = desempilha(pilha_Operadores);	//stringFinal na sua posi��o vazia recebe o operador que estava na pilha_Operadores
			posicao_livre_string++;			//Posi��o vazia da string atualizada
		}									//Pr�xima itera��o...
	}
	str_Final[posicao_livre_string] = '\0';	//Marca o fim da string
	destroip(&pilha_Operadores);
	return str_Final;
}*/

/*

int main(void){
	char expressaoInfixa[DIM];
	printf("Expressao Infixa: ");
	gets(expressaoInfixa);		//Precisa com os par�ntesis para que funcione corretamente
	printf("Posfixa: %s\n", converter_posfixa(expressaoInfixa));
	return 0;
}
*/

#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
#include "pilha.h" 

_Bool converte(char c){
	if (c == 'F') return 0;
	if (c == 'V') return 1;
	return c;
}

_Bool isBool(char c){
	return strchr("FV01",c);
}

int prio(char o) { 
	switch( o ) { 
		case '(': return 0; 
		case '|': return 1;  
		case '&': return 2;   
		case '!': return 3; 
	} 
	return -1; // operador inv�lido! 
} 

char *posfixa(char *e) { 
	static char s[256]; 
	int j = 0; 
	Pilha P = pilha(256); 
	for(int i=0; e[i]; i++) {
		if( e[i]=='(' ) empilha('(',P); 
		//else if( isdigit(e[i]) ) s[j++] = e[i]; 
		else if (isBool(e[i])) s[j++] = e[i];
		else if( strchr("!&|",e[i]) ) { 
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
		if( isBool(e[i]) ) empilha(e[i],P); 
		else { 
			int y = converte(desempilha(P));
			int x = converte(desempilha(P)); 
			switch( e[i] ) {  
				case '|': empilha(x||y,P); break; 
				case '&': empilha(x&y,P); break; 
				case '!': empilha(!(x&&y),P); break; 
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



