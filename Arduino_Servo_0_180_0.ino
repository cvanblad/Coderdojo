/* Servo van 0° naar 180° en terug naar 0°
 * Deze nederlandstalige tutorial werd gemaakt door Chris Van Bladel
 * 
 * Bekijk de originele tutorial op:
 * http://www.arduino.cc/en/Tutorial/Sweep
 */


//Plaats hieronder alle bibliotheken die je nodig hebt in je programma.

#include <Servo.h>  //Deze bibliotheek maakt het aansturen van een servo mogelijk.

Servo servo_1;      //Een servo object om de uiteindelijke motor aan te sturen.

int positie = 0;    //Een variabele die de positie gaat bijhouden.

void setup() {
// Alle code die je hier plaatst wordt maar 1 keer uitgevoerd.

  servo_1.attach(2);  //Koppel de servo via pin 2 aan het servo_1 object.
}

void loop() {
  // Alle code die je hier plaatst wordt telkens herhaald.
  
  for (positie = 0; positie <= 180; positie += 1) { 
    
    //Laat de servo draaien van 0° naar 180° in stapjes van 1°
    
    servo_1.write(positie); //Laat de servo draaien naar de waarde in de variabele "positie".
    delay(10);              //Wacht 10ms om de positie te bereiken.
  }

  //Laat de servo draaien van 180° naar 0° in stapjes van 1°
  
  for (positie = 180; positie >= 0; positie -= 1) { 
    servo_1.write(positie); //Laat de servo draaien naar de waarde in de variabele "positie".
    delay(10);              //Wacht 10ms om de positie te bereiken.
  }

}
