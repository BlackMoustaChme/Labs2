package server;

public class Triangle implements FiguresOnAPlane {
    private double a;
    private double b;
    private double c;

    @Override
    public double CalcPerimetr() {
        return a+b+c;
    }

    @Override
    public double CalcSquare() {
        return Math.sqrt((((CalcPerimetr()/2)*((CalcPerimetr()/2)-a)*(CalcPerimetr()/2)-a)*(CalcPerimetr()/2)-a));
    }
    public Triangle(double a,double b,double c) throws Exception{
        if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        else throw new Exception("Error, can't create this server.Triangle");
    }
    public double GetA(){
        return a;
    }
    public double GetB(){
        return b;
    }
    public double GetC(){
        return c;
    }


}
