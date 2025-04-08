import java.awt.*;
import javax.swing.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class FileDialogExample {
    public static void main(String[] args) throws IOException{
        JFrame f=new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(400, 300);
        f.setVisible(true);
        FileDialog fd=new FileDialog(f,"SELECT",FileDialog.LOAD);
        fd.setVisible(true);
        String Path,Name;
        Name=fd.getFile();
        Path=fd.getDirectory();
        System.out.println("YOU HAVE SELECTED "+Name+" IN"+Path);
        String fullPath=Path+Name;
        try{
        BufferedReader reader = new BufferedReader(new FileReader(fullPath));
        String line;
        while ((line=reader.readLine())!=null) {
            System.out.println(line);
        }
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }
}
