package module;

import java.sql.ResultSet;
import java.sql.SQLException;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

public class Garage {
    public SimpleIntegerProperty id;
    public SimpleStringProperty brand;
    public SimpleStringProperty color;

    public Garage(int id, String brand, String color){
        this.id = new SimpleIntegerProperty(id);
        this.brand = new SimpleStringProperty(brand);
        this.color = new SimpleStringProperty(color);
    }

    public int getId(){
        return this.id.get();
    }

    public String getBrand(){
        return this.brand.get();
    }

/*    public String getTemplate(){
        return this.template.get();
    }
*/
    public void setId(int id){
        this.id.set(id);
    }

    public void setBrand(String brand){
        this.brand.set(brand);
    }

/*    public void setTemplate(String template){
        this.template.set(template);
    }
*/
    public void setColor(String color){
        this.color.set(color);
    }

    public static ObservableList<Garage> getAllCars() throws SQLException{
        ObservableList<Garage> cars = FXCollections.observableArrayList();
        ResultSet rs;
        String query = "select * from garage";
        rs = Database.exeQuery(query);
        while(rs.next()){
            Garage car = new Garage(rs.getInt("id"), rs.getString("brand"), rs.getString("color"));
            cars.add(car);
        }
        return cars;
    }

    public static ObservableList<Garage> getFilteredCars(String queryFilter) throws SQLException{
        ObservableList<Garage> cars = FXCollections.observableArrayList();
        ResultSet rs;
        String query = "select * from garage where " + queryFilter + ";";
        rs = Database.exeQuery(query);
        while(rs.next()){
            Garage car = new Garage(rs.getInt("id"), rs.getString("brand"), rs.getString("color"));
            cars.add(car);
        }
        return cars;
    }

    public static void addCar(String brand, String color){
        String query = "insert into car(brand, color)\nvalues (\'" + brand + "\', " + color + ");";
        Database.exeUpdate(query);
    }

    public static void updateGarage(String id, String brand, String color){
        String query = "update garage\nset name=\'" + brand + "\', area=" + color + " \nwhere id=" + id + ";";
        Database.exeUpdate(query);
    }

    public static void deleteCar(String id){
        String query = "delete from garage\nwhere id=" + id + ";";
        Database.exeUpdate(query);
    }
}
