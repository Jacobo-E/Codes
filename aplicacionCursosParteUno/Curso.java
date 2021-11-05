package aplicacionCursosParteUno;

public class Curso{
    private Integer clave;
    private Integer duracion;
    private String nombreCurso;

    public Integer getClave(){
        return clave;
    }

    public void setClave(Integer clave){
        this.clave = clave;
    }

    public Integer getDuracion(){
        return duracion;
    }

    public void setDuracion(Integer duracion){
        this.duracion = duracion;
    }

    public String getNombreCurso(){
        return nombreCurso;
    }

    public void setNombreCurso(String nombreCurso){
        this.nombreCurso = nombreCurso;
    }

}
