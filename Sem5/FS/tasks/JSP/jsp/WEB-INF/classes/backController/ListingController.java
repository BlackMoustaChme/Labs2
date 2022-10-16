package backController;

import model.User;
import util.Helper;
import java.io.PrintWriter;
import java.io.IOException

import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;


public class ListingController implements IController{

    private HttpServletRequest request;
    private HttpServletResponse response;
    private int method;

    public ListingController(int method, HttpServletRequest request, HttpServletResponse response){
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
        User loginUser = Helper.getLoginUser(request);
        try {
            request.setAttribute("viewFile", "mycars.jsp");
            request.setAttribute("pageTitle", "My cars");
            request.setAttribute("carList", Helper.carsDatabaseHandler().getAllByUserId(loginUser.getId(), true));
            Helper.view(request, response);
        } catch (Exception ex){
            printWriter.println("Error: "+ex.getMessage());
        }
    }

}
