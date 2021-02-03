import g4p_controls.*;
import processing.serial.*;

Serial xbeePort;


public void setup()
{
    size(290, 320, JAVA2D);                            //Initialise the GUI
    createGUI();                                       //Auto generated code from the GP4 Form creator.
    customGUI();
    // Place your setup code here
  
  
    xbeePort = new Serial(this,"COM6", 9600);          //I am using COM6, you might have to chnage this to be the correct port you are using with your USB.
}

public void draw()
{
  background(230);
}

public void send(char c)
{
  History.setText(c + "\n" + History.getText());        //Adds the sent command to the end of the History textbox
  xbeePort.write(c);                                    //Sends the char to the xBee Module
}


// Use this method to add additional statements
// to customise the GUI controls
public void customGUI()
{

}
