#include <stdio.h>

//Traduz e exibe um número natural em binário
void binario(int n){
	if (n<2) printf("%d",n); //Se for menor que 2, não há como dividr por 2, e portanto o próprio número é o primeiro dígito e deve ser exibido
	else{
		binario(n/2);
		printf("%d", n%2); //Exibir depois de chamar a função para garantir que o que for chamado primeiro, será exibido por último
	}
}

int main(void){
	int num;
	printf("Num? ");
	scanf("%d", &num);
	binario(num);
	puts("");
	return 0;	
}
