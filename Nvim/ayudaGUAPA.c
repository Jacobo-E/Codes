#include <stdio.h>

int main(){
    float n=0;
    float m=0;
    float diferencia=0;
    float suma=0;
    printf("Ingrese el intervalo de n a m separado por un espacio: ");
    scanf("%f%f", &n, &m);

    if(n < m){
        diferencia = m-n;
        for(int aux = m; n <= m; aux++){
            suma = suma + (n+diferencia);
        }
    }else{
        printf("\nN es mayor que M. Ingrese un intervalo válido.\n");
    }
return 0;}
