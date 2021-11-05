// Programa para demostrar el uso del método de Newton
// Autor: Escorcia Alcantara Gregorio Jacobo
// Fecha de último cambio: 06/Octubre/2021
#include <stdio.h>
#include <math.h>

//Definiciones
#define MAXITERACIONES 50
#define ERROR 0.001

//Encabezados
unsigned short int SeleccionarFuncion();
void DesplegarFunciones();
void EvaluarConDerivada(unsigned short int opcion, float xN, float *FxN);
void EvaluarConFuncion(unsigned short int opcion, float xN, float *FxN);
void XnInicial(float* xN);
void CalcularXm(float xN, float FxN, float DFxN, float* xNmasUno);

int main(){

    //Variables
    float xN = 0, xNmasUno = 0, FxN = 0, DFxN = 0, errorRe = 1, errorAbs=1;
    int iteracion = 0;
    unsigned short int opcion = 0;

    opcion = SeleccionarFuncion();

    //Paso 2
    do{
        XnInicial(&xN);
        EvaluarConFuncion(opcion, xN, &FxN);
        printf("xN = %f, FxN = %f", xN, FxN);
    }while(FxN > 20 || FxN < -20);

    printf("\nIteración\t\txi\t\tf(xi)\t\tf'(xi)\t\tError rel\tError abs\n");

    do{

        //Paso 3
        EvaluarConFuncion(opcion, xN, &FxN);
        EvaluarConDerivada(opcion, xN, &DFxN);
        CalcularXm(xN, FxN, DFxN, &xNmasUno);

        //Paso 4
        if(iteracion >= 1){
            errorRe = fabs(xNmasUno - xN)/fabs(DFxN);
            errorAbs = fabs(xNmasUno - xN);
        }

        xN = xNmasUno;

        printf("%d\t\t\t%f\t%f\t%f\t%f\t%f\n", iteracion+1, xN, FxN, DFxN, errorRe, errorAbs);

        iteracion++;

    }while((errorAbs > ERROR && iteracion <= MAXITERACIONES)||(errorAbs > ERROR && iteracion <= MAXITERACIONES));

    if(errorAbs < ERROR && iteracion < MAXITERACIONES){
        printf("\n\nSe encontró la raíz xi = %f\n", xNmasUno);
    }else if(errorAbs > ERROR && iteracion < MAXITERACIONES){
        printf("\n\nHubo un error en el sistema");
    }else if(iteracion > MAXITERACIONES){
        printf("\n\nSe alcanzó el maximo número de iteraciones sin encotrar la raíz con el error tolerado.\n");
    }else{
        printf("\n\nHubo un error en el sistema.\n");
    }

return 0;}

unsigned short int SeleccionarFuncion(){

    //Variables
    unsigned short int opcion;
    char c;

    DesplegarFunciones();

    while(!(scanf("%hu%c", &opcion, &c) == 2 && c == '\n') || (opcion < 1 || opcion > 8)){
        printf("Ingrese una opción valida.\n");
        fflush(stdin);
    }
    return opcion;

}

void DesplegarFunciones(){
    printf("Selecciona la función a evaluar: ");
    printf("\n[1] x^3");
    printf("\n[2] x^2 + 2");
    printf("\n[3] sen(x)");
    printf("\n[4] e^-x - x");
    printf("\n[5] x^10 - 1");
    printf("\n[6] (2x)^-x + (x^2 * e^x)\n");
}

void XnInicial(float* xN){

    char c;

    printf("\nIngrese un valor x cercano a la raíz: ");
    while(!(scanf("%f%c", xN, &c) == 2 && c == '\n')){
        printf("Ingrese valores validos.\n");
        fflush(stdin);
    }

}

void EvaluarConDerivada(unsigned short int opcion, float xN, float *DFxN){

    switch(opcion){
        case 1:
            *DFxN = 3*(pow(xN, 2));
            break;
        case 2:
            *DFxN = 2*xN;
            break;
        case 3:
            *DFxN = cos(xN);
            break;
        case 4:
            *DFxN = (-1+exp(xN))/exp(xN);
            break;
        case 5:
            *DFxN = 10*(pow(xN, 9));
            break;
        case 6:
            *DFxN = (log(2)*pow(2, -xN)*(-1*pow(xN, -xN))) + (pow(2, -xN)*exp((log(xN)*-xN))*(((1/xN)*(-xN))+log(xN)*-1))+((2*xN)*exp(xN)+pow(xN, 2)*exp(xN));
            break;
        case 7:
            *DFxN = -(1+2*xN)/(pow((xN+(xN*xN)), 2));
            break;
        default:
            printf("\nError en el programa...\n");
    }

}

void EvaluarConFuncion(unsigned short int opcion, float xN, float* FxN){

    switch(opcion){
        case 1:
            *FxN = pow(xN, 3);
            break;
        case 2:
            *FxN = pow(xN, 2) + 2;
            break;
        case 3:
            *FxN = sin(xN);
            break;
        case 4:
            *FxN = exp(-xN) - xN;
            break;
        case 5:
            *FxN = pow(xN, 10) - 1;
            break;
        case 6:
            *FxN = pow((2*xN), -xN) + ((xN*xN)*exp(xN));
            break;
        case 7:
            *FxN = pow((1+xN), 9)/(xN*(pow((1+xN), 10)));
            break;
        default:
            printf("\nError en el programa...\n");
    }

}

void CalcularXm(float xN, float FxN, float DFxN, float* xNmasUno){

    *xNmasUno = xN - (FxN/(DFxN));

}
