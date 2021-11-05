package aplicacionCursosParteDos.frontend;

import javax.swing.JPanel;
import java.awt.Color;
import java.awt.BorderLayout;
import javax.swing.BorderFactory;
import javax.swing.border.TitledBorder;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;

public class PanelRegistro extends JPanel{
    //             atributos
    //etiquetas y listas desplegables
    private JLabel lbCurso;
    private JComboBox<String> cbCurso;
    private JLabel lbTutor;
    private JComboBox<String> cbTutor;

    //botones
    private JButton btnRegistrarCurso;
    private JButton btnEliminarCurso;
    private JButton btnRegistrarTutor;
    private JButton btnEliminarTutor;

    public PanelRegistro(){
        setLayout(null);
        TitledBorder border = BorderFactory.createTitledBorder("Registro a Cursos");
        border.setTitleColor(Color.BLUE);
        setBorder(border);

        //creacion de etiquetas
        lbCurso = new JLabel("Curso: ");
        lbTutor = new JLabel("Tutor: ");

        //creacion listas desplegables
        cbCurso = new JComboBox<String>();
        cbCurso.addItem("CURSO 1");
        cbCurso.addItem("CURSO 2");
        cbCurso.addItem("CURSO 3");
        cbCurso.addItem("CURSO 4");

        cbTutor = new JComboBox<String>();
        cbTutor.addItem("TUTOR 1");
        cbTutor.addItem("TUTOR 2");
        cbTutor.addItem("TUTOR 3");

        //creacion de botones
        btnRegistrarCurso = new JButton("Registrar Curso");
        btnEliminarCurso = new JButton("Eliminar Curso");
        btnRegistrarTutor = new JButton("Registrar Tutor");
        btnEliminarTutor = new JButton("Eliminar Tutor");

        //posiciones de cada objeto etiqueta, lista desplegable y botones
        lbCurso.setBounds(5, 50, 50, 20);
        cbCurso.setBounds(60, 50, 200, 20);
        lbTutor.setBounds(5, 100, 500, 20);
        cbTutor.setBounds(60, 100, 200, 20);

        btnRegistrarCurso.setBounds(10, 150, 140, 20);
        btnEliminarCurso.setBounds(160, 150, 140, 20);
        btnRegistrarTutor.setBounds(310, 150, 140, 20);
        btnEliminarTutor.setBounds(460, 150, 140, 20);

        //se agregan las etiquetas
        add(lbCurso);
        add(cbCurso);
        add(lbTutor);
        add(cbTutor);
        add(btnRegistrarCurso);
        add(btnEliminarCurso);
        add(btnRegistrarTutor);
        add(btnEliminarTutor);

    }
}

