package util;

import util.IDatabase;
import model.User;
import model.UserDatabaseHandler;
import model.CarsDatabaseHandler;
import util.PgSQL;

import java.io.File;
import java.io.IOException;
import java.util.Map;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

public class Helper {

    public static String VIEW_FOLDER = "";
    public static String NOT_FOUND = "";
    public static String DB_SOURCE = "";
    private static IDatabase DATABASE = null;

    public static void view(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String viewFile = getViewFile(request);
        request.getRequestDispatcher(Helper.VIEW_FOLDER + File.separator + viewFile).forward(request, response);
    }

    private static String getViewFile(HttpServletRequest request) {
        Object viewFileAttribute = request.getAttribute("viewfile");
        return (viewFileAttribute == null)
                ? Helper.NOT_FOUND
                : viewFileAttribute.toString();
    }

    private static IDatabase getPgSQLDatabase() {
        if (Helper.DATABASE == null) {
            Helper.DATABASE = new PgSQL(Helper.DB_SOURCE);
        }
        return Helper.DATABASE;
    }

    public static UserDatabaseHandler userDatabaseHandler() {
        return new UserDatabaseHandler(Helper.getPgSQLDatabase());
    }

    public static CarsDatabaseHandler carsDatabaseHandler() {
        return new CarsDatabaseHandler(Helper.getPgSQLDatabase());
    }

    public static boolean checkParameters(String[] parameters, Map<String, String[]> parameterMap) {
        for (String parameter : parameters) {
            if (!parameterMap.containsKey(parameter)) {
                return false;
            }
        }
        return true;
    }

    public static User getLoginUser(HttpServletRequest request) {
        HttpSession session = request.getSession();
        Object userAttribute = session.getAttribute("user");
        return userAttribute == null ? null : (User) userAttribute;
    }
}
