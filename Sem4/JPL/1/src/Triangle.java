public class Triangle extends FiguresOnAPlane{
    private double a;
    private double b;
    private double c;

    @Override
    public double CalcPerimetr() {
        return a+b+c;
    }

    @Override
    public double CalcSquare() {
        return 0;
    }
    public Triangle(double a,double b,double c) {

        this.a=a;
        this.b=b;
        this.c=c;

    }

}
