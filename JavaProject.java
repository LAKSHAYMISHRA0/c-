import javax.swing.*;
import java.awt.*;
public class JavaProject {
    JFrame window;
    TextArea textArea;
    MenuBar menuBar;
    public static void main(String[] args) {
       new JavaProject();
    }
    public JavaProject(){
        createWindow();
        createTextarea();
        createmenuBar();
        window.setVisible(true);
    }
    public void createWindow(){
        window=new JFrame("Notepad");
        window.setSize(800,600);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void createTextarea(){
        textArea=new TextArea();
        window.add(textArea);
    }
    public void createmenuBar(){
        menuBar=new MenuBar();
        Menu FileMenu=new Menu("File");
        Menu EditMenu=new Menu("Edit");
        Menu Format=new Menu("Format");
        Menu Color=new Menu("Color");
        Menu help=new Menu("Help");
        MenuItem open=new MenuItem("Open");
        open.addActionListener(e->{FileDialog fd=new FileDialog(window,"Open",FileDialog.LOAD);
        fd.setVisible(true);});
        MenuItem save=new MenuItem("Save");
        save.addActionListener(e->{FileDialog fd=new FileDialog(window,"Save",FileDialog.SAVE);
        fd.setVisible(true);});
        MenuItem save_as=new MenuItem("Save As");
        MenuItem Exit=new MenuItem("Exit");
        Exit.addActionListener(e->{int response=JOptionPane.showConfirmDialog(window,"Are you sure you want to Exit !!","Exit Confirmation", JOptionPane.YES_NO_CANCEL_OPTION);
        if (response==JOptionPane.YES_OPTION) {
            System.exit(0);
        }});
        FileMenu.add(open);
        FileMenu.add(save);
        FileMenu.add(save_as);
        FileMenu.add(Exit);


        menuBar.add(FileMenu);
        menuBar.add(EditMenu);
        menuBar.add(Format);
        menuBar.add(Color);
        menuBar.add(help);
        window.setMenuBar(menuBar);
    }
}

