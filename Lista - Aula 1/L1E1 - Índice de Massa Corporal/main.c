/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    float p, a, i;
    printf("Peso e altura: ");
    scanf("%f %f", &p, &a);
    i = p/pow(a,2);
    printf("IMC = %.2f\n", i);
    _getch();

    return 0;
}
