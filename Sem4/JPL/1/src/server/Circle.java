package server;

import server.FiguresOnAPlane;

public class Circle implements FiguresOnAPlane {

    protected double r;

    @Override
    public double CalcPerimetr() {
        return 2*Math.PI*r;
    }

    @Override
    public double CalcSquare() {
        return Math.PI*r*r;
    }
    public Circle(double r) throws Exception{
        if (r>0){
            this.r = r;
        }
        else throw new Exception("Error, can't create this server.Circle");
    }
    public double GetR(){
        return r;
    }
}