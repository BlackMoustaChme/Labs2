package backController;

import model.User;
import util.Helper;
import java.io.PrintWriter;
import java.io.IOException

import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class DeleteController implements IController{

    private HttpServletRequest request;
    private HttpServletResponse response;
    private int method;

    public DeleteController(int method, HttpServletRequest request, HttpServletResponse response){
        this.method = method;
        this.request = request;
        this.response = response;
    }

        public void doMethod(){
        switch (method){
            case 1:
                Get();
                break;
            default:
                break;
        }
    }

        public void Get(){
        PrintWriter printWriter = null;
        int carsId = Integer.parseInt(request.getParameter("car_id"));
        Cars foundCars = Helper.carsDatabaseHandler().get(carsId);

        if (foundCars != null) {
            Helper.CarsDatabaseHandler().remove(carsId);
        }
        response.sendRedirect("mycars");
    }

}
