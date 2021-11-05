#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct nodo{
    int dat;
    nodo *pt;
}nod;

nod *tope = NULL;

void insertaPila(int nuevoDato){
    nod *nuevo = NULL;
    nuevo = (nod *) malloc(sizeof(nod));
    nuevo->dat = nuevoDato;

    if(tope==NULL){
        nuevo->pt = NULL;
    }else{
        nuevo->pt = tope;


    }

    tope = nuevo;
}

int main(){

    

return 0;}
