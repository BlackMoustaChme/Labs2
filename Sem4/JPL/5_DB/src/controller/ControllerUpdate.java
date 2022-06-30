package controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import module.Garage;

public class ControllerUpdate {

    @FXML
    private TextField color;

    @FXML
    private TextField id;

    @FXML
    private TextField brand;

    @FXML
    private Button ok_btn;

    @FXML
    void updateStage(ActionEvent event) {
        String idString = id.getText();
        String brandString = brand.getText();
        String colorString = color.getText();
        Garage.updateGarage(idString, brandString, colorString);
        Stage stage = (Stage) ok_btn.getScene().getWindow();
        Controller.refresh();
        stage.close();
    }

}