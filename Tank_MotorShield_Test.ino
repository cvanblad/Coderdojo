/*************************************************************
Motor Shield 2-Channel DC Motor Demo
by Randy Sarafan

For more information see:
http://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/

*************************************************************/

#include <IRremote.h>

int RECV_PIN = 5;

IRrecv irrecv(RECV_PIN);

decode_results results;

  int Richting; // 1=vooruit, 2=achteruit, 0=stop

void setup() {

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the IRreceiver
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin


  
}

void loop(){
//Serial.println("start loop");
  if (irrecv.decode(&results)) {
    String test;
    test = (results.value, HEX);
    //Serial.println(test);
    

  if ((results.value) == 0XFF629D){
    Richting = 1;
    Vooruit();
    
      }

   if ((results.value) == 0XFF02FD){
    Richting =0;
    RemLinks();
    RemRechts();
    
    }
      
   if ((results.value) == 0XFFA857){
    //Motor A backward @ full speed
    //Motor B fbackward @ full speed
    Richting = 2;
    Achteruit();
    
      } 

    if ((results.value) == 0XFF22DD){
    Links();
    }    

    if ((results.value) == 0XFFC23D){
    Rechts();
    }
  
/* 
  //Motor A forward @ full speed
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
  digitalWrite(13, LOW);  //Establishes backward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 123);    //Spins the motor on Channel B at half speed

  
  delay(3000);

  
  digitalWrite(9, HIGH);  //Engage the Brake for Channel A
  digitalWrite(9, HIGH);  //Engage the Brake for Channel B


  delay(1000);
  
  
  //Motor A forward @ full speed
  digitalWrite(12, LOW);  //Establishes backward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 123);    //Spins the motor on Channel A at half speed
  
  //Motor B forward @ full speed
  digitalWrite(13, HIGH); //Establishes forward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);   //Spins the motor on Channel B at full speed
  
  
  delay(3000);
  
  
  digitalWrite(9, HIGH);  //Engage the Brake for Channel A
  digitalWrite(9, HIGH);  //Engage the Brake for Channel B
  
  
  delay(1000);
*/
irrecv.resume(); // Receive the next value
  
}
    
  //delay(100);  
}
void Vooruit(){
        //Motor A forward @ full speed
      digitalWrite(12, LOW); //Establishes forward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 170);   //Spins the motor on Channel A at full speed

    //Motor B forward @ full speed
      digitalWrite(13, LOW); //Establishes forward direction of Channel B
      digitalWrite(8, LOW);   //Disengage the Brake for Channel B
      analogWrite(11, 168);   //Spins the motor on Channel B at full speed 

      Serial.println(Richting);
      
    }

void Achteruit(){
        //Motor A forward @ full speed
      digitalWrite(12, HIGH); //Establishes forward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 125);   //Spins the motor on Channel A at full speed

    //Motor B forward @ full speed
      digitalWrite(13, HIGH); //Establishes forward direction of Channel B
      digitalWrite(8, LOW);   //Disengage the Brake for Channel B
      analogWrite(11, 125);   //Spins the motor on Channel B at full speed 

      Serial.println(Richting);
      
    }    

void RemLinks(){
  //Engage the Brake for Channel A & B
      //digitalWrite(8, HIGH);  //Engage the Brake for Channel A rechts
      digitalWrite(9, HIGH);  //Engage the Brake for Channel B links
      
  }
  void RemRechts(){
  //Engage the Brake for Channel A & B
      digitalWrite(8, HIGH);  //Engage the Brake for Channel A rechts
      //digitalWrite(9, HIGH);  //Engage the Brake for Channel B links
      
  }

  void Links(){
    
     //Motor A forward @ full speed
      digitalWrite(12, LOW); //Establishes forward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 100);   //Spins the motor on Channel A at full speed

    //Motor B forward @ full speed
      digitalWrite(13, HIGH); //Establishes forward direction of Channel B
      digitalWrite(8, LOW);   //Disengage the Brake for Channel B
      analogWrite(11, 100);   //Spins the motor on Channel B at full speed 

      //RemRechts();
      delay(100);
       //Vooruit();
       //digitalWrite(8, LOW);   //Disengage the Brake for Channel A
      //Rem();
      /*
      if (Richting = 1){
        digitalWrite(40, HIGH);
        Serial.println(Richting);
        Vooruit();
        
      }
      if (Richting = 2){
        digitalWrite(40, LOW);
        Serial.println(Richting);
        Achteruit();
      }
      */
       switch (Richting) {
          case 1:
            digitalWrite(40, HIGH);
              Serial.println(Richting);
              Vooruit();
            break;
          case 2:
            digitalWrite(40, LOW);
              Serial.println(Richting);
              Achteruit();
            break;
          default: 
            // if nothing else matches, do the default
            // default is optional
          break;
          }
  }
  void Rechts(){
       
       //Motor A forward @ full speed
      digitalWrite(12, HIGH); //Establishes forward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 100);   //Spins the motor on Channel A at full speed

    //Motor B forward @ full speed
      digitalWrite(13, LOW); //Establishes forward direction of Channel B
      digitalWrite(8, LOW);   //Disengage the Brake for Channel B
      analogWrite(11, 100);   //Spins the motor on Channel B at full speed 

      //RemLinks();
      delay(100);
      //Vooruit();
      //digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      //Rem();
      
      /*if (Richting = 1){
        digitalWrite(40, HIGH);
        Serial.println(Richting);
        Vooruit();
        
        
      }
      if (Richting = 2){
        digitalWrite(40, LOW);
        Serial.println(Richting);
        Achteruit();
       
      }
      */
      switch (Richting) {
    case 1:
      digitalWrite(40, HIGH);
        Serial.println(Richting);
        Vooruit();
      break;
    case 2:
      digitalWrite(40, LOW);
        Serial.println(Richting);
        Achteruit();
      break;
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
  }
    

