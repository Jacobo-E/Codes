package semana4.personaAuto;

public class Persona{

    private String nombre;
    private String telefono;
    private String apellidoP;
    private String apellidoM;
    private String correoElectronico;
    private int edad;
    private Domicilio direccion;
    private Automovil auto;

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

    public String getTelefono(){
        return telefono;
    }

    public void setTelefono(String telefono){
        this.telefono = telefono;
    }

    public Domicilio getDireccion(){
        return direccion;
    }

    public void setDireccion(Domicilio direccion){
        this.direccion = direccion;
    }

    public Automovil getAuto(){
        return auto;
    }

    public void setAuto(Automovil auto){
        this.auto = auto;
    }

}
