import java.awt.*;
import javax.swing.*;
public class Example {
    public static void main(String[] args) {
        JFrame f=new JFrame("window");
        f.setSize(400,300);
        f.setLayout(new FlowLayout());
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Label l=new Label("ENTER NAME:",Label.LEFT);
        if (l.getAlignment()==Label.RIGHT || l.getAlignment()==Label.CENTER) {
            l.setAlignment(Label.LEFT);
        }
        f.add(l);
        TextField t=new TextField();
        f.add(t);
        Button b1=new Button("OK");
        f.add(b1);
        Button b2=new Button("CANCEL");
        f.add(b2);
        CheckboxGroup pizzaGroup=new CheckboxGroup();
        Checkbox cblarge=new Checkbox("Large pizza",pizzaGroup,false);
        Checkbox cbmedium=new Checkbox("Medium pizza",pizzaGroup,false);
        Checkbox cbsmall=new Checkbox("Small pizza",pizzaGroup,true);
        f.add(cblarge); f.add(cbmedium); f.add(cbsmall);
        if (cblarge.getState()==false) {
            cblarge.setState(true);
        }
        if (pizzaGroup.getSelectedCheckbox()!=cblarge){
            pizzaGroup.setSelectedCheckbox(cblarge);
        }
        Choice ch=new Choice();
        ch.add("c++");
        ch.add("java");
        ch.add("php");
        f.add(ch);
        List myList=new List(3,true);
        myList.add("R");
        myList.add("Hadoop");
        myList.add("Spark");
        myList.add("Scala");
        myList.add("Pig");
        myList.add("Hive");
        f.add(myList);
        if (myList.isMultipleMode()==false) {
            myList.setMultipleMode(true);
        }
        String[] arr;
        arr=myList.getItems();
        for (String string : arr) {
            System.out.println(string);
        }
        myList.replaceItem("Mahout",2);
        Canvas c=new Canvas();
        c.setSize(100,80);
        c.setBackground(Color.red);
        f.add(c);
        Scrollbar sb=new Scrollbar(Scrollbar.HORIZONTAL,25,5,0,100);
        f.add(sb);
        f.setVisible(true);
    }
}
