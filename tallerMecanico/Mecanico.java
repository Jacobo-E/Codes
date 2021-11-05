package tallerMecanico;

import java.util.ArrayList;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Mecanico{
    private String nombre;
    private String apodo;
    private Integer noEmpleado;
    private Double salario;
    private ArrayList<Auto> autos;

    public String getNombre(){
        return nombre;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }
    
    public String getApodo(){
        return apodo;
    }

    public void setApodo(String apodo){
        this.apodo = apodo;
    }

    public Integer getNoEmpleado(){
        return noEmpleado;
    }

    public void setNoEmpleado(Integer noEmpleado){
        this.noEmpleado = noEmpleado;
    }

    public Double getSalario(){
        return salario;
    }

    public void setSalario(Double salario){
        this.salario = salario;
    }

    public ArrayList<Auto> getAutos(){
        return autos;
    }

    public Integer totalDeAutosReparadosXMes(Integer mes, Integer anio){
        int autosReparados = 0;
        for(Integer i=0; i < this.autos.size(); i++){
            if(this.autos.get(i).getFechaEntrada().getMonthValue() == mes && this.autos.get(i).getFechaEntrada().getYear() == anio){
                autosReparados++;
            }
        }
        return autosReparados;
    }

    public Double ObtenerComision(Auto auxCom){
        long diasEntreFechas = ChronoUnit.DAYS.between(auxCom.getFechaEntrada(), auxCom.getFechaSalida());
        double comision = 0.0;
        if(diasEntreFechas >= 1 && diasEntreFechas <= 3){
            comision = 0.20;
        }else if(diasEntreFechas >= 4 && diasEntreFechas <= 6){
            comision = 0.15;
        }else if(diasEntreFechas >= 6 && diasEntreFechas <= 8){
            comision = 0.10;
        }else{
            comision = 0.0;
        }

        return (auxCom.getCostoReparacion()*comision);
    }

    public ArrayList<Auto> mostrarAutosNoReparados(){
        ArrayList<Auto> noReparados = new ArrayList<Auto>();
        for(Integer i=0; i < this.autos.size(); i++){
            if(this.autos.get(i).getFechaSalida().isAfter(LocalDate.now())){
                noReparados.add(this.autos.get(i));
            }
        }
        return noReparados;
    }

    public void agregarAuto(Auto aux){
        if(this.autos == null){
            this.autos = new ArrayList<Auto>();
        }

        this.autos.add(aux);
    }

}
