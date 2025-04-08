import java.io.*;
interface Item{
  public void read();
  public void show();
}
class Book implements Item{
  private String title,author,publication;
  public void read(){
    Console con=System.console();
    System.out.println("Enter the title of Book-->");
    title=con.readLine();
    System.out.println("Enter the author name-->");
    author=con.readLine();
    System.out.println("Enter the publications --> ");
    publication=con.readLine();
  }
  public void show(){
    System.out.println("Book:"+title+" Author:"+author+" Publications:"+publication);
  }
}
class Dvd implements Item{
  private String title,director,category;
  public void read(){
    Console con=System.console();
    System.out.println("Enter Title of Movie:");
    title=con.readLine();
    System.out.println("Enter the director name:");
    director=con.readLine();
    System.out.println("Enter the Category:");
    category=con.readLine();
  }
  public void show(){
    System.out.println("Dvd:"+title+" Director:"+director+" Category:"+category);
  }
}
public class Main{
  public static void main(String[] args) {
    Item items[]=new Item[5];
    String c;
    // Item t;
    for (int i = 0;i < 5; i++) {
      System.out.println("Book Or Dvd<b/d> :");
      Console con=System.console();
      c=con.readLine();
      if (c.charAt(0)=='b'){
        items[i]=new Book();
      }
      else{
        items[i]=new Dvd();
      }
      items[i].read();
    }
    for (int i = 0; i < 5; i++) {
      items[i].show();
    }
  }
}
