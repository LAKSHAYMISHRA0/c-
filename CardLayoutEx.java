import java.awt.*;
public class CardLayoutEx {
    public static void main(String[] args) {
        
        Frame f=new Frame("Card Layout");
        f.setSize(400, 300);
        f.setLayout(new BorderLayout());

        CardLayout cl=new CardLayout();
        Panel cardPanel=new Panel(cl);

        Panel p1=new Panel();
        p1.setLayout(new GridLayout(4,1));

        Panel r1=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label name=new Label("NAME");
        TextField text1=new TextField(20);
        r1.add(name);
        r1.add(text1);

        Panel r2=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label srname=new Label("SURNAME");
        TextField text2=new TextField(20);
        r2.add(srname);
        r2.add(text2);

        Panel r3=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label age=new Label("AGE");
        TextField text3=new TextField(20);
        r3.add(age);
        r3.add(text3);

        Panel r4=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label qualitification=new Label("QUALIFIACTION");
        TextField text4=new TextField(20);
        r4.add(qualitification);
        r4.add(text4);

        p1.add(r1);
        p1.add(r2);
        p1.add(r3);
        p1.add(r4);
        f.add(p1,BorderLayout.CENTER);

        Panel p2=new Panel();
        p2.setLayout(new GridLayout(4,1));
        

        Panel hno=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label home=new Label("H.NO");
        TextField text5=new TextField(20);
        hno.add(home);
        hno.add(text5);

        Panel st=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label street=new Label("STREET");
        TextField text6=new TextField(20);
        st.add(street);
        st.add(text6);

        Panel ar=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label area=new Label("AREA");
        TextField text7=new TextField(20);
        ar.add(area);
        ar.add(text7);

        Panel c=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label city=new Label("CITY");
        TextField text8=new TextField(20);
        c.add(city);
        c.add(text8);

        p2.add(hno);
        p2.add(st);
        p2.add(ar);
        p2.add(c);
        f.add(p2,BorderLayout.CENTER);

        Panel p3=new Panel();
        p3.setLayout(new GridLayout(4,1));
        

        Panel p=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label pin=new Label("PINCODE");
        TextField text9=new TextField(20);
        p.add(pin);
        p.add(text9);

        Panel m=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label mobile=new Label("MOBILE NO.");
        TextField text10=new TextField(20);
        m.add(mobile);
        m.add(text10);

        Panel ph=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label phone=new Label("PHONE");
        TextField text11=new TextField(20);
        ph.add(phone);
        ph.add(text11);

        Panel em=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label email=new Label("EMAIL ID");
        TextField text12=new TextField(20);
        em.add(email);
        em.add(text12);

        p3.add(p);
        p3.add(m);
        p3.add(ph);
        p3.add(em);
        f.add(p3,BorderLayout.CENTER);

        Panel p4=new Panel();
        p4.setLayout(new GridLayout(4,1));
        

        Panel sa=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label sal=new Label("SALARY");
        TextField text13=new TextField(20);
        sa.add(sal);
        sa.add(text13);

        Panel h=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label hra=new Label("H.R.A");
        TextField text14=new TextField(20);
        h.add(hra);
        h.add(text14);

        Panel t=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label ta=new Label("T.A");
        TextField text15=new TextField(20);
        t.add(ta);
        t.add(text15);

        Panel d=new Panel(new FlowLayout(FlowLayout.LEFT));
        Label da=new Label("DA");
        TextField text16=new TextField(20);
        d.add(da);
        d.add(text16);

        p4.add(sa);
        p4.add(h);
        p4.add(t);
        p4.add(d);
        f.add(p4,BorderLayout.CENTER);

        cardPanel.add(p1);
        cardPanel.add(p2);
        cardPanel.add(p3);
        cardPanel.add(p4);

        Panel panel=new Panel(new FlowLayout());
        Button prev=new Button("PREV");
        Button next=new Button("NEXT");
        prev.addActionListener(e->cl.previous(cardPanel));
        next.addActionListener(e->cl.next(cardPanel));
        panel.add(prev);
        panel.add(next);

        f.add(cardPanel,BorderLayout.CENTER);
        f.add(panel,BorderLayout.SOUTH);
        f.setVisible(true);
    }
}
