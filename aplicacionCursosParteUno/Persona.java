package aplicacionCursosParteUno;

import java.util.Date;

public class Persona{
    private Date fechaNac;
    private Genero genero;
    private String nombre;
    private String paterno;
    private String materno;

    public Date getFechaNacimiento(){
        return fechaNac;
    }

    public void setFechaNacimiento(Date fechaNac){
        this.fechaNac = fechaNac;
    }

    public Genero getGenero(){
        return genero;
    }

    public void setGenero(Genero genero){
        this.genero = genero;
    }

    public String getNombre(){
        return nombre;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public String getPaterno(){
        return paterno;
    }

    public void setPaterno(String paterno){
        this.paterno = paterno;
    }

    public String getMaterno(){
        return materno;
    }

    public void setMaterno(String materno){
        this.materno = materno;
    }

}
