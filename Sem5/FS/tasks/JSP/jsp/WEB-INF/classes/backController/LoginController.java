package backController;

import model.User;
import util.Helper;
import java.io.PrintWriter;
import java.io.IOException

import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class LoginController implements IController {
    private HttpServletRequest request;
    private HttpServletResponse response;
    private int method;

    public LoginController(int method, HttpServletRequest request, HttpServletResponse response){
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
            request.setAttribute("viewFile", "login.jsp");
            request.setAttribute("pageTitle", "Login");
            Helper.view(request, response);
        } catch (Exception ex){
            printWriter.println("Error: "+ex.getMessage());
        }
    }

    public void Post(){
        PrintWriter printWriter = null;
        String[] parameters = {"login", "password"};
        boolean checkResult = Helper.checkParameters(parameters, request.getParameterMap());
        if(!checkResult){
            try {
                request.setAttribute("viewFile", "login.jsp");
                request.setAttribute("message", "Please fill all field");
                Helper.view(request, response);
            } catch (Exception ex){
                printWriter.println("Error: "+ex.getMessage());
            }
        } else {
            String login = request.getParameter("login");
            String password = request.getParameter("password");

            User user = Helper.userDatabaseHandler().login(login, password);

            if(user != null){
                HttpSession session = request.getSession();
                session.setAttribute("user", user);
                response.sendRedirect("mycars");
            } else {
                try {
                    request.setAttribute("message", "No user found");
                    request.setAttribute("viewFile", "login.jsp");
                    request.setAttribute("pageTitle", "Login");
                    Helper.view(request, response);
                } catch (Exception ex){
                    printWriter.println("Error: "+ex.getMessage());
                }
            }
        }

    }

}
