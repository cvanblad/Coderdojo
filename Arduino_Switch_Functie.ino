int WillekeurigGetal;

void setup() {
  //Mogelijk maken dat Seriële monitor waarden kan weergeven.
    Serial.begin(9600);

}

void loop() {
  //Onderstaande code oneindig laten uitvoeren.
  
  WillekeurigGetal = random(0, 5);    //Geef de variabele "WillekeurigGetal" een willekeurige waarde tussen 0 en 5.

  Vergelijk(WillekeurigGetal);        //Aanroepen van de functie "Vergelijk()" en geef meteen het net gegenereerde getal "WillekeurigGetal" mee.

}

/*
 * De functie Vergelijk waar de variabele "Getal" gedeclareerd wordt als een integer.
 * Een "void" functie geeft geen waarde terug, alle berekeningen en weergaven gebeuren binnen deze functie.
*/
void Vergelijk(int Getal)             
{
  switch (Getal) 
  {
    case 0:
      // Als "Getal" gelijk is aan 0, dan geven we onderstaande weer in de seriële monitor.
      Serial.println("Getal = 0");
      break;
    case 2:
      // Als "Getal" gelijk is aan 2, dan geven we onderstaande weer in de seriële monitor.
      Serial.println("Getal = 2");
      break;
    default: 
      // Als "Getal" niet gelijk is aan een van bovenstaande waarden, dan geven we onderstaande weer in de seriële monitor.
      Serial.print("iets anders, getal was: ");
      Serial.println(Getal);
    break;
  }
// Wacht 1000 milliseconden (1 seconde).
   delay(1000);
}


