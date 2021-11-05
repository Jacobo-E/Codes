package semana4.personaAuto;

public class Automovil{

    private String placa;
    private String marca;
    private String modelo;
    private String transmision;
    private String color;
    private int anio;
    private Combustible combustible;

    public String getPlaca(){
        return placa;
    }

    public void setPlaca(String placa){
        this.placa = placa;
    }

    public String getMarca(){
        return marca;
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public String getModelo(){
        return modelo;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public String getTransmision(){
        return transmision;
    }

    public void setTransmision(String transmision){
        this.transmision = transmision;
    }

    public String getColor(){
        return color;
    }

    public void setColor(String color){
        this.color = color;
    }

    public Integer getAnio(){
        return anio;
    }

    public void setAnio(Integer anio){
        this.anio = anio;
    }

    public Combustible getCombustible(){
        return combustible;
    }

    public void setCombustible(Combustible combustible){
        this.combustible = combustible;
    }

}
