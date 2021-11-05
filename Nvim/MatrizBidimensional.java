//Tarea de POO:
//Autor: Escorcia Alcantara Gregorio Jacobo
//Fecha: 29/Agosto/2021
//Descripción: Este código imprime una matriz de nxn con números que siguen un orden en específico.
//Para más detalles, ver ~/Documentos/Escuela/MatrizBidimensional.pdf
import java.util.Scanner;

public class MatrizBidimensional{
    public static void main(String[] args){

        System.out.print("Ingrese el tamaño de la matriz que desea: ");
        Scanner leer = new Scanner(System.in);
        int tamanio;
        tamanio = leer.nextInt(); //Se lee el tamaño de la matriz.
        System.out.println();

        if(tamanio != 0 && (tamanio%2)!=0){//se evalua que el tamaño de la matriz sea impar y diferente de cero.

            int A[][] = new int[tamanio][tamanio];//se crea la matriz.
            int numeros=1;//contador para llenar toda la matriz.
            int columna = ((tamanio-1)/2);//se consigue la columna central de la matriz.
            int renglon = 0;//se establece el primer renglon para el comienzo.
            int vuelta=0;//bandera para llenado de matriz.
            int contVuelta=1;//contador de cuantas veces ya se llenó la matriz con un múltiplo de la variable tamanio.

            while(numeros <= (tamanio*tamanio)){//ciclo para llenar toda la matriz.
                A[renglon][columna] = numeros;//llena la matriz.

                if(vuelta==1){//condicional que valora si el siguiente número a almacenar es número sucesor de un múltiplo de la variable tamanio.
                    renglon++;//se mueve el renglon a trabajar a la posición posterior.
                }else{
                    if((renglon-1)>=0){//condicional que evalua si el renglon a trabajar es mayor a cero.
                        renglon--;//se mueve el renglon a trabajar una posición anterior.
                    }else{
                        renglon=(tamanio-1);//se manda al renglon a trabajar a la ultima posición.
                    }

                    if((columna+1) < tamanio){//condicional que evalua si la columna a trabajar es menor al tamaño.
                        columna++;//se mueve la columna a trabajar a una posición posterior.
                    }else{
                        columna=0;//se manda a la columna a trabajar a la primer posición.
                    }
                }

                if((numeros+1)==(tamanio*contVuelta)){//condicional que valora si la matriz ya almacenó algún múltiplo de la variable tamanio.
                    vuelta=1; //bandera 
                    contVuelta++;
                }else{ 
                    vuelta=0; //bandera.
                }

                numeros++;//contador para llenar la matriz.
            }

                for(int i=0; i < tamanio; i++){//ciclo para imprimir la matriz.
                    for(int j=0; j < tamanio; j++){
                        System.out.print(A[i][j] + "\t");
                    }
                    System.out.println();
                }

        }else{//mensajes de error para validaciones.
            if (tamanio!=0 && (tamanio%2)==0) {
                System.out.println("¡ERROR! El tamaño no puede ser par.");
            }else if(tamanio==0){
                System.out.println("¡ERROR! El tamaño de la matriz no puede ser cero.");
            }
        }
    }
}
