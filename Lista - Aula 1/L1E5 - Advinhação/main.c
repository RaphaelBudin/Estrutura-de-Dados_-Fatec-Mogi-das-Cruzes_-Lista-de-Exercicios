#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
	srand(time(NULL));
	int c, n = rand()%10;
    do {
        printf("Chute entre 0 e 9: ");
        scanf("%d", &c);
        if (c < n) puts("Baixo!");
        else if (c > n) puts("Alto!");
    }while(n!=c);
    puts("Acertou!");
	_getch();	
return 0;
}
