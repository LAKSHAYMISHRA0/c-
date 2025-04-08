import java.awt.*;
public class FormInterface {
    public static void main(String[] args) {
        Frame f=new Frame("Form");
        f.setSize(400,300);
        f.setLayout(new BorderLayout());
        f.setBackground(Color.RED);
        // Panel p1=new Panel();
        Label l1=new Label("Q. CAPITAL OF RAJASTHAN ?");
        // p1.add(l1);
        f.add(l1,BorderLayout.NORTH);
        Panel p2=new Panel(new GridLayout(4,1));
        CheckboxGroup group=new CheckboxGroup();
        Checkbox A=new Checkbox("AJMER",group,false);
        Checkbox B=new Checkbox("JAIPUR",group, false);
        Checkbox C=new Checkbox("DELHI",group,false);
        Checkbox D=new Checkbox("JODHPUR",group,false);
        p2.add(A);
        p2.add(B);
        p2.add(C);
        p2.add(D);
        Panel p3=new Panel();
        Button b1=new Button("Prev");
        Button b2=new Button("Next");
        p3.add(b1);
        p3.add(b2);
        
        f.add(p2,BorderLayout.WEST);
        f.add(p3,BorderLayout.SOUTH);
        f.setVisible(true);
        
    }
}
