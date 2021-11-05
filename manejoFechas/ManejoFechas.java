package manejoFechas;

import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;
import javax.swing.JOptionPane;

public class ManejoFechas{

    public static void main(String[] args){

        SimpleDateFormat fecha = new SimpleDateFormat("dd/MM/yyyy");
        String auxiliar="", auxDia="", auxMes="", auxAnio="", stringFechaUno="", stringFechaDos="";
        int llave=0;

        do{
            auxiliar = JOptionPane.showInputDialog("Ingrese primera fecha");

            if(Validacion.comprobarFecha(auxiliar)){
                llave=1;
            }else{
                llave=0;
            }

        }while(llave==0);

        String auxiliarDos="";

        for(int i=0; i <= 7; i++){//Se almacena el dia mes y año en auxiliares
            if(i < 2){
                auxDia = auxDia + auxiliar.charAt(i);
            }else if(i >= 2 && i < 4){
                auxMes = auxMes + auxiliar.charAt(i);
            }else if(i >= 4 && i < 8){
                auxAnio = auxAnio + auxiliar.charAt(i);
            }
        }
        stringFechaUno=auxDia+"/"+auxMes+"/"+auxAnio;

        Date fechaUno = new Date(Integer.parseInt(auxAnio), Integer.parseInt(auxMes), Integer.parseInt(auxDia));

        auxiliar="";
        do{
            auxiliar = JOptionPane.showInputDialog("Ingrese segunda fecha");

            if(Validacion.comprobarFecha(auxiliar)){
                llave=1;
            }else{
                llave=0;
            }

        }while(llave==0);

        auxiliarDos="";
        auxDia="";
        auxMes="";
        auxAnio="";

        for(int i=0; i <= 7; i++){//Se almacena el dia mes y año en auxiliares
            if(i < 2){
                auxDia = auxDia + auxiliar.charAt(i);
            }else if(i >= 2 && i < 4){
                auxMes = auxMes + auxiliar.charAt(i);
            }else if(i >= 4 && i < 8){
                auxAnio = auxAnio + auxiliar.charAt(i);
            }
        }
        stringFechaDos=auxDia+"/"+auxMes+"/"+auxAnio;

        Date fechaDos = new Date(Integer.parseInt(auxAnio), Integer.parseInt(auxMes), Integer.parseInt(auxDia));

        if(fechaUno.after(fechaDos)){
            JOptionPane.showMessageDialog(null, stringFechaDos);
        }else if(fechaDos.after(fechaUno)){
            JOptionPane.showMessageDialog(null, stringFechaUno);
        }else if(fechaDos.equals(fechaUno)){
            JOptionPane.showMessageDialog(null, "Las fechas son iguales");
        }else{
            JOptionPane.showMessageDialog(null, "Error en el sistema :(");
        }
 
    }
}
