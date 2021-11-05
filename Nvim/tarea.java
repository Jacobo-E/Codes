//Tarea de POO:
//Autor: Escorcia Alcantara Gregorio Jacobo
//Fecha: 16/Agosto/2021
//Descripción: Este código imprime un cuadrado de asteriscos de tamaño dado por el usuario 
//desde la consola.

//package semana1

import java.util.Scanner;

public class tarea{
    public static void main(String[] args){
        Scanner tamanio = new Scanner(System.in);
        int n=0;
        System.out.println("¡Bienvenido!");
        System.out.println("Introduzca el tamaño del cuadrado de asteriscos que desea: ");

        n=tamanio.nextInt();
        if(n>1){
            int i;
            int j;
            for(i=0; i < n; i++){
                System.out.print("*");
            }
            System.out.println();
            for(j=0; j < n-2; j++){
                System.out.print("*");
                for(i=0; i < n-2; i++){
                    System.out.print(" ");
                }
                System.out.print("*");
                System.out.println();
            }
            for(i=0; i < n; i++){
                System.out.print("*");
            }
        }else if(n==1){
            System.out.println("*");
        }else{
            System.out.println("¡ERROR! El numero introducido debe ser mayor que cero.");
        }
    }
}
