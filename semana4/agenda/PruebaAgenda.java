package semana4.agenda;

import javax.swing.JOptionPane;

public class PruebaAgenda{
    public static void main(String[] args){
        //Administrar Agenda
        Agenda nueva = new Agenda();
        int pos=0;

        //Asigna un dueño;
        nueva.setDuenio(new Persona());
        nueva.getDuenio().setNombre("Jacobobo de Misato");
        nueva.getDuenio().setEdad(41);

        //Agregar contacto 1
        Persona pTmp = new Persona("Juan", "Perez", "Palma");
        nueva.agregarContactos(pTmp);

        //Agregar contacto 2
        pTmp = new Persona("Sofo", "Trinidad");
        nueva.agregarContactos(pTmp);

        //Agregar contacto 3
        pTmp = new Persona("Gaboooo");
        nueva.agregarContactos(pTmp);

        //Agregar contacto 4
        pTmp = new Persona("YO");
        nueva.agregarContactos(pTmp);

        JOptionPane.showMessageDialog(null, "El total de contactos es: "+nueva.obtenerTotalContactos());

        nueva.mostrarContactosMismoDialog();

        pos=Integer.parseInt(JOptionPane.showInputDialog(null, "Ingresa clave de contacto a modificar"));

        nueva.actualizarContacto(pos-1);

        nueva.mostrarContactosMismoDialog();
    }
}
