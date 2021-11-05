#include <iostream>
#include <stdlib.h>
using namespace std;

int generarNumPseudo(time_t x){
    return rand()%x;
}

int main(){

    int totalNums;
    time_t tInic, tFin, n;
    srand((unsigned) time(NULL));

    tInic=time(NULL);

    cout << "\n¿Cuántos números pseudoaleatorios quiere imprimir? " << endl;
    cin >> totalNums;

    cout << "\n¿Cuál es el número más grande que se puede generar? " << endl;
    cin >> n;

    for(int i=1; i<=totalNums; i++){
        cout << "\nNúmero Pseudoaleatorio #" << i << ": " << generarNumPseudo(n); 
    }

    tFin = time(NULL);

    cout << "\n\nTiempo de inicio de la ejecución: " << asctime(localtime(&tInic));
    cout << "Tiempo de finalización de la ejecución: " << asctime(localtime(&tFin));
    cout << "Tiempo total de ejecución: " << difftime(tFin, tInic) << " segundos." << endl;

return 0;}
