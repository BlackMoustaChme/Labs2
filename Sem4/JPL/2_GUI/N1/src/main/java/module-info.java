module com.example.n1 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.n1 to javafx.fxml;
    exports com.example.n1;
}