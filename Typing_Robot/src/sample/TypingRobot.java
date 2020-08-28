package sample;
import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

        public class TypingRobot extends Robot{
            private String text;
            TypingRobot(String input)throws java.awt.AWTException{
                this.text = input;
            }
            public void startTyping(int ms){
                for (int i = 0; i < text.length(); i++) {
                    if(     ((int) text.charAt(i) >= 44 && (int) text.charAt(i) <= 57)
                         || ((int)text.charAt(i) >= 97 && (int) text.charAt(i) <= 122)) {
                        int keyCode = KeyEvent.getExtendedKeyCodeForChar(text.charAt(i));
                        this.keyPress(keyCode);
                        this.keyRelease(keyCode);
                    } else {
                        int keyCode = KeyEvent.getExtendedKeyCodeForChar(text.charAt(i));
                        this.keyPress(KeyEvent.VK_SHIFT);
                        this.keyPress(keyCode);
                        this.keyRelease(keyCode);
                        this.keyRelease(KeyEvent.VK_SHIFT);
                    }
                }
        //this.mouseMove(1555, 963);
        this.mousePress(InputEvent.BUTTON1_DOWN_MASK);
        this.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
//        this.keyPress(KeyEvent.VK_ENTER);
//        this.keyRelease(KeyEvent.VK_ENTER);
        this.delay(ms);
    }
}
