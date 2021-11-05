package aplicacionCursosParteDos.frontend;

import javax.swing.JPanel;
import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JTextField;
import java.awt.BorderLayout;
import javax.swing.BorderFactory;
import javax.swing.border.TitledBorder;
import java.awt.GridLayout;

public class PanelDatos extends JPanel{
    private JLabel lbNombre;
    private JTextField txtNombre;

    private JLabel lbPaterno;
    private JTextField txtPaterno;

    private JLabel lbMaterno;
    private JTextField txtMaterno;

    private JLabel lbFechaNac;
    private JTextField txtFechaNac;

    private JLabel lbGenero;
    private JTextField txtGenero;

    //etiqueta para mostrar la imagen
    private JLabel lbImagen;

    public PanelDatos(){
        //creacion del panelDatosAlumnol
        setLayout(new BorderLayout());
        TitledBorder border = BorderFactory.createTitledBorder("Datos Alumno");
        border.setTitleColor(Color.BLUE);
        setBorder(border);

        //crear dos paneles dentro del panel
        JPanel panelDatosAlumno = new JPanel();
        JPanel panelFotoAlumno = new JPanel();

        //se añaden al panel principal
        add(panelDatosAlumno, BorderLayout.CENTER);
        add(panelFotoAlumno, BorderLayout.EAST);

        //Etiquetas 
        lbNombre = new JLabel("Nombre: ");
        lbPaterno = new JLabel("Apellido paterno: ");
        lbMaterno = new JLabel("Apellido materno: ");
        lbGenero = new JLabel("Sexo: ");
        lbFechaNac = new JLabel("Fecha de Nacimiento: ");

        //creacion y configuracion de la zona de texto para los datos
        txtNombre = new JTextField();
        txtNombre.setEditable(false);
        txtNombre.setBackground(Color.LIGHT_GRAY);
        txtNombre.setForeground(Color.BLUE);

        txtPaterno = new JTextField();
        txtPaterno.setEditable(false);
        txtPaterno.setBackground(Color.LIGHT_GRAY);
        txtPaterno.setForeground(Color.BLUE);

        txtMaterno = new JTextField();
        txtMaterno.setEditable(false);
        txtMaterno.setBackground(Color.LIGHT_GRAY);
        txtMaterno.setForeground(Color.BLUE);

        txtGenero = new JTextField();
        txtGenero.setEditable(false);
        txtGenero.setBackground(Color.LIGHT_GRAY);
        txtGenero.setForeground(Color.BLUE);

        txtFechaNac = new JTextField();
        txtFechaNac.setEditable(false);
        txtFechaNac.setBackground(Color.LIGHT_GRAY);
        txtFechaNac.setForeground(Color.BLUE);

        //se agrega el distribuidor grafico
        panelDatosAlumno.setLayout(new GridLayout(7, 2));

        //Se agregan las etiquetas y las cajas de texto al panel principal
        panelDatosAlumno.add(lbNombre);
        panelDatosAlumno.add(txtNombre);
        panelDatosAlumno.add(lbPaterno);
        panelDatosAlumno.add(txtPaterno);
        panelDatosAlumno.add(lbMaterno);
        panelDatosAlumno.add(txtMaterno);
        panelDatosAlumno.add(lbGenero);
        panelDatosAlumno.add(txtGenero);
        panelDatosAlumno.add(lbFechaNac);
        panelDatosAlumno.add(txtFechaNac);

        //crear etiqueta para mostrar la foto
        lbImagen = new JLabel("FOTO DEL ALUMNO");
        //se agrega el panel al panel principal
        panelFotoAlumno.add(lbImagen);

    }

}
