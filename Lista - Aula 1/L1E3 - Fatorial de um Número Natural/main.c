#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,f;
    printf("Numero? ");
    scanf("%d", &n);
    f = 1;
    for (int i = 1; i <= n; i++) f *=i;
    printf("Fatorial: %d\n", f);
    _getch();
    return 0;
}
