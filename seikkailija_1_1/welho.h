void welhoTxt ()  //Printtaa welhon ja pelaajan välisen keskustelun ja kuvan
{        
  bool welho = true; // asetetaan Welhon puhumiselle tarvittava boolean todeksi
  if(welho = true)
  {
      tutki = digitalRead(30);                        
      myGLCD.fillScreen(TAUSTAVARI);
      myGLCD.setColor(SEINAVARI);
      myGLCD.fillRect(0, 0, 339, 195);//Seinä
      
      myGLCD.setColor(64, 55, 55);      //ovi
      myGLCD.fillRect(85,5,230,195);
      myGLCD.setColor(21, 21, 18);
      myGLCD.fillRect(155,5, 159, 195);
      myGLCD.drawRect(84, 4, 231, 195);
      
      myGLCD.setColor(PELAAJANVARI);
      myGLCD.fillCircle(170,230,40);
      myGLCD.setColor(WELHONVARI);
      myGLCD.fillCircle(70, 200, 30);
      txtBox();
      myGLCD.setBackColor(OVIAUKKO);
      myGLCD.setColor(255,255,255);
      
      switch(welhonDialogi) // welhon dialogi muuttuu joka kerta, kun sille jutellaan
      {
        case 1:
          myGLCD.print("Olen suuri ja mahtava Welho!", 3, 3, 0);
          myGLCD.print("seuraavassa huoneessa on", 3, 23, 0);
          myGLCD.print("morko, ole varovainen!", 3, 33, 0);
          delay(5000);
          welhonDialogi++;
          welho = false; 
          break;
        case 2:
          myGLCD.print("Loysitko jo lukitun oven?", 3, 3, 0);
          myGLCD.print("En ole saanut sita itse viela auki.", 3, 13, 0);
          delay(5000);
          welhonDialogi++;
          welho = false; 
          break;
        case 3:
          myGLCD.print("Huomasitko seinilla olevat?", 3, 3, 0);
          myGLCD.print("kirjoitukset? Ne vaikuttavat olevan", 3, 13, 0);
          myGLCD.print("vihjeita lukitun oven avaamiseksi.", 3, 23, 0);
          delay(5000);
          welhonDialogi++;
          welho = false; 
          break;
        case 4:
          myGLCD.print("Kavitko jo moron vartioimassa", 3, 3, 0);
          myGLCD.print("huoneessa? Siella on jotakin", 3, 13, 0);
          myGLCD.print("erikoista kirjoitettuna lattiaan.", 3, 23, 0);
          delay(5000);
          welhonDialogi++;
          welho = false; 
          break;
        case 5:
          myGLCD.print("Olen Tampereen Welhoyhdistyksen", 3, 3, 0);
          myGLCD.print("asettamalla lakisaateisella", 3, 13, 0);
          myGLCD.print("kahvitauolla.", 3, 23, 0);
          myGLCD.print("Tulehan hetken paasta juttelemaan", 3, 65, 0);
          myGLCD.print("uudelleen. Nyt juon Saludoa.", 3, 75, 0);
          delay(8000);
          welhonDialogi = 1;
          welho = false; 
          break;
      }
  }
          
  if (welho == false) // kun welholle puhuminen loppuu, piirretään huone
  {
    piirraHuone = 1;
  }
}
