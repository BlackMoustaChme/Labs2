package controller;

import java.io.PrintWriter;
import backController.IController;
import backController.BackControllerFactory;

import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;



public class WebController extends HttpServlet
{
    IController ic;
    BackControllerFactory bcf = new BackControllerFactory();
  protected void doPost(HttpServletRequest request, HttpServletResponse response)
  {    
    PrintWriter printWriter = null;
    try	
	{			
        printWriter = response.getWriter();
        String url = request.getRequestURL().toString();
        url = url.substirng(url.lastIndexOf("/"), url.length());
        response.setHeader("Content-Type", "text/html;charset=UTF-8");
        String login = (String) request.getAttribute("login");
        request.setAttribute("login", login);
        switch (url) {
            case "/login":{
                ic = bcf.createController("Login", 2,request, response);
                break;
            }
            case "/listing":{
                break;
            }
            case "/add":{
                break;
            }
            case "/delete":{
                break;
            }
            default:
                break;
        }

	}
	catch (Exception ex)
	{
        printWriter.println("Error: "+ex.getMessage());
	}
  }

  protected void doGet(HttpServletRequest request, HttpServletResponse response){
      PrintWriter printWriter = null;
      try{
          printWriter = response.getWriter();
          String url = request.getRequestURL().toString();
          url = url.substring(url.lastIndexOf("/"), url.length());
          response.setHeader("Content-Type", "text/html;charset=UTF-8");
          switch (url) {
              case "/login":{
                  ic = bcf.createController("Login", 1,request, response);
                  break;
              }
              case "/l":{
                  break;
              }
              default: {
                  break;
              }
          }
      } catch (Exception ex) {
          printWriter.println("Error: "+ex.getMessage());
      }
  }

}