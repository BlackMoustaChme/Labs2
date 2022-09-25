package util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;


public class PgSQL implements IDatabase {
    private  final String source;

    public PgSQL(String source) {
        this.source = source;
    }

    @Override
    public Connection getConnection()
            throws  ClassNotFoundException, SQLException {
        Class.forName("");
        return DriverManager.getConnection(source);
    }

    @Override
    public ResultSet executeQuery(String query)
            throws ClassNotFoundException, SQLException {
        return getConnection().createStatement().executeQuery(query);
    }

    @Override
    public Object executeSQL(String sql)
            throws ClassNotFoundException, SQLException {
        return getConnection().createStatement().execute(sql);
    }
}


