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
		case '(': return 0; //Preced�ncia baixa
		case '+':
		case '-': return 1; //Preced�ncia m�dia
		case '*':
		case '/': return 2;	//Preced�ncia alta
}
return -1; // operador inv�lido!
}

char *posfixa(char *expressaoInfixa) {
	static char stringAux[256];		//String Aux - Serve para:
									// 1 - Guardar todos os n�meros (sem operadores)
	int j = 0;			
	Pilha P = pilha(256);			//pilha P - Serve para:
									//1 - Guardar os operadores
									//2 - Guardar os n�meros entre parentesis

	for(int i=0; expressaoInfixa[i]; i++){							//At� o for achar o '\0' dentro da string
		//printf("ExpressaoInfixa[i] = %c\n",expressaoInfixa[i]);
		if( expressaoInfixa[i]=='(' ){ 								//Se for '('...
			empilha('(',P);										//Empilha o '(' na pilha P
		} 							
		else if( isdigit(expressaoInfixa[i]) ){ 						//Se for um n�mero...
			stringAux[j++] = expressaoInfixa[i];					//stringAux recebe apenas os n�meros
		}
		else if( strchr("+-/*",expressaoInfixa[i]) ) {			//Caso n�o seja '(' nem um n�mero, verifica se � um dos operadores b�sicos

			//Se for...
			//Depois verifica a ordem de prioridade das opera��es
			//Se for um operador b�sico...
			//... verifica se o operador atual tem preced�ncia sobre o que est� na pilha (inicialmente sempre temos o '(' )
			//printf("Pilha vazia? %i		Operador topo Pilha = %c		Operador Expressao Infixa = %c\n", vaziap(P), topo(P), expressaoInfixa[i]);
			while( !vaziap(P) && prio(topo(P))>=prio(expressaoInfixa[i]) )
				stringAux[j++] = desempilha(P);		//stringAux recebe apenas os n�meros, retirando da pilha P (enquanto n�o ficar vazia)
			empilha(expressaoInfixa[i],P);
		}

															//Caso n�o seja nem '(', nem n�meros, nem operadores, sobra apenas um caractere v�lido...
		else if( expressaoInfixa[i] == ')' ) {					//Caso o caractere atual seja ')'...
			while( topo(P)!='(' )								//...o algoritmo procurar� pelo '(' imediatamente anterior na pilha P...
				stringAux[j++] = desempilha(P);				//...desempilhando tudo da pilha P e colocando temporariamente na stringAux
			desempilha(P);									//Quando encontra o '(', ele remove da pilha
		}

		//Ser� executado sempre
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
		if(isdigit(expressaoInfixa[i])) 			empilha(expressaoInfixa[i]-'0',P);		//Empilha apenas os d�gitos
		else{
			//Pega os dois �ltimos n�meros
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
	
	char expressaoInfixa[256];		//Express�o infixa "normal"
	printf("Infixa? ");
	gets(expressaoInfixa);
	printf("Posfixa: %s\n", posfixa(expressaoInfixa));
	printf("Valor: %i\n", valor(posfixa(expressaoInfixa)));
	puts("");
	return 0;
}
