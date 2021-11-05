//Tarea de Métodos Numéricos:
//Autor: Escorcia Alcantara Gregorio Jacobo
//Fecha: 30/Agosto/2021
//Descripción: Este código realiza la sumatoria de 1/k^2 para k=1, 2, ..., 100 y para k=100, 99, ..., 1.
#include <stdio.h>
#include <math.h>

int main(){

    float suma=0;
    for(float i = 1; i <= 100; i++){
        suma = suma + 1/(i*i);
    }

    printf("El resultado de la suma en orden ascendente es: %f\n", suma);

    suma=0;
    for(float i = 100; i > 0; i--){
        suma = suma + 1/(i*i);
    }

    printf("El resultado de la suma en orden descendente es: %f\n", suma);

return 0;}
