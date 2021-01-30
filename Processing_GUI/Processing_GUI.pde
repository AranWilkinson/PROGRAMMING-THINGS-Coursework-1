// Need G4P library
import g4p_controls.*;
// You can remove the PeasyCam import if you are not using
// the GViewPeasyCam control or the PeasyCam library.
//import peasy.*;

import processing.serial.*;

Serial xbeePort;


public void setup(){
  size(290, 320, JAVA2D);
  createGUI();
  customGUI();
  // Place your setup code here
  
  
  //xbeePort = new Serial(this,"COM5", 9600);
  
}

public void draw(){
  background(230);
  
}

// Use this method to add additional statements
// to customise the GUI controls
public void customGUI(){

}
