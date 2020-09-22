#include <stdio.h>

void barras(int v[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < v[i]; j++)
            putchar(220);
        putchar('\n');
    }
}


int main(void){
    int a[3] = {9,3,7};
    int b[4] = {4,3,2,1};
    barras(a,3);
    _getch();
    barras(b,4);
    _getch();
    return 0;
}
