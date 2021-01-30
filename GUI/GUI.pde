import processing.serial.*;

Serial xbeePort;

public void setup()
{
  size(500,500,JAVA2D);
  
  xbeePort = new Serial(this,"COM5", 9600);
}

public void draw()
{
  background(20);
  
  
  if(mouseOverRect(75,50,40,40))    { fill(255); xbeePort.write('w'); }
  else fill(100);
  rect(75,50,40,40);            //  W
  
  if(mouseOverRect(25,100,40,40))   { fill(255); xbeePort.write('a'); }
  else fill(100);
  rect(25,100,40,40);           //  A
  
  if(mouseOverRect(75,100,40,40))   { fill(255); xbeePort.write('s'); }
  else fill(100);
  rect(75,100,40,40);           //  S
  
  if(mouseOverRect(125,100,40,40))   { fill(255); xbeePort.write('d'); }
  else fill(100);
  rect(125,100,40,40);          //  D
}



boolean mouseOverRect(int x, int y, int width, int height)
{
  return ((mouseX >= x) && (mouseX <= (x + width)) && (mouseY >= y) && (mouseY <= (y + height)));
}
