package rest.service;

import jakarta.ws.rs.Path;

import java.util.ArrayList;
import java.util.List;

import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;
import jakarta.ws.rs.HeaderParam;
import jakarta.ws.rs.POST;
import jakarta.ws.rs.core.Response;
import rest.model.Car;
import rest.model.User;
import rest.util.CarDatabaseHandler;
import rest.util.UserDatabaseHandler;

@Path("/car")
public class serverProduct {
    private Jsonb jsonb = JsonbBuilder.create();

    @POST
    @Path("/")
    public Response getCars(@HeaderParam(value="Authorization") String authInfo) {
        if (!checkSession(authInfo)) {
            return Response.ok("No access").build();
        }
        ArrayList<Car> products = CarDatabaseHandler.getAllCars();
        String resultJson = jsonb.toJson(products);
        return Response.ok(resultJson).build();
    }

    @POST
    @Path("/userCar")
    public Response getUserCar(@HeaderParam(value="Authorization") String authInfo, String userJson) {
        if (!checkSession(authInfo)) {
            return Response.ok("No access").build();
        }
        User user = jsonb.fromJson(userJson, User.class);
        String user_name = user.getLogin();
        ArrayList<Car> cars = CarDatabaseHandler.getUsercar(user_name);
        String resultJson = jsonb.toJson(cars);
        return Response.ok(resultJson).build();
    }

    @POST
    @Path("/add")
    public Response sale(@HeaderParam(value="Authorization") String authInfo, String jsonSale) {
        if (!checkSession(authInfo)) {
            return Response.ok("No access").build();
        }
        Car car = jsonb.fromJson(jsonSale, Car.class);
        CarDatabaseHandler.addCar(car);
        return Response.ok().build();
    }

    @POST
    @Path("/delete")
    public Response delete(@HeaderParam(value="Authorization") String authInfo, String jsonDeleteID) {
        if (!checkSession(authInfo)) {
            return Response.ok("No access").build();
        }
        List<Car> carsID = jsonb.fromJson(jsonDeleteID, new ArrayList<Car>() {
        }.getClass().getGenericSuperclass());
        for (int i = 0; i < carsID.size(); i++) {
            Car.deleteCar(carsID.get(i).getId());
        }
        return Response.ok().build();
    }

    private boolean checkSession(String authInfo){
        String[] user = authInfo.split(";");
        if (!UserDatabaseHandler.authUser(user[0], user[1])) {
            return false;
        }
        return true;
    }
}
