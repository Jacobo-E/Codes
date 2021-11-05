// Programa para demostrar el uso del método de falsa posición.
// Autor: Escorcia Alcantara Gregorio Jacobo
// Fecha de último cambio: 06/Octubre/2021
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definiciones
#define EULER 2.71728
#define MAXITERACIONES 50
#define ERROR 0.00001

//Encabezados
int SeleccionarFuncion();
void DesplegarFunciones();
void SolicitarDatosIniciales(float* xi, float* xs, unsigned short int opcion);
void EvaluarFuncion(unsigned short int opcion, float xi, float xs, float* Fxi, float* Fxs);
float CalcularXm(float xi, float xs, float Fxi, float Fxs);
void DeterminarCaso(float* xi, float* xs, float xm, float Fxi, float Fxm);

//Función Principal
int main(){

    //Variables
    float xi = 0, xs = 0, xm = 0, xmViejo = 0;
    float errorRe = 1, errorAb = 0;
    float Fxi = 0, Fxs = 0, Fxm = 0;
    float raizAprox;
    unsigned short int opcion = 0;
    unsigned int iteracion = 0; 

    //PASO 1
    //Selección de la función
    opcion =  SeleccionarFuncion();
    do{
        SolicitarDatosIniciales(&xi, &xs, opcion);
        EvaluarFuncion(opcion, xi, xs, &Fxi, &Fxs);
    }while(!(Fxi*Fxs < 0));

    printf("\nIteración\t\txi\t\txs\t\txm\t\tError rel\tf(xi)\t\tf(xs)\t\tf(xm)\n");

    do{

        printf("%d\t\t\t%f\t%f\t", iteracion, xi, xs);

        //PASO 2
        EvaluarFuncion(opcion, xi, xs, &Fxi, &Fxs);
        xm = CalcularXm(xi, xs, Fxi, Fxs);
        printf("%f\t", xm);

        //PASO 3
        EvaluarFuncion(opcion, xi, xm, &Fxi, &Fxm);
        DeterminarCaso(&xi, &xs, xm, Fxi, Fxm);
        if(xi != xm && xs != xm){
            printf("\nRaíz encontrada x = %f\n", xm);
        }

        //PASO 4
        if(iteracion >= 1){
            errorRe = fabs(xm - xmViejo) / fabs(xm);
        }
        printf("%f\t%f\t%f\t%f\n", errorRe, Fxi, Fxs, Fxm);

        xmViejo = xm;
        iteracion++;

    }while(errorRe > ERROR || (iteracion == 1 || iteracion > MAXITERACIONES));

    if(errorRe < ERROR){
        printf("\nSe encontró la raíz xm = %f\n", xm);
    }else{
        printf("\nSe alcanzó el maximo número de iteraciones sin encotrar la raíz con el error tolerado.\n");
    }

return 0;}

int SeleccionarFuncion(){

    //Variables
    unsigned short int opcion;
    char c;

    DesplegarFunciones();

    while(!(scanf("%hu%c", &opcion, &c) == 2 && c == '\n') || (opcion < 1 || opcion > 4)){
        printf("Ingrese una opción valida.\n");
        fflush(stdin);
    }
    return opcion;
}

void DesplegarFunciones(){
    printf("Selecciona la función a evaluar: ");
    printf("\n[1] x^3 - x - 1");
    printf("\n[2] -2x^3 - 4x^2 + 4x + 4");
    printf("\n[3] x - 2^-x");
    printf("\n[4] e^x + 2^-x + 2 cos(x) -6\n");
}

void SolicitarDatosIniciales(float* xi, float* xs, unsigned short int opcion){

    char c;
    printf("Introduzca el valor de xi y xs: ");

    if(opcion == 1 || opcion == 2){
        while(!(scanf("%f%f%c", xi, xs, &c) == 3 && c == '\n') || (xi > xs)){
            printf("Ingrese valores validos.\n");
            fflush(stdin);
        }
    }else{
        switch(opcion){
            case 3:
                *xi = 0;
                *xs = 1;
                break;
            case 4:
                *xi = 1;
                *xs = 2;
                break;
        }
    }

}

void EvaluarFuncion(unsigned short int opcion, float xi, float xs, float* Fxi, float* Fxs){

    switch(opcion){
        case 1:
            *Fxi = ((pow(xi, 3)) - xi -1);
            *Fxs = ((pow(xs, 3)) - xs -1);
            break;
        case 2:
            *Fxi = (-2*(pow(xi, 3)))+ (-4*(xi*xi)) + 4*xi +4;
            *Fxs = (-2*(pow(xs, 3)))+ (-4*(xs*xs)) + 4*xs +4;
            break;
        case 3:
            *Fxi = xi - pow(2, -xi);
            *Fxs = xs - pow(2, -xs);
            break;
        case 4:
            *Fxi = exp(xi) + pow(2, -xi) + (2*cos(xi)) - 6;
            *Fxs = exp(xs) + pow(2, -xs) + (2*cos(xs)) - 6;
            break;
        default:
            printf("\nError en el programa...\n");
            exit(2);
            break;
    }

}

float CalcularXm(float xi, float xs, float Fxi, float Fxs){

    return (xs - ((Fxs*(xs-xi))/(Fxs-Fxi)));

}

void DeterminarCaso(float* xi, float* xs, float xm, float Fxi, float Fxm){
    float producto = Fxi * Fxm;
    //printf("\nPRODUCTO Fxi*Fxm = %f\n", producto);

    int caso = 0;

    if(producto < 0){
        caso = 1;
    }else if(producto > 0){
        caso = 2;
    }

    switch(caso){
        case 1: *xs = xm;
                //printf("\nCASO 1\n");
            break;
        case 2: *xi = xm;
                //printf("\nCASO 2\n");
            break;
        default:
            break;
    }

}
