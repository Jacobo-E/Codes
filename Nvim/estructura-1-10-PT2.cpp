#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct nodos{

    int ni;
    float nf;

}nodU;

typedef struct nodos2{

    float nf;
    char nC;

}nodD;

int main(){

    nodU *rt1 = new nodU;

    rt1->ni = 10;
    rt1->nf = 3.5;

    cout << "[ " << rt1->ni << " | " << rt1->nf << " ]" << endl;

    nodD *pt = new nodD;

    pt->nf = 3.5;
    pt->nC = 'A';

    cout << "[ " << pt->nf << " | " << pt->nC << " ]" << endl;

    delete(rt1);
    delete(pt);

return 0;}

