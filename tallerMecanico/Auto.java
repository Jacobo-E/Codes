package tallerMecanico;

//import java.util.LocalDate;
import java.time.LocalDate;

public class Auto{
    private String placas;
    private String modelo;
    private String marca;
    private Integer anio;
    private String color;
    private LocalDate fechaEntrada;
    private LocalDate fechaSalida;
    private String descripcionReparacion;
    private String duenio; 
    private Double costoReparacion;

    public String getPlacas(){
        return placas;
    }

    public void setPlacas(String placas){
        this.placas = placas;
    }

    public String getModelo(){
        return modelo;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public String getMarca(){
        return marca;
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public Integer getAnio(){
        return anio;
    }

    public void setAnio(Integer anio){
        this.anio = anio;
    }

    public String getColor(){
        return color;
    }

    public void setColor(String color){
        this.color = color;
    }

    public LocalDate getFechaEntrada(){
        return fechaEntrada;
    }

    public void setFechaEntrada(LocalDate fechaEntrada){
        this.fechaEntrada = fechaEntrada;
    }

    public LocalDate getFechaSalida(){
        return fechaSalida;
    }

    public void setFechaSalida(LocalDate fechaSalida){
        this.fechaSalida = fechaSalida;
    }

    public String getDescripcionReparacion(){
        return descripcionReparacion;
    }

    public void setDescripcionReparacion(String descripcionReparacion){
        this.descripcionReparacion = descripcionReparacion;
    }

    public String getDuenio(){
        return duenio;
    }

    public void setDuenio(String duenio){
        this.duenio = duenio;
    }

    public Double getCostoReparacion(){
        return costoReparacion;
    }

    public void setCostoReparacion(Double costoReparacion){
        this.costoReparacion = costoReparacion;
    }

}
