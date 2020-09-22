#include <stdio.h>
#include <stdlib.h>

typedef struct no {int item; struct no *prox;} *Lst;

Lst no (int x, Lst p){
    Lst n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

int main(void){
    Lst p = no(1,no(2,no(3,NULL)));
    while (p!= NULL) {
        printf("%d\n", p->item);
        p = p->prox;
    }
    _getch();
    return 0;
}
