//Clase 11/08 de Estructuras:
//Links:
//https://www.h-schmidt.net/FloatConverter/IEEE754.html
//https://www.youtube.com/watch?v=p8u_k2LIZyo
#include <stdio.h>

int main(){

    bool r=true;
    float x = 0.31416;
    long Nx = *(long *)&x;

    long Ny = 0x5f3759df - (Nx >> 1);
    float Y = *(float *)&Ny;

    if(r)
    printf("%.10f\n", Y);

    return 0;
}
