import processing.serial.*;

Serial myPort;
String myString = null;
int angle;
int distance;

void setup(){
  size(1920, 1050);
  background(0);
  myPort = new Serial(this, "COM5", 9600);
}

void draw(){
  noStroke();
  fill(0, 7);
  rect(0, 0, width, height);
  
  drawRadar();
  drawLine();
  drawObject();
}

void serialEvent(Serial mys){
  if(myPort.available() > 0){
    try{
      myString = mys.readStringUntil('.');
      if(myString != null){
         //println(myString);
         String[] list = split(myString, ',');
         angle = int(list[0]);
         //println(angle);
         distance = int(list[1].replace(".",""));
         //println(distance);
      } 
    }catch(Exception e){ //e Error
    } 
  }
}

void drawLine(){
  pushMatrix();
  translate(width/2, height);
  strokeWeight(6);
  stroke(98, 245, 31);
  
  line(0, 0, width/2 * cos(radians(angle)), -width/2*sin(radians(angle)));
  popMatrix();
}

void drawObject(){
  pushMatrix();
  translate(width/2, height);
  strokeWeight(6);
  stroke(255, 10, 10);
  float d = (width/2.0/30.0) * (float)distance;
  if(d < width/2){
    line(d*cos(radians(angle)), -d*sin(radians(angle)), width/2 * cos(radians(angle)), -width/2*sin(radians(angle)));
  }
  popMatrix();
}

void drawRadar(){
  pushMatrix();
  translate(width/2, height);
  noFill();
  stroke(98, 245, 31);
  strokeWeight(2);
  arc(0, 0, width, width, PI, TWO_PI); 
  arc(0, 0, width*2/3, width*2/3, PI, TWO_PI);
  arc(0, 0, width*1/3, width*1/3, PI, TWO_PI);
  line(0, 0, width/2*cos(radians(30)), -width/2*sin(radians(30)));
  line(0, 0, width/2*cos(radians(60)), -width/2*sin(radians(60)));
  line(0, 0, width/2*cos(radians(90)), -width/2*sin(radians(90)));
  line(0, 0, width/2*cos(radians(120)), -width/2*sin(radians(120)));
  line(0, 0, width/2*cos(radians(150)), -width/2*sin(radians(150)));
  
  textSize(16);
  fill(98, 245, 31);
  textAlign(RIGHT);
  text("10cm", width * 1/6, 0);
  text("20cm", width * 2/6, 0);
  text("30cm", width * 3/6, 0);
  
  textAlign(LEFT);
  text("10cm", width * -1/6, 0);
  text("20cm", width * -2/6, 0);
  text("30cm", width * -3/6, 0);
  popMatrix();
}
