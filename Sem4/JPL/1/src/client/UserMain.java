package client;

import server.Circle;
import server.FiguresOnAPlane;
import server.Ring;
import server.Triangle;

import java.util.Scanner;
public class UserMain {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
//        String name = scanner.nextLine();
//        int age = scanner.nextInt();
        System.out.println("Enter a,b,c for Triangle, r for Circle and InnerR for Ring");
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();
        double r = scanner.nextDouble();
        double InnerR = scanner.nextDouble();
        FiguresOnAPlane A = null;
        FiguresOnAPlane B = null;
        FiguresOnAPlane C = null;
        try{
            A = new Triangle(a,b,c);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
            return;
//            System.out.println("Catched");
        }
        try{
            B = new Circle(r);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
            return;
//            System.out.println("Catched");
        }
        try{
            C = new Ring(r,InnerR);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
            return;
//            System.out.println("Catched");
        }
//        server.FiguresOnAPlane A = new server.Triangle(3,4,5);
//        server.FiguresOnAPlane B = new server.Circle(1);
        System.out.println(A.CalcPerimetr()+ "  ");
        System.out.println(A.CalcSquare()+ "    ");
        System.out.println(B.CalcPerimetr()+ "  ");
        System.out.println(B.CalcSquare()+ "    ");
        System.out.println(C.CalcPerimetr()+ "  ");
        System.out.println(C.CalcSquare()+ "    ");
    }
}

