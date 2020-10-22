#include <stdio.h>

//Calcula a soma dos primeiros termos da série harmônica...
//(1+1/2+1/3+1/4+...+1/n)
//Condições: n>=1
float harmonica(int num){
	if (num==1) return 1;
	return harmonica(num-1) + 1.0/num;
}

int main(void){
	int n;
	printf("Num? ");
	scanf("%d",&n);
	printf("Harmonica = %.2f\n", harmonica(n));
	puts("");
	return 0;
}
