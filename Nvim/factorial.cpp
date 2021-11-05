#include <iostream>
#include <stdlib.h>
using namespace std;

int factorial(int n){
    return (n>1? n*factorial(n-1) : 1);
}

int main(){

    int x;
    cout << "Introduce un entero" << endl;
    cin >> x;
    cout << "El factorial de " << x << " es " << factorial(x) << endl;
    cin.get();

}
