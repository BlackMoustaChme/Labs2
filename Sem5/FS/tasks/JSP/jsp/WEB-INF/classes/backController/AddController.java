package backController;

import model.User;
import model.Cars;
import util.Helper;
import java.io.PrintWriter;
import java.io.IOException

import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class AddController implements IController{

    private HttpServletRequest request;
    private HttpServletResponse response;
    private int method;

    public AddController(int method, HttpServletRequest request, HttpServletResponse response){
        this.method = method;
        this.request = request;
        this.response = response;
    }

    public void doMethod(){
        switch (method){
            case 1:
                Get();
                break;
            case 2:
                Post();
                break;
            default:
                break;
        }
    }

    public void Get(){
        PrintWriter printWriter = null;
        try {
            request.setAttribute("viewFile", "add.jsp");
            request.setAttribute("pageTitle", "Add new car /");
            Helper.view(request, response);
        } catch (Exception ex){
            printWriter.println("Error: "+ex.getMessage());
        }
    }

    public void Post(){
        PrintWriter printWriter = null;
        
        
        }

}
