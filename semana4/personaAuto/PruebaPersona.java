package semana4.personaAuto;

import javax.swing.JOptionPane;

public class PruebaPersona{
    public static void main(String[] args){

        Persona pablo;
        Domicilio dom=null;
        Automovil carro;
        String nombre;
        int e;

        pablo = new Persona();
        carro = new Automovil();

        //Nombre
        nombre = JOptionPane.showInputDialog("Ingresa nombre");
        pablo.setNombre(nombre);

        //Teléfono
        pablo.setTelefono(JOptionPane.showInputDialog("Ingresa teléfono"));

        //Edad
        e = Integer.parseInt((JOptionPane.showInputDialog("Ingresa edad")));
        pablo.setEdad(e);

        //Automovil
        carro.setAnio(2000);
        carro.setMarca("Honda");
        carro.setCombustible(Combustible.GASOLINA);
        pablo.setAuto(carro);

        //Direccion
        pablo.setDireccion(dom);

        JOptionPane.showMessageDialog(null, "nombre: "+pablo.getNombre()
                                        +"\nedad: "+pablo.getEdad()
                                        +"\ntelefono: "+pablo.getTelefono()
                                        +"\nauto: "+pablo.getAuto()
                                        +"\n-marca: "+pablo.getAuto().getMarca()
                                        +"\n-año: "+pablo.getAuto().getAnio()
                                        +"\n-combustible: "+pablo.getAuto().getCombustible());

    }
}
