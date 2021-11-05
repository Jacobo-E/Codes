package manejoFechas;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import javax.swing.JOptionPane;
import java.util.GregorianCalendar;
import java.util.Date;

public class Validacion{

    public static boolean comprobarFecha(String texto){
        try{
            Integer fechaNum = Integer.parseInt(texto);
            if(texto.length() <= 8){// Se comprueba si la longitud de la entrada es correcta
                String auxDia="", auxMes="", auxAnio="";

                for(int i=0; i <= 7; i++){//Se almacena el dia mes y año en auxiliares
                    if(i < 2){
                        auxDia = auxDia + texto.charAt(i);
                    }else if(i >= 2 && i < 4){
                        auxMes = auxMes + texto.charAt(i);
                    }else if(i >= 4 && i < 8){
                        auxAnio = auxAnio + texto.charAt(i);
                    }
                }

                //Conversion a Integers
                Integer dia=0, mes=0, anio=0;
                dia = Integer.parseInt(auxDia);
                mes = Integer.parseInt(auxMes);
                anio = Integer.parseInt(auxAnio);

                //Comprobacion de la fecha dada
                if(anio >= 0){
                    if(mes < 13 && mes > 0){//Se comprueba si el mes existe
                        if(dia < 32 && dia > 0){//Se comprueba si el dia existe
                            if(mes < 8){//Se toman los primeros siete meses
                                if((mes%2)==0){//Se toman los meses pares de los primeros siete meses, pues estos tendrán menos de de 31 dias
                                    if(dia <= 30 && mes != 2){//Se comprueba si los dias son correctos y si no es febrero el mes
                                        return true;
                                    }else if(dia <= 29 && mes == 2){//Se comprueba si el mes es febrero y si los dias son correctos, en caso de ser febrero
                                        GregorianCalendar bisiesto = new GregorianCalendar();
                                        if(!(bisiesto.isLeapYear(anio)) && dia <= 28){//Se comprueba si no es año bisiesto y si el dia es correcto, en caso de no ser año bisiesto
                                            return true;
                                        }else if(bisiesto.isLeapYear(anio) && dia <= 29){//Se comprueba si es año bisiesto y si el dia es correcto, en caso de ser año bisiesto
                                            return true;
                                        }else{//La fecha no existe
                                            return false;//La fecha no existe
                                        }
                                    }else{
                                        return false;//La fecha no existe
                                    }
                                }else{//Como ya se comprobó antes si los dias y los meses son correctos, los meses impares ya no necesitan verificación, pues el dia ingresado es <= 31
                                    return true;
                                }
                            }else if(mes >= 8){//Se toman los siguientes meses despues de julio
                                if((mes%2)==0){//Los meses pares despues de julio tienen 31 dias, y como ya se comprobaron que los dias son correctos, ya no se necesita otra verificación
                                    return true;
                                }else if((mes%2)==1 && dia <= 30){//Se evaluan los meses impares y si el dia es correcto
                                    return true;
                                }else{
                                    return false;//La fecha no existe
                                }
                            }
                        }else{
                            return false;//La fecha no existe
                        }
                    }else{
                        return false; //La fecha no existe
                    }
                }else{
                    return false; //La fecha no existe
                }
            }else{
                return false;
            }
        }catch(Exception e){
            JOptionPane.showMessageDialog(null, "¡Error en el input!");
            return false;
        }
        return false;
    }

}
