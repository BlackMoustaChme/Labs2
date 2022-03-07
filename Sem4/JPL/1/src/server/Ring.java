package server;

public class Ring extends Circle {

    private double InnerR;

    @Override
    public double CalcPerimetr() {
        return 2*Math.PI*r+2*Math.PI*InnerR;
    }

    @Override
    public double CalcSquare() {
        return Math.PI*r*r-Math.PI*InnerR*InnerR;
    }
    public Ring(double r, double InnerR) throws Exception{
        super(r);
        if (r>0 && InnerR>0 && InnerR<r){
            //this.r = r;
            this.InnerR = InnerR;
        }
        else throw new Exception("Error, can't create this Ring");
    }
    public double GetInnerR(){
        return InnerR;
    }
}

