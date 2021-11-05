package semana4.agenda;

import java.util.Date;

public class Persona{

    private String nombre;
    private String apellidoP;
    private String apellidoM;
    private int edad;
    private String[] correoElectronico;
    private Date fechaNacimiento;
    private Domicilio direccion;
    private Telefono[] numerosTel;

    public Persona(){ //Constructor por defecto
        
    }
    
    public Persona(String nombre, String apellidoP, String apellidoM){
        this.nombre = nombre;
        this.apellidoP = apellidoP;
        this.apellidoM = apellidoM;
    }

    public Persona(String nombre, String apellidoP){
        this.nombre = nombre;
        this.apellidoP = apellidoP;
    }

    public Persona(String nombre){
        this.nombre = nombre;
    }

    public String getNombre(){
        return nombre;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public int getEdad(){
        return edad;
    }

    public void setEdad(int edad){
        this.edad = edad;
    }

    public Telefono[] getNumerosTel(){
        return numerosTel;
    }

    public void setNumerosTel(Telefono[] numerosTel){
        this.numerosTel = numerosTel;
    }

    public Date getFechaNacimiento(){
        return fechaNacimiento;
    }

    public void setFechaNacimiento(Date fechaNacimiento){
        this.fechaNacimiento = fechaNacimiento;
    }

    public String getApellidoP(){
        return apellidoP;
    }

    public void setApellidoP(String apellidoP){
        this.apellidoP = apellidoP;
    }

    public String getApellidoM(){
        return apellidoM;
    }

    public void setApellidoM(String apellidoM){
        this.apellidoM = apellidoM;
    }

    public String[] getCorreoElectronico(){
        return correoElectronico;
    }

    public void setCorreoElectronico(String[] correoElectronico){
        this.correoElectronico = correoElectronico;
    }

    public Domicilio getDireccion(){
        return direccion;
    }

    public void setDireccion(Domicilio direccion){
        this.direccion = direccion;
    }

}
