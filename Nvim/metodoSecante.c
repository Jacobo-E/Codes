// Programa para demostrar el uso del método de la secante
// Autor: Escorcia Alcantara Gregorio Jacobo
// Fecha de último cambio: 06/Octubre/2021
#include <stdio.h>
#include <math.h>

//Definiciones
#define MAXITERACIONES 50
#define ERROR 0.0001

//Encabezados
unsigned short int SeleccionarFuncion();
void DesplegarFunciones();
void EvaluarConFuncion(unsigned short int opcion, float xNmenosUno, float xN, float *FxNmenosUno, float *FxN);
void XnInicial(float* xNmenosUno, float* xN);
void CalcularXm(float xNmenosUno, float xN, float FxNmenosUno, float FxN, float* xNmasUno);

int main(){

    //Variables
    float xNmenosUno = 0, xN = 0, xNmasUno = 0, FxNmenosUno = 0, FxN = 0, errorRe = 1, errorAbs=1;
    int iteracion = 0;
    unsigned short int opcion = 0;

    opcion = SeleccionarFuncion();

    //Paso 1
    XnInicial(&xNmenosUno, &xN);

    printf("\nIteración\t\txn-1\t\txn\t\txn+1\t\tf(xn-1)\t\tf(xn)\t\tError rel\tError abs\n");

    do{

        //Paso 2
        EvaluarConFuncion(opcion, xNmenosUno, xN, &FxNmenosUno, &FxN);
        CalcularXm(xNmenosUno, xN, FxNmenosUno, FxN, &xNmasUno);

        if(iteracion >= 1){
            errorRe = fabs(xNmasUno - xN)/fabs(xNmasUno);
            errorAbs = fabs(xNmasUno - xN);
        }

        printf("%d\t\t\t", iteracion+1);
        printf("%f\t%f\t%f\t", xNmenosUno, xN, xNmasUno);
        printf("%f\t%f\t", FxNmenosUno, FxN);
        printf("%f\t", errorRe);
        printf("%f\n", errorAbs);

        iteracion++;
        xNmenosUno = xN;
        xN = xNmasUno;

    }while((errorRe > ERROR && iteracion <= MAXITERACIONES) && (errorAbs > ERROR && iteracion <= MAXITERACIONES));

    if(errorRe < ERROR && iteracion < MAXITERACIONES){
        printf("\n\nSe encontró la raíz xNmasUno = %f\n", xNmasUno);
    }else if(errorRe > ERROR && iteracion < MAXITERACIONES){
        printf("\n\nHubo un error en el sistema.\n");
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

    while(!(scanf("%hu%c", &opcion, &c) == 2 && c == '\n') || (opcion < 1 || opcion > 6)){
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
    printf("\n[4] e^x + 2^-x + 2cos(x) - 6");
    printf("\n[5] -x + 2^-x + e^x\n");
    printf("[6] 5\n");
}

void XnInicial(float* xNmenosUno, float* xN){

    char c;

    printf("\nIngrese un el valor de xN y xNmasUno: ");
    while(!(scanf("%f%f%c", xNmenosUno, xN, &c) == 3 && c == '\n')){
        printf("Ingrese valores validos.\n");
        fflush(stdin);
    }

}

void EvaluarConFuncion(unsigned short int opcion, float xNmenosUno, float xN, float *FxNmenosUno, float *FxN){

    switch(opcion){
        case 1:
            *FxN = (pow(xN, 3))-xN-1;
            *FxNmenosUno = (pow(xNmenosUno, 3))-xNmenosUno-1;
            break;
        case 2:
            *FxN = (-2*pow(xN, 3))-(4*(xN*xN))+4*xN+4;
            *FxNmenosUno = (-2*pow(xNmenosUno, 3))-(4*(xNmenosUno*xNmenosUno))+4*xNmenosUno+4;
            break;
        case 3:
            *FxN = xN-pow(2, -xN);
            *FxNmenosUno = xNmenosUno-pow(2, -xNmenosUno);
            break;
        case 4:
            *FxN = exp(xN) + pow(2, -xN) + 2*cos(xN) -6;
            *FxNmenosUno = exp(xNmenosUno) + pow(2, -xNmenosUno) + 2*cos(xNmenosUno) -6;
            break;
        case 5:
            *FxN = -xN + (pow(2, -xN)) + exp(xN);
            *FxNmenosUno = -xNmenosUno + (pow(2, -xNmenosUno)) + exp(xNmenosUno);
            break;
        case 6:
            *FxN = 5;
            *FxNmenosUno = 5;
            break;
        default:
            printf("\nError en el programa...\n");
    }

}

void CalcularXm(float xNmenosUno, float xN, float FxNmenosUno, float FxN, float* xNmasUno){

    *xNmasUno = xN-((FxN*(xN-xNmenosUno))/(FxN-FxNmenosUno));

}
