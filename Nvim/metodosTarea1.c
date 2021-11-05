//Tarea 1 de Metodos Numericos:
//Autor: Escorcia Alcantara Gregorio Jacobo
//Fecha: 23/Agosto/2021
//Descripción: Este código hace la conversión de numeros de base 10 a base 2 o de base 2 a base 10.
#include <stdio.h>
#include <math.h>

void bits(long int x){//Función para las conversiones a base 2

    if(x < 10)
        printf("| Numero dado: %ld \t\t\t| Numero en base 2: ", x);
    else
            printf("| Numero en dado: %ld \t\t| Numero en base 2: ", x);

    for(int bits=65536; bits > 0; bits=bits/2){
        if(x & bits) //se toma la representación binaria de x y se evalua con un And a nivel bit con 
                     //el numero bits, y si de la comparacion resulta un número diferente de cero, significa
                     //que hay un bit prendido en la posición 2^n.
            printf("1");
        else 
            printf("0");
    }
    printf("|\n");

}

void baseDiez(long int x){//Función para la conversión a base 10

    printf("| Numero dado: %ld \t\t| Numero en base 10: ", x);
    int auxiliar=0, decimal=10, suma=0;
    for(int exponente=0; exponente <= 16; exponente++){
        auxiliar=0;
        auxiliar=x%decimal; //se toma el modulo de x.
        x=x/10; //se reduce a x dividiendo entre 10.
        suma=suma+(auxiliar*pow(2, exponente)); //se toma el modulo de x entre 10 y se multiplica por 2^n.
    }
    printf("%d |\n", suma);

}

int main(){

    printf("¿Que conversion desea realizar?\n");
    printf("[1] - Conversion de base 10 a base 2.\n[2] -  Conversion de base 2 a base 10.\n");

    int selec=0;
    long int num=0;
    scanf("%d", &selec);

    if(selec==1){
        printf("¿Que numero entero desea manejar? (menor a 65,536)\n");
        scanf("%ld", &num);
        if(num < 65536){
            bits(num);
        }else{
            printf("\n¡Error! El numero es mayor que 65,536.\n");
        }
    }else if (selec==2){
        printf("¿Que numero binario desea convertir? (menor de 17 digitos)\n");
        scanf("%ld", &num);
        if(num<1111111111111112){
            baseDiez(num);
        }else{
            printf("\n¡Error! El numero es mayor de 16 digitos.\n");
        }
    }

return 0;}
