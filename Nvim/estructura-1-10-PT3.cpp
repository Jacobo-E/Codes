#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct nodoTres{

    int ni;
    float nf;
    char nC;

}nodT;

int main(){

    nodT *q1 = new nodT;
    nodT *q2 = new nodT;

    q1->ni=10;
    q1->nf=3.5;
    q1->nC='A';

    q2->ni=20;
    q2->nf=4.6;
    q2->nC='B';

    cout << "[ " << q1->ni << " | " << q1->nf << " | " << q1->nC << " ]" << endl;
    cout << "[ " << q2->ni << " | " << q2->nf << " | " << q2->nC << " ]" << endl;

    delete(q1);
    delete(q2);

return 0;}
