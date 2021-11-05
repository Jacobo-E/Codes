package tallerMecanico;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class PruebaTaller{
    public static void main(String[] args){
        LocalDate fechaAux;

        Mecanico mecanicoUno = new Mecanico();
        mecanicoUno.setNombre("Jorge");
        mecanicoUno.setApodo("El Maik");
        mecanicoUno.setSalario(8000.00);

        Mecanico mecanicoDos = new Mecanico();
        mecanicoDos.setNombre("Franco");
        mecanicoDos.setApodo("Franky");
        mecanicoDos.setSalario(8000.00);

        Mecanico mecanicoTres = new Mecanico();
        mecanicoTres.setNombre("Marco");
        mecanicoTres.setApodo("Polopolo");
        mecanicoTres.setSalario(8000.00);

        Auto vocho = new Auto();
        vocho.setAnio(1986);
        vocho.setCostoReparacion(500.50);
        fechaAux = LocalDate.of(2021, 10, 5);
        vocho.setFechaEntrada(fechaAux);
        fechaAux = LocalDate.of(2021, 10, 8);
        vocho.setFechaSalida(fechaAux);

        Auto viejito = new Auto();
        viejito.setCostoReparacion(200.39);
        fechaAux = LocalDate.of(2021, 10, 9);
        viejito.setFechaEntrada(fechaAux);
        fechaAux = LocalDate.of(2021, 10, 16);
        viejito.setFechaSalida(fechaAux);

        Auto tsuru = new Auto();
        tsuru.setCostoReparacion(3200.30);
        fechaAux = LocalDate.of(2021, 10, 1);
        tsuru.setFechaEntrada(fechaAux);
        fechaAux = LocalDate.of(2021, 10, 9);
        tsuru.setFechaSalida(fechaAux);

        Auto bugati = new Auto();
        Auto ferrari = new Auto();
        Auto nuevo = new Auto();
        Auto tsuruTuneado = new Auto();
        Auto familiar = new Auto();
        Auto tuneado = new Auto();
        Auto escarabajo = new Auto();
        Auto encargo = new Auto();

        mecanicoUno.agregarAuto(vocho);
        mecanicoUno.agregarAuto(viejito);
        mecanicoUno.agregarAuto(tsuru);

        mecanicoDos.agregarAuto(bugati);
        mecanicoDos.agregarAuto(ferrari);
        mecanicoDos.agregarAuto(nuevo);
        mecanicoDos.agregarAuto(tsuruTuneado);

        mecanicoTres.agregarAuto(familiar);
        mecanicoTres.agregarAuto(tuneado);
        mecanicoTres.agregarAuto(escarabajo);
        mecanicoTres.agregarAuto(encargo);

        Taller tallerUno = new Taller();
        tallerUno.setMecanico1(mecanicoUno);
        tallerUno.setMecanico2(mecanicoDos);
        tallerUno.setMecanico3(mecanicoTres);

        for(int i=0; i < tallerUno.consultaAutosEnReparacionMecanico(mecanicoUno).size(); i++){
            System.out.println(tallerUno.consultaAutosEnReparacionMecanico(mecanicoUno).get(i));
        }

    }
}
