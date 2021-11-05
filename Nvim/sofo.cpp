#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n=0, linea=1, aux=0;
    n=8;
    if(n < 5){
        cout << "Ingresa un número más grande";
    }else{
        for(int j=0; j < n; j++){
            if(linea==1){
                cout << "  ";
                for(int x=0; x < n-3; x++){
                    cout << "*";
                }
                cout << " ";
                for(int x=0; x < n-3; x++){
                    cout << "*";
                }
                cout << " ";
            }else if(linea==2){
                for(int x=0; x < j; x++){
                    cout << " ";
                }
                for(int x=0; x < n+(n/2); x++){
                    cout << "*";
                }
                cout << "*";
            }else if(linea==3){
                for(int x=0; x < j; x++){
                    cout << " ";
                }
                for(int x=0; x < n+(n/2); x++){
                    cout << "*";
                }
                aux++;
            }else if(linea>3){
                for(int x=0; x < j; x++){
                    cout << " ";
                }
                for(int x=0; x < n+((n/2)-(aux+aux)); x++){
                    cout << "*";
                }
                for(int x=0; x < aux; x++){
                    cout << " ";
                }
                aux++;
            }
            cout << "\n";
            linea++;
        }
    }
    cout << "\nTe amo, Sofo";
    cout << "\n\n";
}
