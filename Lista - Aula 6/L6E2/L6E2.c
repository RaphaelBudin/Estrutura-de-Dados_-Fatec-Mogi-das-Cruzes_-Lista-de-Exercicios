#include <stdio.h>

//Essa função faz a mesma coisa de um for que multiplica o número por ele mesmo n vezes, porém com recusão
float potenciacao(float numero, int nVezes){
	if (nVezes == 0) return 1;	//Bateu aqui, quer dizer que já executou o número determinado de vezes que deveria
	return numero*potenciacao(numero, nVezes-1);	
}

int main(void){
	float base;
	int expoente;
	printf("Base e expoente? ");
	scanf("%f %d",&base, &expoente);
	printf("Pot = %.1f\n", potenciacao(base, expoente));
	puts("");
	return 0;	
}
