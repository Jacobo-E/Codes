#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

    float* q1;
    float* q2;
    float* aux;

    q1 = new float;
    *q1 = 9.5;

    q2 = new float;
    *q2 = 20.0;

    aux = new float;

    cout << "*q1 = " << *q1 << "; *q2 = " << *q2 << endl;

    *aux = *q1;
    *q1 = *q2;
    *q2 = *aux;

    cout << "*q1 = " << *q1 << "; *q2 = " << *q2 << endl;

    delete q1;
    delete q2;
    delete aux;

return 0;}
