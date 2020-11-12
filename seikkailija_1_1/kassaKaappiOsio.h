/* Kassakaappiosio */

void kassaKaappi()  //funktio, joka piirtää näytölle kassakaapin ja suorittaa koko kassakaappiosion
{
  /* kassakaapin piirto */
  
  myGLCD.fillScreen(TAUSTAVARI);
  myGLCD.setColor(64, 55, 55);
  myGLCD.fillRect(0, 0, 339, 195);//Seinä

  myGLCD.setColor(SEINAVARI);      //kassakaappi
  myGLCD.fillRect(60,10,180,220);
  myGLCD.setColor(OVIAUKKO);
  myGLCD.drawRect(60,10,180,220);
  myGLCD.setColor(KASSAKAAPPIRULLA);
  myGLCD.fillCircle(120, 120, 30);
  myGLCD.setColor(OVIAUKKO);
  myGLCD.drawCircle(120, 120, 30);
  myGLCD.setColor(SEINAVARI);
  myGLCD.fillCircle(120, 120, 24);
  myGLCD.setColor(OVIAUKKO);
  myGLCD.drawCircle(120, 120, 24);
  myGLCD.drawLine(120, 110 , 120, 96);

  int ledYmpyranKeskipisteX = 75; //Ledien 1-4 piirtäminen
  int ledVasenReunaX = 65;
  for(int i=1; i<5; i++)
  {
    myGLCD.setColor(OVIAUKKO); 
    myGLCD.drawCircle(ledYmpyranKeskipisteX, 40, 10); 
    myGLCD.drawRect(ledVasenReunaX, 40, ledVasenReunaX +20, 65); 
    myGLCD.setColor(LEDOFFVARI); //aluksi kaikki ledit ovat sammuksissa
    myGLCD.fillCircle(ledYmpyranKeskipisteX, 40, 9);
    myGLCD.fillRect(ledVasenReunaX + 1, 41, ledVasenReunaX +19, 64);
    ledYmpyranKeskipisteX += 30;
    ledVasenReunaX += 30;
  }

  ledYmpyranKeskipisteX = 75; // alustetaan ledien paikka takaisin, jotta voidaan sytyttää ne
  ledVasenReunaX = 65;

  myGLCD.setColor(PELAAJANVARI);
  myGLCD.fillCircle(170,230,40);

  myGLCD.setBackColor(64, 55, 55);
  myGLCD.setColor(255,255,255);
  myGLCD.print("Avaa kassakaappi", 200, 80, 0);

  /* Kassakaapin aukaisu */
  
  while(tyostettavaLed < 54) // While-loop, joka käy yksitellen työstettävät ledit läpi
  {
    potikkaValue = analogRead(potikkaAnalogIn); // potikkaValue määritetään lukemaan potikkaan kytkettyä analog inputtia
    Serial.print(potikkaValue); // tulostaa potikan antaman lukeman serial monitorille
    Serial.print("  ");
    Serial.print(tyostettavaLed); // tulostaa työn alla olevan ledin pinnin serial monitorille
    Serial.print("  ");
    Serial.println(satunnaisLuku); //tulostaa satunnaisluvun, mikä pitää potikan avulla löytää että led syttyy
    if(satunnaisLuku == 0)
    {
      satunnaisLuku = random(100, 950); // tulostaa uuden satunnaisluvun silloin, kun satunnaisluku on 0
    }
    if(potikkaValue < satunnaisLuku || potikkaValue > satunnaisLuku + 40 ) //jos potikka ei ole satunnaisluvun ja satunnaisluku +2:n välillä, niin led ei syty
    {
      digitalWrite (tyostettavaLed, LOW); // työstettävä led ei ole päällä
      startMillis = millis(); //resettaa jatkuvasti ajastinta, kun työstettävä led ei ole päällä
    }
    else //else-lauseessa potikka on tarpeeksi lähellä arvottua satunnaislukua, ja työstettävä led sytytetään
    {
      digitalWrite (tyostettavaLed, HIGH); // sytytetään työstettävä led
      currentMillis = millis(); // tämä kertoo, kauan aikaa on kulunut siitä, kun ajastin on viimeksi resetoitu
      if (currentMillis - startMillis >= 2000) // jos-lause suoritetaan, kun ajastimen viimeisestä resetoinnista on kulunut 2 sekuntia, eli led on ollut 2 sekuntia yhtäjaksoisesti päällä. Tällöin hyväksytään, että pelaaja on löytänyt oikean kohdan potentiometrin avulla.
      {
        for(int ledinValkytys = 1; ledinValkytys < 4; ledinValkytys++) // välkytetään työstettävää lediä kolme kertaa, jotta pelaaja tietää että arvo on hyväksytty ja pelaaja voi siirtyä ratkaisemaan seuraavaa lediä.
        { 
          digitalWrite (tyostettavaLed, LOW); // työstettävä led päälle
          delay(200);
          digitalWrite (tyostettavaLed, HIGH); //työstettävä led pois päältä
          delay(200);
        }
        myGLCD.setColor(LEDONVARI);
        myGLCD.fillCircle(ledYmpyranKeskipisteX, 40, 9);  // sytyttää näytölle piirretyn työstettävän ledin, kun se on saatu oikein
        myGLCD.fillRect(ledVasenReunaX + 1, 41, ledVasenReunaX +19, 64);  // sytyttää näytölle piirretyn työstettävän ledin, kun se on saatu oikein
        ledYmpyranKeskipisteX += 30;  //asetetaan koordinaatit seuraavan ledin sytytystä varten
        ledVasenReunaX += 30; //asetetaan koordinaatit seuraavan ledin sytytystä varten
        satunnaisLuku = 0; //asetetaan satunnaisluku nollaksi, jotta voidaan arpoa uusi satunnaisluku seuraavalle ledille
        tyostettavaLed++; // lisätään työstettävään lediin yksi, jolloin siirrytään ratkaisemaan seuraavaa lediä.
      }
    }
  } 

  if (tyostettavaLed == 54) //kun kaikki 4 lediä on ratkaistu, tyostettavaLed == 7 ja tämä if lause vilkuttaa kaikkia ledejä, jotta pelaaja tietää että kassakaappi on aukaistu onnistuneesti
  {
    for(int ledValkytys = 1; ledValkytys < 9; ledValkytys++)
    {
      digitalWrite (50, HIGH);
      digitalWrite (51, HIGH);
      digitalWrite (52, HIGH);
      digitalWrite (53, HIGH);
      delay(200);
      digitalWrite (50, LOW);
      digitalWrite (51, LOW);
      digitalWrite (52, LOW);
      digitalWrite (53, LOW);
      delay(200); 
    }
    tyostettavaLed++; // siirrytään seuraavan ledin sytyttämiseen
  }
}
