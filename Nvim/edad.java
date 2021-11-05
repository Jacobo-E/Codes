//Tarea de POO:
//Autor: Escorcia Alcantara Gregorio Jacobo
//Fecha: 18/Agosto/2021
//Descripción: Este código imprime un saludo dependiendo de la hora. Imprime en consola buenos
//días en un horario de las 0 horas a las 11:59 horas, buenas tardes en un horario de las 12 a
//las 18:59 horas y buenas noches en un horario de 19 a 23:59 horas.

import java.util.Scanner;
import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;

public class edad{
    public static void main(String[] args){

        String fecha;
        Scanner leer = new Scanner(System.in);
        fecha = leer.nextLine();

        DateTimeFormatter fmt = DateTimeFormatter.ofPattern("ddMMyyyy");
        LocalDate fechaNac = LocalDate.parse(fecha, fmt);
        LocalDate ahora = LocalDate.now();

        Period periodo = Period.between(fechaNac, ahora);
        System.out.printf("Tu edad es %s años.", periodo.getYears());

    }
}


