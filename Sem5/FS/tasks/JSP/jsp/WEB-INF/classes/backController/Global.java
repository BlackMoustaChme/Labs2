package backController;

public class Global {
    public static IControllerFactory getFactory(){
        BackControllerFactory bcf = new BackControllerFactory();
        return bcf;
    }
}
