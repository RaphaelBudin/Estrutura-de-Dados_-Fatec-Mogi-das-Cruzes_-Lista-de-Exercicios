#include <stdio.h>

void troca(int x, int y) {
    int z = x;
    x = y;
    y = z;
}


int main(void){
    int a=5, b=8;
    troca(a,b);
    printf("a=%d, b=%d\n",a,b);
    _getch();
    return 0;
}
