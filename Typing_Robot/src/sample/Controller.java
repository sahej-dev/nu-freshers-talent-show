package sample;

import javafx.fxml.FXML;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import java.awt.*;

public class Controller {
    private boolean isTyping = false;
    private int counter = 0;
    private int delayInt;
    private int maxLimitInt;
    private int mouseXInt, mouseYInt;
    @FXML
    TextArea text;
    @FXML
    TextField delay;
    @FXML
    TextField maxLimit;
    @FXML
    TextField mouseX;
    @FXML
    TextField mouseY;

    //TypingRobot bot = new TypingRobot(text.getText());

    @FXML
    public void startPressed(){
        if(!isTyping) {
            isTyping = true;
            counter = 0;
        }
        delayInt = Integer.parseInt(delay.getText());
        maxLimitInt = Integer.parseInt(maxLimit.getText());
        try { Thread.sleep(5000); }
        catch (Exception e){
            System.out.println("Exception Occurred");
        }
        startTyping();
    }
    public void stopPressed() { isTyping = false; counter = 0;}
    private void startTyping(){
        while (isTyping && counter < maxLimitInt) {
            try{
                new TypingRobot(text.getText()).startTyping(delayInt);
            }
            catch (AWTException e){
                System.out.println("Exception Occurred!");
            }
            counter++;
        }
        isTyping = false;
    }
}

