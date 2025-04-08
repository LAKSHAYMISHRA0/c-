import java.awt.*;
import java.awt.event.*;
public class CalculatorInterface implements ActionListener{
    Frame f=new Frame("Calculator");
    Button b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16;
    TextField text;
    Double n1,n2;
    String operator;
    public CalculatorInterface(){
        f.setSize(400,300);
        f.setLayout(new BorderLayout());
        text=new TextField(20);
        Panel p1=new Panel(new GridLayout());
        p1.add(text);
        Panel p2=new Panel(new GridLayout(4,4));
        b1=new Button("1");
        b1.addActionListener(this);
        p2.add(b1);
        b2=new Button("2");
        b2.addActionListener(this);
        p2.add(b2);
        b3=new Button("3");
        b3.addActionListener(this);
        p2.add(b3);
        b4=new Button("+");
        b4.addActionListener(this);
        p2.add(b4);
        b5=new Button("4");
        b5.addActionListener(this);
        p2.add(b5);
        b6=new Button("5");
        b6.addActionListener(this);
        p2.add(b6);
        b7=new Button("6");
        b7.addActionListener(this);
        p2.add(b7);
        b8=new Button("-");
        b8.addActionListener(this);
        p2.add(b8);
        b9=new Button("7");
        b9.addActionListener(this);;
        p2.add(b9);
        b10=new Button("8");
        b10.addActionListener(this);
        p2.add(b10);
        b11=new Button("9");
        b11.addActionListener(this);
        p2.add(b11);
        b12=new Button("*");
        b12.addActionListener(this);
        p2.add(b12);
        b13=new Button("C");
        b13.addActionListener(this);;
        p2.add(b13);
        b14=new Button("0");
        b14.addActionListener(this);
        p2.add(b14);
        b15=new Button("/");
        b15.addActionListener(this);
        p2.add(b15);
        b16=new Button("=");
        b16.addActionListener(this);
        p2.add(b16);
        f.add(p1,BorderLayout.NORTH);
        f.add(p2,BorderLayout.CENTER);
        f.setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
        String str=e.getActionCommand();
        if (str.equals("1")||str.equals("2")||str.equals("3")||str.equals("4")||str.equals("5")||str.equals("6")||str.equals("7")||str.equals("8")||str.equals("9")||str.equals("0")) {
            text.setText(text.getText()+str);
        }
        else if (str.equals("+")||str.equals("*")||str.equals("/")||str.equals("-")) {
            operator=str;
            n1=Double.parseDouble(text.getText());
            text.setText("");
        }
        else if (str.equals("C")) {
            text.setText("");
        }
        else if (str.equals("=")) {
            n2=Double.parseDouble(text.getText());
            double res=0.0;
            switch (operator) {
                case "+":
                    res=n1+n2;
                    break;
                case "-":
                    res=n1-n2;
                    break;
                case "*":
                    res=n1*n2;
                    break;
                case "/":
                    res=n1/n2;
                    break;
                default:
                    text.setText("error");
                    break;
            }
            text.setText(res+"");
        }
    }
    public static void main(String[] args) {
        CalculatorInterface c=new CalculatorInterface();
    }
}
