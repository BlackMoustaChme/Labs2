package model;

import util.IDatabase;
import util.IRepository;
import model.User;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class UserDatabaseHandler implements IRepository<User, Integer> {

    private final IDatabase database;

    public UserDatabaseHandler(IDatabase database) {
        this.database = database;
    }

    @Override
    public User get(Integer index){
        User user = null;
        String query = String.format();

        try {
            ResultSet resultSet = database.executeQuery(query);
            while (resultSet.next()){
                user = new User();
                user.setId(resultSet.getInt("user_id"));
                user.setLogin(resultSet.getString("login"));
                user.setPassword(resultSet.getString("password"));
            }
        } catch (Exception e){
            return user;
        }
        return user;
    }

    @Override
    public List<User> getAll(){
        List<User> list = new ArrayList<>();
        String query = ;

        try {
            ResultSet resultSet = database.executeQuery(query);
            while (resultSet.next()){
                User user = new User();
                user.setId(resultSet.getInt("user_id"));
                user.setLogin(resultSet.getString("login"));
                user.setPassword(resultSet.getString("password"));
                list.add(user);
            }
        } catch (Exception e){
            return list;
        }
        return list;
    }

    @Override
    public boolean add(User user){
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
    public User update(Integer index, User user){
        User updatedUser = get(index);
        String query = String.format();

        try {
            boolean result = (boolean) database.executeSQL(query);
            updatedUser = result ? updatedUser : user;

        } catch (Exception e){
            return updatedUser;
        }
        return updatedUser;
    }

    @Override
    public User remove(Integer index){
        String query = String.format();
        User deletedUser = get(index);

        try {
            database.executeSQL(query);
        } catch (Exception e){
            return deletedUser;
        }
        return deletedUser;
    }

    public User login(String login, String password) {
        User user = null;
        String query = String.format();

        try {
            ResultSet resultSet = database.executeQuery(query);
            while (resultSet.next()) {
                user = new User();
                user.setId(resultSet.getInt("user_id"));
                user.setLogin(resultSet.getString("login"));
                user.setPassword(resultSet.getString("password"));
            }
        } catch (Exception e){
            return user;
        }
        return user;
    }
}

