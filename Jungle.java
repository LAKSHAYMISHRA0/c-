abstract class Animal{
    public void speak(){
        System.out.println("Animal speaks ");
    }
    public void Move(){
        System.out.println("Animal Moves");
    }
    abstract public void eat();
}
class Dog extends Animal{
    public void speak(){
        System.out.println("Dog Barks");
    }
    public void Move(){
        System.out.println("Dog Jumps");
    }
    public void eat(){}
}
class Horse extends Animal{
    public void speak(){
        System.out.println("Horse Neighs");
    }
    public void Move(){
        System.out.println("Horse Runs");
    }
    public void eat(){}
}
public class Jungle {
    public static void main(String[] args) {
        Animal a;
        a=new Dog();
        a.speak();
        a.Move();
        a=new Horse();
        a.speak();
        a.Move();
    }
}
