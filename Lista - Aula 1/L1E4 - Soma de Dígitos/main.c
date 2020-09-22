#include <stdio.h>

int main(void){
	int n;
	printf("Numero? ");
	scanf("%d", &n);
	int s = 0;
	while (n>0) {
		s += n%10;
		n /=10;
	}
	printf("Soma dos digitos = %d\n", s);
	_getch();	
return 0;
}
