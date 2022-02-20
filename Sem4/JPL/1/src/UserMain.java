import java.util.Scanner;
public class UserMain {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
//        String name = scanner.nextLine();
//        int age = scanner.nextInt();
        double a = scanner.nextInt();
        double b = scanner.nextInt();
        double c = scanner.nextInt();
        double r = scanner.nextInt();
        FiguresOnAPlane A = null;
        FiguresOnAPlane B = null;
        try{
            A = new Triangle(a,b,c);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
//            System.out.println("Catched");
        }
        try{
            B = new Circle(r);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
//            System.out.println("Catched");
        }
//        FiguresOnAPlane A = new Triangle(3,4,5);
//        FiguresOnAPlane B = new Circle(1);
        System.out.println(A.CalcPerimetr()+ "  ");
        System.out.println(A.CalcSquare()+ "    ");
        System.out.println(B.CalcPerimetr()+ "  ");
        System.out.println(B.CalcSquare()+ "    ");
    }
}

