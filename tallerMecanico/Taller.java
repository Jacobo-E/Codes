package tallerMecanico;

import java.util.ArrayList;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Taller{
    private String razonSocial;
    private String direccion;
    private Mecanico mecanicoUno;
    private Mecanico mecanicoDos;
    private Mecanico mecanicoTres;

    public String getRazonSocial(){
        return razonSocial;
    }

    public void setRazonSocial(String razonSocial){
        this.razonSocial = razonSocial;
    }

    public String getDireccion(){
        return direccion;
    }

    public void setDireccion(String direccion){
        this.direccion = direccion;
    }

    public Mecanico getMecanico1(){
        return mecanicoUno;
    }

    public void setMecanico1(Mecanico mecanicoUno){
        this.mecanicoUno = mecanicoUno;
    }

    public Mecanico getMecanico2(){
        return mecanicoDos;
    }

    public void setMecanico2(Mecanico mecanicoDos){
        this.mecanicoDos = mecanicoDos;
    }

    public Mecanico getMecanico3(){
        return mecanicoTres;
    }

    public void setMecanico3(Mecanico mecanicoTres){
        this.mecanicoTres = mecanicoTres;
    }

    public ArrayList<Auto> consultaAutosEnReparacionMecanico(Mecanico mecanicoAux){
        return mecanicoAux.mostrarAutosNoReparados();
    }

    public Double calculaSalarioTotalMecanicoXMes(Mecanico mecanicoAux, Integer mes, Integer anio){
        double sumar=0;
        for(int i = 0; i < mecanicoAux.getAutos().size(); i++){
            if(mecanicoAux.getAutos().get(i).getFechaEntrada().getMonthValue() == mes && mecanicoAux.getAutos().get(i).getFechaEntrada().getYear() == anio){
                sumar = sumar + mecanicoAux.ObtenerComision(mecanicoAux.getAutos().get(i));
            }
        }
        return (mecanicoAux.getSalario()+sumar);
    }

}
