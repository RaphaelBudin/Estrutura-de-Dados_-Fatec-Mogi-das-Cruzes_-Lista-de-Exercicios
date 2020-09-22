#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pilha.h>


char *mostrarString(char *str){
	static char aux[256];
	int i;
	for (i = 0; str[i]; ++i)
		aux[i] = str[i];
	aux[i] = str[i];
	return aux;
}

int prio(char o) {
	switch( o ) {
		case '(': return 0; //Precedência baixa
		case '+':
		case '-': return 1; //Precedência média
		case '*':
		case '/': return 2;	//Precedência alta
}
return -1; // operador inválido!
}

char *posfixa(char *expressaoInfixa) {
	static char stringAux[256];		//String Aux - Serve para:
									// 1 - Guardar todos os números (sem operadores)
	int j = 0;			
	Pilha P = pilha(256);			//pilha P - Serve para:
									//1 - Guardar os operadores
									//2 - Guardar os números entre parentesis

	for(int i=0; expressaoInfixa[i]; i++){							//Até o for achar o '\0' dentro da string
		//printf("ExpressaoInfixa[i] = %c\n",expressaoInfixa[i]);
		if( expressaoInfixa[i]=='(' ){ 								//Se for '('...
			empilha('(',P);										//Empilha o '(' na pilha P
		} 							
		else if( isdigit(expressaoInfixa[i]) ){ 						//Se for um número...
			stringAux[j++] = expressaoInfixa[i];					//stringAux recebe apenas os números
		}
		else if( strchr("+-/*",expressaoInfixa[i]) ) {			//Caso não seja '(' nem um número, verifica se é um dos operadores básicos

			//Se for...
			//Depois verifica a ordem de prioridade das operações
			//Se for um operador básico...
			//... verifica se o operador atual tem precedência sobre o que está na pilha (inicialmente sempre temos o '(' )
			//printf("Pilha vazia? %i		Operador topo Pilha = %c		Operador Expressao Infixa = %c\n", vaziap(P), topo(P), expressaoInfixa[i]);
			while( !vaziap(P) && prio(topo(P))>=prio(expressaoInfixa[i]) )
				stringAux[j++] = desempilha(P);		//stringAux recebe apenas os números, retirando da pilha P (enquanto não ficar vazia)
			empilha(expressaoInfixa[i],P);
		}

															//Caso não seja nem '(', nem números, nem operadores, sobra apenas um caractere válido...
		else if( expressaoInfixa[i] == ')' ) {					//Caso o caractere atual seja ')'...
			while( topo(P)!='(' )								//...o algoritmo procurará pelo '(' imediatamente anterior na pilha P...
				stringAux[j++] = desempilha(P);				//...desempilhando tudo da pilha P e colocando temporariamente na stringAux
			desempilha(P);									//Quando encontra o '(', ele remove da pilha
		}

		//Será executado sempre
		while( !vaziap(P) )			
			stringAux[j++] = desempilha(P);			
		stringAux[j] = '\0';
		destroip(&P);
	}
	return stringAux;
} 

int valor(char *expressaoInfixa){
	Pilha P = pilha(256);	
	for (int i = 0; expressaoInfixa[i]; ++i)
		if(isdigit(expressaoInfixa[i])) 			empilha(expressaoInfixa[i]-'0',P);		//Empilha apenas os dígitos
		else{
			//Pega os dois últimos números
			int y = desempilha(P);								
			int x = desempilha(P);	
			switch(expressaoInfixa[i]){
				case '+': empilha(x+y,P); break;
				case '-': empilha(x-y,P); break;
				case '*': empilha(x*y,P); break;
				case '/': empilha(x/y,P); break;	
			}
		}	
	int z = desempilha(P);
	destroip(&P);
	return z;
}



int main(void){
	
	char expressaoInfixa[256];		//Expressão infixa "normal"
	printf("Infixa? ");
	gets(expressaoInfixa);
	printf("Posfixa: %s\n", posfixa(expressaoInfixa));
	printf("Valor: %i\n", valor(posfixa(expressaoInfixa)));
	puts("");
	return 0;
}
