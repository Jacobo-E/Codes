#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//variables globales
int **matriz;
int ***submatriz;

//Declaración de funciones
int PedirTamanio();
void CrearMatriz(int n);
void IngresarDatos(int n);
void LiberarMemoria(int n);
void CrearSubMatriz(int orden);
int DeterminanteMat(int SubOrden, int ordenOriginal);
int Cofactor(int orden, int fila, int columna);

int main(){

    //variables
    int **matriz;
    int n = 0;
    n = PedirTamanio();
    CrearMatriz(n);
    IngresarDatos(n);
    CrearSubMatriz(n);
    DeterminanteMat(n-1, n);
    LiberarMemoria(n);

return 0;}

int PedirTamanio(){
    //variables
    int n=0;

    printf("\nIngrese el tamaño de renglones y columnas para el determinante a crear: ");
    scanf("%d", &n);

return n;}

void CrearMatriz(int n){
    //creacion de matriz
    matriz = (int **)calloc(n, sizeof(int));
    for(int i=0; i < n; i++){
        matriz[i] = (int *)calloc(n, sizeof(int));
    }

    //comprobacion
    if(matriz == NULL){
        printf("\nError al reservar memoria.\n");
        return;
    }
    for(int i=0; i < n; i++){
        if(matriz[i] == NULL){
            printf("\nError al reservar memoria.\n");
            return;
        }
    }

return;}

void CrearSubMatriz(int orden){
    submatriz = (int ***)calloc(orden, sizeof(int));
    int x=0;
    int y=0;
    for(int i=orden; i > 0; i--){
        submatriz[x] = (int **)calloc(i, sizeof(int));
        for(int j=orden; j > 0; j--){
            submatriz[x][y] = (int *)calloc(j, sizeof(int));
            y++;
        }
        x++;
    }

    for(int i=0; i < orden; i++){
        for(int j=0; j < orden; j++){
            submatriz[0][i][j] = matriz[i][j];
        }
    }

    if(submatriz == NULL){
        printf("\nError al reservar memoria.\n");
        return;
    }
    for(int i=0; i < orden-1; i++){
        if(submatriz[i]==NULL){
            printf("\nError al reservar memoria.\n");
            return;
        }
        for(int j=0; j<orden-1; j++){
            if(submatriz[i][j] == NULL){
                printf("\nError al reservar memoria.\n");
                return;
            }
        }
    }
}

void IngresarDatos(int n){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            printf("\n[%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void LiberarMemoria(int n){
    for(int i=0; i < n; i++){
        free(matriz[i]);
        for(int j=0; j < n; j++){
            free(submatriz[i][j]);
        }
        free(submatriz[i]);
    }
    free(matriz);
    free(submatriz);
return;}

int DeterminanteMat(int SubOrden, int ordenOriginal){
    int det=0;
    if(SubOrden == 1){
        det = submatriz[ordenOriginal-1][ordenOriginal-1][ordenOriginal-1];
    }else{
        for(int i=0; i <= SubOrden; i++){
            det = det + submatriz[1][1][i] * Cofactor(SubOrden, 0, i);
        }
    }
    return det;
}

int Cofactor(int orden, int fila, int columna){
    //auxiliares y variables
    int x=0;//fila submatriz
    int y=0;//columna submatriz
    int z=0;//numero submatriz
    int auxX=0;
    int auxY=0;
    int SubOrden = orden-1;

    for(int i=1; i < SubOrden+1; i++){//numero submatriz
        x=SubOrden-z;
        y=SubOrden-z;
        for(int j=0; j < x; j++){//fila submatriz
            for(int k=0; k < y; k++){//columna submatriz
                if(fila!=j && columna!=k){
                    submatriz[i][auxX][auxY] = submatriz[1][j][k];
                    auxY++;
                    if(auxY >= SubOrden){
                        auxX++;
                        auxY=0;
                    }
                }
            }
        }
        z++;
    }

    return pow(-1, (fila+1)+(columna+1))*DeterminanteMat(SubOrden, orden);
}
