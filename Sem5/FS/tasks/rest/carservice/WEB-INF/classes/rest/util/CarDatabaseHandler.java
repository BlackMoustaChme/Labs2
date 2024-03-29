package rest.util;

import rest.model.Car;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;


public class CarDatabaseHandler {

    private final IDatabase database;

    public CarDatabaseHandler(IDatabase database) {
        this.database = database;
    }

    public ArrayList<Car> getAllCars(){
        ArrayList<Car> cars = new ArrayList<>();
        PreparedStatement ps = null;
        ResultSet rs = null;
        String select = "select * from ;";
        try {
            ps = database.getConnection().prepareStatement(select);
            rs = ps.executeQuery();
            while (rs.next()) {
                Integer id = rs.getInt(1);
                String user_name = rs.getString(2);
                String brand = rs.getString(3);
                String model = rs.getString(4);
                String color = rs.getString(5);
                String number = rs.getString(6);
                Car car = new Car(id, user_name, brand, model, color, number);
                cars.add(car);
            }
        } catch (Exception e) {
//            closeConnection();
            return cars;
        }
        return cars;
    }

    public ArrayList<Car> getUserCar(String user_name) {
        ArrayList<Car> cars = new ArrayList<>();
        PreparedStatement ps = null;
        ResultSet rs = null;
        String select = "select * from  where user_name=?;";
        try {
            ps = database.getConnection().prepareStatement(select);
            ps.setString(1, user_name);
            rs = ps.executeQuery();
            while (rs.next()) {
                Integer id = rs.getInt(1);
                String brand = rs.getString(3);
                String model = rs.getString(4);
                String color = rs.getString(5);
                String number = rs.getString(6);
                Car car = new Car(id, user_name, brand, model, color, number);
                cars.add(car);
            }
        } catch (Exception e) {
            //closeConnection();
            return cars;
        }
        return cars;
    }

    public void addCar(Car car){
        PreparedStatement ps = null;
        String insert = "insert into  (ownerName, brand, model, color, number) values (?, ?, ?, ?, ?);";
        try {
            ps = database.getConnection().prepareStatement(insert);
            ps.setString(1, car.getOwnerName());
            ps.setString(2, car.getBrand());
            ps.setString(3, car.getModel());
            ps.setString(4, car.getColor());
            ps.setString(5, car.getNumber());
            ps.executeUpdate();
        } catch (Exception e) {
            //closeConnection();
        }
    }

    public void deleteCar(Integer carID){
        PreparedStatement ps = null;
        String insert = "delete from  where id=?;";
        try {
            ps = database.getConnection().prepareStatement(insert);
            ps.setInt(1, carID);
            ps.executeUpdate();
        } catch (Exception e) {
            //closeConnection();
        }
    }
}
