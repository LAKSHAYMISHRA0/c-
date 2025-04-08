import java.awt.*;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
class ScrollBarsInterface implements AdjustmentListener{
    Frame f=new Frame("ScrollBarsInterface");
    Scrollbar sb1,sb2,sb3;
    TextField t1,t2,t3;
    public ScrollBarsInterface(){
        f.setSize(400,300);
        f.setLayout(new BorderLayout());
        Panel p1=new Panel();
        p1.setLayout(new GridLayout(1,3));
        sb1=new Scrollbar(Scrollbar.VERTICAL, 0, 5, 0, 260);
        sb2=new Scrollbar(Scrollbar.VERTICAL, 0, 5, 0, 260);
        sb3=new Scrollbar(Scrollbar.VERTICAL, 0, 5, 0, 260);
        p1.add(sb1);
        p1.add(sb2);
        p1.add(sb3);
        Panel p2=new Panel();
        Label l1=new Label("RED");
        t1=new TextField(5);
        Label l2=new Label("GREEN");
        t2=new TextField(5);
        Label l3=new Label("BLUE");
        t3=new TextField(5);
        p2.add(l1);
        p2.add(t1);
        p2.add(l2);
        p2.add(t2);
        p2.add(l3);
        p2.add(t3);
        f.add(p1,BorderLayout.EAST);
        f.add(p2,BorderLayout.SOUTH);
        f.setBackground(new Color(0,0,0));
        sb1.addAdjustmentListener(this);
        sb2.addAdjustmentListener(this);
        sb3.addAdjustmentListener(this);
        f.setVisible(true);
    }
    public void adjustmentValueChanged(AdjustmentEvent e)
    {
        int RED=sb1.getValue();
        int GREEN=sb2.getValue();
        int BLUE=sb3.getValue();
        f.setBackground(new Color(RED, GREEN, BLUE));
        t1.setText(RED+"");
        t2.setText(GREEN+"");
        t3.setText(BLUE+"");
    } 
    public static void main(String[] args) {
        ScrollBarsInterface s=new ScrollBarsInterface();
    }
}
