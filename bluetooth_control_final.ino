#include <SoftwareSerial.h>
#define en1 2
#define en2 7
SoftwareSerial Blue(10, 11); //Rx, Tx respectively
String readdata; //datatype label

void setup() 
{
  Blue.begin(9600);
  Serial.begin(9600);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}
void forward()
{
  
      digitalWrite(3,HIGH);   //logic for left motor 
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);    //logic for right motor
      digitalWrite(6,LOW);
      Serial.println("Forward");
}
void backward()
{
    digitalWrite(3, LOW);    //logic for left motor 
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);   //logic for right motor
      digitalWrite(6, HIGH);
      Serial.println("Backward");
    
  
}
void right()
{
  digitalWrite(3,HIGH);   //logic for left motor 
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);    //logic for stopping right motor
      digitalWrite(6,LOW);
      Serial.println("right");
}
void left()
{
   digitalWrite(3,LOW);   //logic for stopping left motor 
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);    //logic for right motor
      digitalWrite(6,LOW);  
      Serial.println("left");
      
}
void stop()
{
     digitalWrite(3,LOW);   //logic for stopping right motor 
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);    //logic for stopping left motor
      digitalWrite(6,LOW);
      Serial.println("STOP");
  
}

void loop() 
{
  digitalWrite(en1, HIGH);
  digitalWrite(en2, HIGH);
  while (Blue.available())      //Check if there is an available byte to read
  {  
  delay(10);                  //Delay added to make thing stable
  char c = Blue.read();         //Conduct a serial read
  readdata += c;              //build the string- "forward", "reverse", "left" and "right"
   
  if (readdata.length() > 0) 
  {
    Serial.println(readdata);
    if(readdata == "F")
  {
      forward();
  }

  else if(readdata == "B")
  {
     backward();
    
  }

  else if (readdata == "L")
  {
     left();
  }

 else if ( readdata == "R")
 {
  right();    
      
 }

 else if (readdata == "S")
 {
    
    stop(); 
      
 }
readdata="";        //Reset the variable
}
} 
}
