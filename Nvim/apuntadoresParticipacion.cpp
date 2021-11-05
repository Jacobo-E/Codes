#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct nodo{
    char dato;
    nodo *pt;
}nodU;

typedef struct nodoDos{
    float dat2;
    nodoDos *pt2;
}nodD;

typedef struct nodoTres{
    nodU *s1;
    nodD *s2;
}nodT;

int main(){

    nodT *pt;
    pt = (nodT *) malloc(sizeof(nodT));

    pt->s1 = (nodU *) malloc(sizeof(nodU));
    pt->s1->dato = 'A';
    pt->s1->pt = (nodU *) malloc(sizeof(nodU));
    pt->s1->pt->dato = 'B';
    pt->s1->pt->pt = (nodU *) malloc(sizeof(nodU));
    pt->s1->pt->pt->dato = 'C';
    pt->s1->pt->pt->pt = NULL;

    pt->s2 = (nodD *) malloc(sizeof(nodD));
    pt->s2->dat2 = 9.8;
    pt->s2->pt2 = NULL;

    cout << "pt -> s1 -> [ " << pt->s1->dato <<" | [ " << pt->s1->pt->dato <<" | [ " << pt->s1->pt->pt->dato << " | NULL ] ] ]" << endl;
    cout << "pt -> s2 -> [ " << pt->s2->dat2 << " | NULL ]" << endl;

    free(pt->s1->pt->pt);
    free(pt->s1->pt);
    free(pt->s1);
    free(pt->s2);
    free(pt);

}
