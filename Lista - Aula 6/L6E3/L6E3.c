#include <stdio.h>

//Calcula a soma dos 'n' primeiros números naturais
int termial(int n){
	if (n == 0) return 0;
	return termial(n-1) + n;	
}

int main(void){
	int n;
	printf("Num? ");
	scanf("%d", &n);
	printf("Termial = %d\n", termial(n));
	
	puts("");
	return 0;	
}
