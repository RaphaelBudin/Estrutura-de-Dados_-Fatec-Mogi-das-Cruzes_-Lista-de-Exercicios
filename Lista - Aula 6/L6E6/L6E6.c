#include <stdio.h>

void contagemRegressiva(int n){
	if (n<0) return;
	//Essa parte da função funciona de forma contrária ao exercício anterior
	//No exercício anterior, a função recursiva era chamada antes da exibição
	//Isso resulta que os números eram exibidos na ordem crescente, do mais velho para o mais novo
	
	//Ao exibir o número antes de chamar a função recursiva, se obtém o efeito de contagem regressiva
	printf("%d\n", n);
	contagemRegressiva(n-1);	
}

int main(void){
	int n;
	printf("Num? ");
	scanf("%d", &n);
	contagemRegressiva(n);
	puts("");
	return 0;
}
