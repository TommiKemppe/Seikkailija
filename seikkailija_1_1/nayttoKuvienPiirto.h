void loppuNaytto()    //Printtaa loppunäytön kun peli voitetaan
{

  int x = 32; // alustetaan x- ja y-koordinaatit, joiden avulla piirretään bitmap oikeaan paikkaan
  int y = 95;
  
  myGLCD.fillScreen(OVIAUKKO); // täytetään näyttö mustalla
  myGLCD.setBackColor(OVIAUKKO); // asetetaan tekstin taustaväriksi musta
  myGLCD.setColor(255,255,255); // asetetaan tekstin väriksi valkoinen
  myGLCD.print("Loysit kassakaapista Graalin Maljan!", CENTER, 50, 0);
  myGLCD.print("Olet aito oikea", CENTER, 80, 0);

  myGLCD.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1); // varataan bitmapille 64x64 alue
  myGLCD.pushColors((const uint8_t*)seikkailijaBanner1, 64 * 64, 1, false); // piirretään Seikkalija-bannerin bitmap neljässä osassa
  myGLCD.setAddrWindow(x + 64, y, x + 128 - 1, y + 64 - 1); // sama kuin edellä
  myGLCD.pushColors((const uint8_t*)seikkailijaBanner2, 64 * 64, 1, false);
  myGLCD.setAddrWindow(x + 128, y, x + 192 - 1, y + 64 - 1);
  myGLCD.pushColors((const uint8_t*)seikkailijaBanner3, 64 * 64, 1, false);
  myGLCD.setAddrWindow(x + 192, y, x + 192 + 67 - 1, y + 64 - 1);
  myGLCD.pushColors((const uint8_t*)seikkailijaBanner4, 67 * 64, 1, false);
  

  myGLCD.setBackColor(OVIAUKKO);
  myGLCD.setColor(255,255,255);
  myGLCD.print("Kiitos kun pelasit peliamme!", CENTER, 200, 0);

  tyostettavaLed = 50; // alustetaan muuttujat, jotta peli voi alkaa alusta
  kk = 0;
  welhonDialogi = 1;
  koodi = false;
  delay(20000);
}
void havioNaytto()
{
  myGLCD.fillScreen(OVIAUKKO); // täytetään näyttö mustalla
  int x = 96; // alustetaan x- ja y-koordinaatit, joiden avulla piirretään bitmap oikeaan paikkaan
  int y = 90;
  myGLCD.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1); // varataan bitmapille 64x64 alue
  myGLCD.pushColors((const uint8_t*)moronHymy1, 64 * 64, 1, false); // piirretään mörön hymyn bitmap kahdessa osassa
  myGLCD.setAddrWindow(x + 64, y, x + 64 + 64 - 1, y + 64 - 1);
  myGLCD.pushColors((const uint8_t*)moronHymy2, 64 * 64, 1, false);
  
  x = 95;// asetetaan x- ja y-koordinaatit, joiden avulla piirretään bitmap oikeaan paikkaan
  y = 50;
  myGLCD.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1); // varataan bitmapille 64x64 alue
  myGLCD.pushColors((const uint8_t*)moronSilma, 64 * 64, 1, false); // piirretään mörölle kaksi silmää
  myGLCD.setAddrWindow(x + 66, y, x + 66 + 64 - 1, y + 64 - 1);
  myGLCD.pushColors((const uint8_t*)moronSilma, 64 * 64, 1, false);
  
  // kirjoitetaan näytölle häviötekstit
  myGLCD.setBackColor(OVIAUKKO);
  myGLCD.setColor(255,255,255);
  myGLCD.print("Morko soi sinut!", CENTER, 180, 0);
  myGLCD.print("Havisit pelin!", CENTER, 190, 0);
  delay(10000);
}

void alkuNaytto()
{
  pelaajanX = 160;    //pelaajan alkukoordinaatit
  pelaajanY = 120;
  
  int x = 32; // alustetaan x- ja y-koordinaatit, joiden avulla piirretään bitmap oikeaan paikkaan
  int y = 50;
  myGLCD.fillScreen(OVIAUKKO); // täytetään näyttö mustalla
  myGLCD.setAddrWindow(x, y, x + 64 - 1, y + 64 - 1); // varataan bitmapille 64x64 alue
  myGLCD.pushColors((const uint8_t*)seikkailijaBanner1, 64 * 64, 1, false); // piirretään Seikkalija-bannerin bitmap neljässä osassa
  myGLCD.setAddrWindow(x + 64, y, x + 128 - 1, y + 64 - 1);
  myGLCD.pushColors((const uint8_t*)seikkailijaBanner2, 64 * 64, 1, false);
  myGLCD.setAddrWindow(x + 128, y, x + 192 - 1, y + 64 - 1);
  myGLCD.pushColors((const uint8_t*)seikkailijaBanner3, 64 * 64, 1, false);
  myGLCD.setAddrWindow(x + 192, y, x + 192 + 67 - 1, y + 64 - 1);
  myGLCD.pushColors((const uint8_t*)seikkailijaBanner4, 67 * 64, 1, false);
  delay(2000);
  myGLCD.setBackColor(OVIAUKKO);
  myGLCD.setColor(255,255,255);
  myGLCD.print("Paina X aloittaaksesi pelin", CENTER, 180, 0);

      
  while (tutki == LOW)  // alkunäyttö pysyy näytöllä niin kauan aikaa, kun X-nappia ei ole painettu
  {
      tutki = !digitalRead(30);
      
      if (tutki == HIGH) // kun X-nappia painetaan, piirretään ensimmäinen huone
      {
        huoneNumero = 1;
      }
  }
      
}
