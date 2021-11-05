package semana4.agenda;

import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Agenda{

    private ArrayList<Persona> contactos;
    private Persona duenio;

    //-------------Constructores--------------------
    public Agenda(){

    }

    public Agenda(Persona duenio, ArrayList<Persona> contactos){
        this.duenio = duenio;
        this.contactos = contactos;
    }

    public Agenda(ArrayList<Persona> contactos, Persona duenio){
        this.contactos = contactos;
        this.duenio = duenio;
    }

    public Agenda(Persona duenio){
        this.duenio = duenio;
    }

    public Agenda(ArrayList<Persona> contactos){
        this.contactos = contactos;
    }
    //-------------------------------------------------

    //------------Set y get----------------------------
    public Persona getDuenio(){
        return duenio;
    }

    public void setDuenio(Persona duenio){
        this.duenio = duenio;
    }

    public ArrayList<Persona> getContactos(){
        return contactos;
    }

    public void setContactos(ArrayList<Persona> contactos){
        this.contactos = contactos;
    }
    //--------------------------------------------------
    
    //---------------Metodos----------------------------
    public void agregarContactos(Persona per){
        if(contactos == null)
            contactos = new ArrayList<Persona>();

        contactos.add(per);
    }

    public int obtenerTotalContactos(){
        return contactos == null ? 0 : contactos.size();
    }

    public void mostrarContactos(){
        int i = 1;

        for(Persona personaTemp : contactos){
            JOptionPane.showMessageDialog(null, "Contacto "+i+": "+personaTemp.getNombre());
            i++;
        }
    }

    public void mostrarContactosMismoDialog(){
        int i=1;
        String contactosNom="";

        for(Persona personaTemp : contactos){
            contactosNom+="Clave Contacto: "+i+"=>"+personaTemp.getNombre()+" Edad: "+personaTemp.getEdad()+"\n";
            i++;
        }

        JOptionPane.showMessageDialog(null, contactosNom);
    }

    public void actualizarContacto(int posicion){
        if(contactos!=null && posicion < contactos.size()){
            Persona personaTemp = contactos.get(posicion);

            personaTemp.setNombre(personaTemp.getNombre().toUpperCase());
            personaTemp.setEdad(20);
        }
    }

}
