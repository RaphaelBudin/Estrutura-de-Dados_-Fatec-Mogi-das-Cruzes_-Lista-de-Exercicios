#include <stdio.h>
#define DIM 5


void exibe(int  v[], int tamanhoVetor){
	for (int i = 0; i < tamanhoVetor; ++i)
		printf("%i ", v[i]); 
}

void empurra(int v[], int tamanhoVetor, int posDestino){
	/*
	1 - Guardar o valor da última posição
	2 - Descobrir posição do menor valor
	3 - Copiar o valor n+1 para posição n a partir da posição do menor valor
	4 - Na última posição colocar o menorValor
	*/

	int i = 0; //Essa variável será usada em vários momentos, vale declara-la separadamente

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
		v[i] = v[i+1];	//Transfere todos os elementos do escopo para uma posição anterior
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
