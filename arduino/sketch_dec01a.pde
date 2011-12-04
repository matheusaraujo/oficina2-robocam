#include <Robot.h>

#include<util/delay.h>

Robot robot;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

}

void loop() {

  if(Serial.available()){
    
    int x = Serial.read();
    
    if (x == 79){
       robot.move(Constants::FORWARD);
       digitalWrite(7, HIGH);
       digitalWrite(8, HIGH);
    }    
    else if(x == 39){
      robot.move(Constants::SPINLEFT);
        digitalWrite(7, HIGH);
       digitalWrite(8, HIGH);
    }
    else if(x == 78){
      robot.move(Constants::SPINRIGHT);
             digitalWrite(7, HIGH);
       digitalWrite(8, HIGH);
    }
    else if(x == 19){
      robot.move(Constants::BACKWARD);
             digitalWrite(7, HIGH);
       digitalWrite(8, HIGH);
    }
    else if(x == 77){
      robot.move(Constants::STOP);
             digitalWrite(7, HIGH);
       digitalWrite(8, HIGH);
    }
    
  }
  else {
      robot.move(Constants::STOP);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
  }
 
}
