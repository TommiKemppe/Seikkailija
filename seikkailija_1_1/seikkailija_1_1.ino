#include <Adafruit_GFX.h>   //Lisätään aluksi tarvittavat kirjastot
#include <UTFTGLUE.h> 
#include <MCUFRIEND_kbv.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>

#define SPEED 1   //määritellään liikkumisnopeusmuuttuja sekä värit, jotta niitä on helppo muutella
#define TAUSTAVARI  0x8200
#define PELAAJANVARI  0xFFE0
#define SEINAVARI 0x8410
#define OVIAUKKO 0x0000
#define VIHJE 0xFFFF
#define GLYFITAUSTA 0xF800
#define GLYFIVARI 0xFFFF
#define KASSAKAAPPIRULLA 0x39E7
#define LUKITTUOVIVARI 0xF800
#define LEDOFFVARI 0x0400
#define LEDONVARI 0x07E0
#define WELHONVARI 0x07FF

MCUFRIEND_kbv tft;    //alustetaan käyttämämme TFT-näyttö
UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0);

int huone = 1;  //huoneluku, joka alkaa ensimmäisestä huoneesta
int pelaajanX = 160;    //pelaajan alkukoordinaatit
int pelaajanY = 120;
int welhonX = 280;    //welhon koordinaatit
int welhonY = 165;
int moronX = 40;    //mörön koordinaatit
int moronY = 170;
int welhonDialogi = 1;    //muuttuja, joka kertoo switch caselle minkä dialogin welho puhuu
     
int osuma = moronX - pelaajanX;    // muuttujat, jotka kertoo osuuko pelaaja mörköön
int osuma1 = moronY - pelaajanY;
int osuma2 = pelaajanX - moronX;
int osuma3 = pelaajanY - moronY;

int oikea = 0;    // nimetään muuttujat liikkumista varten
int vasen = 0;
int ylos = 0;
int alas = 0;
int tutki = 0; 

int valinta1 = 1;   //Kombinaatilukon muuttujat
int valinta2 = 1;
int valinta3 = 1;
int valinta4 = 1;
int rulla = 1;
int kk = 0; // kombinaatiolukon väärien yritysten muuttuja.


int piirraHuone = 1;  // muuttuja kertoo, piirretäänkö huone (1) vai ei (0)
int huoneNumero = 0;  // muuttuja kertoo, mikä huone on kyseessä


bool ylaOvi = false;    // booleanit määrittävät, mitä ovia huoneessa on
bool alaOvi = false;
bool oikeaOvi = false;
bool vasenOvi = false;

bool morkoOikea = true; // määrittää liikkuuko mörkö oikealle vai vasemmalle
bool koodi = false;   // kertoo onko kombinaatiolukon koodi oikein vai väärin

bool kirjoita = true; // booleanit, joita tarvitaan tekstiin joka ilmestyy kun pelaaja on welhon lähellä
bool welhonLahella = false;

/* kassakaappiin tarvittavat */

const int potikkaAnalogIn = A10; //potikan analog input -pin

int potikkaValue; // näyttää potikan antaman jännitteen arvon (0-1023)
int tyostettavaLed = 50; // kertoo, missä pinnissä olevaa lediä työstetään
long satunnaisLuku = 0; // arvottava satunnaisluku, koodissa arvotaan potikkaValuen arvo, mikä sytyttää ledin

unsigned long startMillis;  // ajastimen aloitusmuuttuja, laskee millisekunteja ylöspäin nollasta lähtien
unsigned long currentMillis; // muuttuja, mikä kertoo ajastimen ajan kyseisellä ajanhetkellä

/* omat kirjastot */

#include "seikkailijaBanner.h" // alkubannerin bitmap
#include "moronBitmapit.h"  // mörön bitmap

#include "nayttoKuvienPiirto.h"  //omat kirjastot funktioille, joita kutsutaan void-loopissa
#include "huoneidenPiirto.h"
#include "kassaKaappiOsio.h"
#include "textBox.h"
#include "kombinaatioLukko.h"
#include "welho.h"
#include "siirtyminenHuoneeseen.h"
#include "liikkuminen.h"
#include "morko.h"


void setup() 
{
  Serial.begin(9600);  // avataan sarjayhteys
  
  myGLCD.InitLCD();    // alustetaan näyttö käyttöön
  myGLCD.setFont(BigFont);   // fontin valinta
  pinMode(22, INPUT_PULLUP);    // alustetaan liikkumiseen käytettävät pinnit inputeiksi
  pinMode(24, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  
  for(int pinNumero = 50; pinNumero < 54; pinNumero++) // for-loop määrittää kassakaappiledeissä käytettävät pinnit outputiksi
  {
  pinMode(pinNumero, OUTPUT);
  }
  
  randomSeed(analogRead(A12)); // alustaa satunnaisuuden kytkemättömän A5-pinnin avulla
}


/* Itse peli void-loopissa */

void loop()
{
  
/* Alustetaan muuttujat, jotka lukevat liikuttamiseen käytettäviä pinnejä ( joko HIGH tai LOW) */
  
  oikea = !digitalRead(22);
  vasen = !digitalRead(24);
  ylos = !digitalRead(26);
  alas = !digitalRead(28);
  tutki = !digitalRead(30);

  /* Liikkuminen painonapeilla */

      liikkuminen();
  
/* Kassakaappiosio */
      
      if(huoneNumero == 7 && pelaajanX > 190 && pelaajanX < 250 && pelaajanY > 70 && pelaajanY < 170)
      {
        kassaKaappi();
        
        huoneNumero = 10;
        piirraHuone = 1;
      }

/* Huoneiden piirtäminen */

      huoneidenPiirto();

/* pelaajan siirtyminen huoneesta toiseen */

      siirtyminenHuoneeseen();

/* Mörön koodi */

      morko();
      delay(10);
}
