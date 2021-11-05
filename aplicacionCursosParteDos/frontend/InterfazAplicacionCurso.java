package aplicacionCursosParteDos.frontend;

import java.awt.BorderLayout;
import javax.swing.JFrame;

public class InterfazAplicacionCurso extends JFrame{
    private PanelDatos panelDatos;
    private PanelRegistro panelRegistro;
    private PanelNavegacion panelNavegacion;

    public InterfazAplicacionCurso(){

        setTitle("Aplicacion Cursos");
        setSize(700, 450);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setResizable(false);
        setLayout(new BorderLayout());

        panelDatos = new PanelDatos();
        panelRegistro = new PanelRegistro();
        panelNavegacion = new PanelNavegacion();

        add(panelDatos, BorderLayout.NORTH);
        add(panelRegistro, BorderLayout.CENTER);
        add(panelNavegacion, BorderLayout.SOUTH);

    }

    public static void main (String[] args){
        InterfazAplicacionCurso interfaz = new InterfazAplicacionCurso();
        interfaz.setVisible(true);
    }

}
