package aplicacionCursosParteDos.frontend;

import javax.swing.JPanel;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.BorderLayout;
import javax.swing.BorderFactory;
import javax.swing.border.TitledBorder;
import javax.swing.JButton;

public class PanelNavegacion extends JPanel{
    //          atributos
    //botones
    private JButton btnSiguiente;
    private JButton btnAnterior;

    public PanelNavegacion(){
        setLayout(new FlowLayout());
        TitledBorder border = BorderFactory.createTitledBorder("Navegación");
        border.setTitleColor(Color.BLUE);
        setBorder(border);

        //creacion de botones
        btnSiguiente = new JButton(">");
        btnAnterior = new JButton("<");

        //se agregan los botones
        add(btnAnterior);
        add(btnSiguiente);
    }
}
