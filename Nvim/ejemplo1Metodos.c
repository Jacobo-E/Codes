//Programa para determinar si un número es primo o no.
//Autor: Grupo 1352 MAC
//Fecha: 07/Septiembre/2021
#include <stdio.h>
#include <stdlib.h>

int LeerNumero();

int main(){

    int n=0;

    n = LeerNumero();

return 0;}
int LeerNumero(){

    int n = 0;
    char c;

    printf("Introduzca un número entero positivo.\n");

    while((scanf("%d%c", &n, &c) != 2 || c !='\n' || n<1)){
            printf("\nEl número debe ser entero positivo. Favor de verificar.\n");
            printf("Introduzca un número entero positivo: ");
        }

    return n;

}
