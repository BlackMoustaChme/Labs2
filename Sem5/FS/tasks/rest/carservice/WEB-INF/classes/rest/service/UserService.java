package rest.service;


import jakarta.ws.rs.Path;

import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;
import jakarta.ws.rs.POST;
import jakarta.ws.rs.core.Response;
import rest.model.User;
import rest.util.UserDatabaseHandler;

import java.util.ArrayList;
import java.util.List;



@Path("/")
public class UserService {
    private Jsonb jsonb = JsonBuilder.create();
 
 @GET
 @Path("/")
 @Produces("text/plain")
 public String ping() {   
  return "OK";
 } 
 
 
 @POST
 public Response login(String userJson) {
     User user;
     user = jsonb.fromJson(userJson, User.class);
     String login = user.getLogin();
     String password = user.getPassword();
     if (DataBaseHandler.authUser(login, password)){
         return Response.ok("Yes").build();
     }
     return Response.ok("No").build();
 }

    @POST
    @Path("/registr")
    public Response registr(String userJson) {
        User user = jsonb.fromJson(userJson, User.class);
        String login = user.getLogin();
        String password = user.getPassword();
        if (UserDatabaseHandler.registerUser(login, password, lastName, name, middleName)){
            return Response.ok("Yes").build();
        }
        return Response.ok("No").build();
    }
 
}