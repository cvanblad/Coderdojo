/*
 * Een voorbeeldprogramma om een functie de oppervlakte van een driehoek te laten berekenen.
 * 
 */
void setup()
{

  Serial.begin(9600);
  float Oppervlakte;    //In deze variabele komt het resultaat van de berekening die in de functie gedaan wordt.
  float Basis;          //In deze variabele komt de breedte van de figuur.
  float Hoogte;         //In deze variabele komt de hoogte van de figuur.
  
  Basis = 4;            //De variabele "Basis" krijgt hier de vaste waarde 4 mee.
  Hoogte = 8;           //De variabele "Hoogte" krijgt hier de vaste waarde 4 mee.
  
  /*
   * bereken de oppervlakte van een figuur met een opgegeven basis en hoogte
  */
      Oppervlakte = BerekenOppervlakteDriehoek(Basis,Hoogte);     //Oppervlakte roept hier de functie "BerekenOppervlakteDriehoek" aan en geeft de basis en de hoogte meteen mee.
  
      // print de oppervlakte tot 2 cijfers na de komma.
      Serial.print("De oppervlakte van de driehoek is: ");
      Serial.println(Oppervlakte, 2);
  
  /*
   * Bereken de oppervlakte van een rechthoek met de opgegeven breedte en hoogte
   */
      Oppervlakte = BerekenOppervlakteRechthoek(Basis,Hoogte);   //Oppervlakte roept hier de functie "BerekenOppervlakteRechthoek" aan en geeft de basis en de hoogte meteen mee.
      
      // print de oppervlakte tot 2 cijfers na de komma.
      Serial.print("De oppervlakte van de rechthoek is: ");
      Serial.println(Oppervlakte, 2);
}

void loop() 
{
  /*
   * In de functie "loop" wordt in dit programma niks uitgevoerd
   */
}

/*
 * De functie "BerekenOppervlakteDriehoek" om de oppervlakte van een driehoek te berekenen en de uitkomst terug te geven.
 */
  float BerekenOppervlakteDriehoek(float b, float h)
  {
    float resultaat;  //De variabele resultaat is enkel aanspreekbaar binnen deze functie.
    
    resultaat = b * h / 2;
    
    return resultaat; //De uitkomst van de berekening teruggeven naar de functie BerekenOppervlakteDriehoek en steek deze uitkomst in de variabele "Oppervlakte"
  }

/*
 * De functie "BerekenOppervlakteRechthoek" om de oppervlakte van een rechthoek te berekenen en de uitkomst terug te geven.
 */
  float BerekenOppervlakteRechthoek(float b, float h)
  {
    float resultaat;  //De variabele resultaat is enkel aanspreekbaar binnen deze functie.
    
    resultaat = b * h;
    
    return resultaat; //De uitkomst van de berekening teruggeven naar de functie BerekenOppervlakteRechthoek en steek deze uitkomst in de variabele "Oppervlakte"
  }
