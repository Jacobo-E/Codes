//Tarea de POO:
//Autor: Escorcia Alcantara Gregorio Jacobo
//Fecha: 18/Agosto/2021
//Descripción: Este código imprime un saludo dependiendo de la hora. Imprime en consola buenos
//días en un horario de las 0 horas a las 11:59 horas, buenas tardes en un horario de las 12 a
//las 18:59 horas y buenas noches en un horario de 19 a 23:59 horas.

import java.util.Calendar;

public class tarea2Horario{
    public static void main(String[] args){
        Calendar calendario = Calendar.getInstance(); //obteniendo hora y fecha del dispositivo
        int hora;
        hora = calendario.get(Calendar.HOUR_OF_DAY); // asignando la hora a una variable entera
        if(hora > 0 && hora < 12){
            System.out.println("Buenos días.");
        }else if(hora >= 12 && hora < 19){
            System.out.println("Buenas tardes.");
        }else if(hora >= 19 && hora < 24){
            System.out.println("Buenas noches.");
        }else{
            System.out.println("¡ERROR! No se pudo determinar la hora del dispositivo.");
        }
    }
}

