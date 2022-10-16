package backController;

import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public interface IControllerFactory {
    public IController createController(String name, int method, HttpServletRequest request, HttpServletResponse response);
}
