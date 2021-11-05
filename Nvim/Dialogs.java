import javax.swing.JOptionPane;

public class Dialogs{
    public static void main(String[] args){

        String num="";
        num=JOptionPane.showInputDialog("Ingrese un número.");
        JOptionPane.showMessageDialog(null, "Número ingresado es: " +num);

    }
}
