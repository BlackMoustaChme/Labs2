package model;

import util.IDatabase;
import util.IRepository;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class CarsDatabaseHandler implements IRepository<Cars, Integer> {

    private final IDatabase database;

    public CarsDatabaseHandler(IDatabase database) {
        this.database = database;
    }

    @Override
    public Cars get(Integer index){
        Cars cars = null;
        String query = String.format();

        try {
            ResultSet resultSet = database.executeQuery(query);
            while (resultSet.next()){
                cars = new Cars();
                cars.setId(resultSet.getInt("user_id"));
                cars.setBrand(resultSet.getString("brand"));
                cars.setModel(resultSet.getString("model"));
                cars.setColor(resultSet.getString("color"));
                cars.setNumber(resultSet.getString("number"));
            }
        } catch (Exception e){
            return cars;
        }
        return cars;
    }

    @Override
    public List<Cars> getAll(){
        List<Cars> list = new ArrayList<>();
        String query = ;

        try {
            ResultSet resultSet = database.executeQuery(query);
            while (resultSet.next()){
                Cars cars = new Cars();
                cars.setId(resultSet.getInt("user_id"));
                cars.setBrand(resultSet.getString("brand"));
                cars.setModel(resultSet.getString("model"));
                cars.setColor(resultSet.getString("color"));
                cars.setNumber(resultSet.getString("number"));
                list.add(cars);
            }
        } catch (Exception e){
            return list;
        }
        return list;
    }

    public List<Cars> getAllByUserId(Integer userIndex, boolean showAll){
        List<Cars> list = new ArrayList<>();

        String query = "";

        try{
            ResultSet resultSet = database.executeQuery(query);
            while (resultSet.next()){
                Cars cars = new Cars();
                cars.setId(resultSet.getInt("user_id"));
                cars.setBrand(resultSet.getString("brand"));
                cars.setModel(resultSet.getString("model"));
                cars.setColor(resultSet.getString("color"));
                cars.setNumber(resultSet.getString("number"));
                list.add(cars);
            }
        } catch (Exception ex){
            return list;
        }
        return list;
    }

    @Override
    public boolean add(Cars cars){
        boolean result = false;
        String query = String.format();

        try {
            database.executeSQL(query);
            result = true;
        } catch (Exception e){
            return result;
        }
        return result;
    }

    @Override
    public Cars update(Integer index, Cars cars){
        Cars updatedCars = get(index);
        String query = String.format();

        try {
            boolean result = (boolean) database.executeSQL(query);
            updatedCars = result ? updatedCars : cars;

        } catch (Exception e){
            return updatedCars;
        }
        return updatedCars;
    }

    @Override
    public Cars remove(Integer index){
        String query = String.format();
        Cars deletedCars = get(index);

        try {
            database.executeSQL(query);
        } catch (Exception e){
            return deletedCars;
        }
        return deletedCars;
    }

}

