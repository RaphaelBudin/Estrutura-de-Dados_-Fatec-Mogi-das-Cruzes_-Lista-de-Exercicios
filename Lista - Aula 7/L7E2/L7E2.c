#include <stdio.h>
#define DIM 5


void exibe(int  v[], int tamanhoVetor){
	for (int i = 0; i < tamanhoVetor; ++i)
		printf("%i ", v[i]); 
}

void empurra(int v[], int tamanhoVetor, int posDestino){
	/*
	1 - Guardar o valor da �ltima posi��o
	2 - Descobrir posi��o do menor valor
	3 - Copiar o valor n+1 para posi��o n a partir da posi��o do menor valor
	4 - Na �ltima posi��o colocar o menorValor
	*/

	int i = 0; //Essa vari�vel ser� usada em v�rios momentos, vale declara-la separadamente

	//PASSO - 1
	int valorUltimaPosicao = v[tamanhoVetor-1];

	//PASSO - 2
	int menorElemento = 999, posMenorElemento = 999; 
	for (i = 0; i < tamanhoVetor; ++i){
		if (v[i] < menorElemento){
			menorElemento = v[i];
			posMenorElemento = i;
		}
	}

	//PASSO 3
	for (i = posMenorElemento; i < posDestino; ++i){
		v[i] = v[i+1];	//Transfere todos os elementos do escopo para uma posi��o anterior
	}

	//PASSO 4
	v[i] = menorElemento;
}

int main(void){
	int v[DIM] = {48,19,31, 52,27};
	empurra(v,DIM,4);
	exibe(v,DIM);
	puts("");
	return 0;

}
