//原型模式

public class Square extends Shape {
    public Square(){
        type = "Square";
    }

    public void draw(){
        System.out.println("Inside Square::draw() method.");
    }

}
