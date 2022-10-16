package backController;

import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public class BackControllerFactory implements IControllerFactory{

    public IController createController(String name, int method, HttpServletRequest request, HttpServletResponse response) {
        IController ic = null;
        switch (name){
            case "Login":
                ic = new LoginController(method, request, response);
                break;

            case "":
                break;

            case "":
                break;

            case "":
                break;

            default:
                break;
        }
        return ic;
    }

}
