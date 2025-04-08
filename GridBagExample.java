import java.awt.*;
public class GridBagExample {
    public static void main(String[] args) {
        Frame f=new Frame("GridBag");
        f.setSize(400,300);
        f.setLayout(new GridBagLayout());
        Label l1=new Label("Name");
        GridBagConstraints gbc=new GridBagConstraints();
        gbc.gridx=0;
        gbc.gridx=0;
        gbc.anchor=GridBagConstraints.WEST;
        Insets i=new Insets(5, 5, 5, 5);
        gbc.insets=i;
        f.add(l1,gbc);
        TextField text=new TextField(10);
        gbc.gridx=1;
        gbc.gridy=0;
        gbc.anchor=GridBagConstraints.CENTER;
        f.add(text,gbc);
        Label l2=new Label("Password");
        gbc.gridx=0;
        gbc.gridy=1;
        gbc.anchor=GridBagConstraints.WEST;
        f.add(l2,gbc);
        TextField text2=new TextField(10);
        gbc.gridx=1;
        gbc.gridy=1;
        gbc.anchor=GridBagConstraints.CENTER;
        f.add(text2,gbc);
        Button b1=new Button("OK");
        gbc.gridx=0;
        gbc.gridy=2;
        gbc.gridwidth=2;
        gbc.anchor=GridBagConstraints.CENTER;
        f.add(b1,gbc);
        f.setVisible(true);
    }
}
