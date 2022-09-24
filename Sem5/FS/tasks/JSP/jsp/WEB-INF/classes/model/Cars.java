package model;

import java.io.Serializable;

public class Cars implements Serializable {
    private int id;
    private String brand;
    private String model;
    private String color;
    private String number;

    public Cars(){
    }

    public int getId() {
        return id;
    }

    public void setId(int id){
        this.id = id;
    }

    public String getBrand(){
        return brand;
    }

    public void setBrand(String login){
        this.brand = brand;
    }

    public String getModel(){
        return model;
    }

    public void setModel(String login){
        this.model = model;
    }

    public String getColor(){
        return color;
    }

    public void setColor(String login){
        this.color = color;
    }

    public String getNumber(){
        return number;
    }

    public void setNumber(String login){
        this.number = number;
    }



}
