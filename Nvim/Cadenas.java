//Tarea de POO:
//Autor: Escorcia Alcantara Gregorio Jacobo
//Fecha: 03/Septiembre/2021
//Descripción: Este código muestra una ventana en pantalla con JoptionPane donde se pide una cadena
//y despúes muestra la primer palabra concatenada consigo misma, pero al revés, sin duplicar la 
//ultima letra.
import javax.swing.JOptionPane;

public class Cadenas{
    public static void main(String[] args){

        String cadena="";//se crea una variable tipo String.
        cadena=JOptionPane.showInputDialog("Ingrese una cadena.");//Se despliega en pantalla la ventana y se pide la cadena.
        String[] newCadena= cadena.split("\\s+");//Se dividen las palabras separadas por espacios en un array de tipo String.
        String palabra = newCadena[0];//Se toma la primer palabra separada por espacio.

        String invertida="";//se crea una variable para la palabra invertida.
        for(int i = palabra.length() - 2; i>=0; i--){
            invertida += palabra.charAt(i);//Creamos la palabra invertida recorriendo con un ciclo desde la penúltima posición hasta la primer posición.
        }

        JOptionPane.showMessageDialog(null, (palabra+invertida/*se concatenan las palabras*/).toUpperCase()/*Se convierten las cadenas a mayúsculas*/);//Se muestra el resultado en una ventana.
    }
}
