#include <stdio.h>

//Exibe contagem progressiva de 1 até n>= 0
void contagemProgressiva(int n){
	if (n<0) return;
	contagemProgressiva(n-1); //O valor de n de cada iteração será guardado na pilha virtual, de forma que o primeiro valor passado seja o último a ser exibido, e o último valor antes de n<0 seja o primeiro
	printf("%d\n", n);
}

int main(void){
	int n;
	printf("Num ? ");
	scanf("%d", &n);
	contagemProgressiva(n);
	return 0;	
}
