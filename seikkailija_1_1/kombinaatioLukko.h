void kombinaatioLukko()       //Kombinaatiolukon toiminta
{
  bool tutkiminen = true; 
  bool indikaattoriViiva = true;
  myGLCD.fillScreen(TAUSTAVARI);        //Aluksi piirretään kuva jossa lukkoa avataan
  myGLCD.setColor(SEINAVARI);
  myGLCD.fillRect(0, 0, 339, 195);//Seinä
  
  myGLCD.setColor(64, 55, 55);      //ovi
  myGLCD.fillRect(85,5,230,195);
  myGLCD.setColor(21, 21, 18);
  myGLCD.fillRect(155,5, 159, 195);
  myGLCD.drawRect(84, 4, 231, 195);
  
  myGLCD.setColor(PELAAJANVARI);    //pelaaja
  myGLCD.fillCircle(170,230,40);
  txtBox();                               //kutsutaan txtbox ja printataan ohjeet lukon käyttöön
  myGLCD.print("Ovi on Lukittu. Syota oikeat numerot", 2, 3, 0);
  myGLCD.print("ylos/alas toiminnolla ja vaihda", 2, 13, 0);
  myGLCD.print("numeroa vasen/oikea toiminnoilla.", 2, 23, 0);
    
  delay(200);
  
  myGLCD.printNumI(1 , 20 , 65);
  myGLCD.printNumI(1 ,65, 65);
  myGLCD.printNumI(1 ,110, 65);
  myGLCD.printNumI(1 ,155, 65);

  // painonapin debounceen tarvittavat muuttujat    //Painonapista saadut arvot pomppivat oikealle painaessa

  int painoNapinLukema = LOW;             
  int edellinenPainoNapinLukema = LOW;
  unsigned long debounceAika = 0; 
  unsigned long debounceDelay = 50;  

  while(tutkiminen == true)
  {
    oikea = !digitalRead(22);  //alustetaan muuttujat, jotka lukevat liikuttamiseen käytettäviä pinnejä ( joko HIGH tai LOW)
    vasen = !digitalRead(24);
    ylos = !digitalRead(26);
    alas = !digitalRead(28);
    tutki = !digitalRead(30);

    /* indikaattoriviivan piirto */

    if (rulla == 1 && indikaattoriViiva == true)
    {
      myGLCD.setColor(OVIAUKKO);
      myGLCD.fillRect(15,74,165,76);
      myGLCD.setColor(255,255,255);
      myGLCD.drawLine(20,75,25,75);
      indikaattoriViiva = false;
    }
    if (rulla == 2 && indikaattoriViiva == true)
    {
      myGLCD.setColor(OVIAUKKO);
      myGLCD.fillRect(15,74,165,76);
      myGLCD.setColor(255,255,255);
      myGLCD.drawLine(65,75,70,75);
      indikaattoriViiva = false;
    }
    if (rulla == 3 && indikaattoriViiva == true)
    {
      myGLCD.setColor(OVIAUKKO);
      myGLCD.fillRect(15,74,165,76);
      myGLCD.setColor(255,255,255);
      myGLCD.drawLine(110,75,115,75);
      indikaattoriViiva = false;
    }
    if (rulla == 4 && indikaattoriViiva == true)
    {
      myGLCD.setColor(OVIAUKKO);
      myGLCD.fillRect(15,74,165,76);
      myGLCD.setColor(255,255,255);
      myGLCD.drawLine(155,75,160,75);
      indikaattoriViiva = false;
    }


    /* Kombinaatiolukon numeroiden vaihtaminen */
    
    if (tutki == LOW)
    {
      myGLCD.setBackColor(OVIAUKKO);
      myGLCD.setColor(255,255,255);

      //Painonapin debouncer joka suodattaa kohinat:
      
        if (oikea != edellinenPainoNapinLukema && rulla < 4) //Jos napin tila on muuttunut, if-lause suoritetaan
        {
          debounceAika = millis(); // resetoidaan debouncerin ajastin
        }
        if (millis() - debounceAika > debounceDelay && rulla < 4) //if-lause suoritetaan, jo nappi on ollut samassa tilassa pitempään kuin debounceDelay
        {
          if (oikea != painoNapinLukema) //jos napin tila on muuttunut
          {
            painoNapinLukema = oikea; //asetetaan painoNapinLukemaksi nyt oikea-painonapin tila

            if (painoNapinLukema == HIGH) //Jos tila on HIGH, lisätään rullaan yksi.
            {
              rulla++;
              indikaattoriViiva = true;
              delay(200);
            }
          }
        }
      edellinenPainoNapinLukema = oikea; //asetetaan edellinenPainoNapinLukema oikea-painonapin lukemaan.


      if (rulla == 1)         //Suoritetaan joka rullan numerovalinta ja printataan arvoa näytölle. (Looppi ei onnistu)
      {  
        if (ylos == HIGH && valinta1 < 9)
        {            
          valinta1++;
          delay(200);
        }
       
        if (alas == HIGH && valinta1 > 1)
        {
          valinta1--;
          delay(200);
        }
        if (vasen == HIGH && rulla > 1)
        {
          rulla--;
          indikaattoriViiva = true;
          delay(200);
        }
        if (valinta1 == 1)
        {       
              myGLCD.printNumI(1 , 20 , 65);                 
        }
        if (valinta1 == 2)
        {     
              myGLCD.printNumI(2 , 20 , 65);          
        }
        if (valinta1 == 3)
        {      
              myGLCD.printNumI(3 , 20 , 65);                 
        }
        if (valinta1 == 4)
        {     
              myGLCD.printNumI(4 , 20 , 65);                 
        }
        if (valinta1 == 5)
        {     
              myGLCD.printNumI(5 , 20 , 65);                 
        }
        if (valinta1 == 6)
        {      
              myGLCD.printNumI(6 , 20 , 65);                 
        }
        if (valinta1 == 7)
        {       
              myGLCD.printNumI(7 , 20 , 65);                 
        }
        if (valinta1 == 8)
        {      
              myGLCD.printNumI(8 , 20 , 65);                 
        }
        if (valinta1 == 9)
        {      
              myGLCD.printNumI(9 , 20 , 65);                 
        }
    
      }
      if (rulla == 2)
      {
        if (ylos == HIGH && valinta2 < 9)
        {            
          valinta2++;
          delay(200);
        }
        if (alas == HIGH && valinta2 > 1)
        {
          valinta2--;
          delay(200);
        }
        if (vasen == HIGH && rulla > 1)
        {
          rulla--;
          indikaattoriViiva = true;
          delay(200);
        }
        if (valinta2 == 1)
        {       
              myGLCD.printNumI(1 ,65, 65);                 
        }
         if (valinta2 == 2)
        {       
              myGLCD.printNumI(2 ,65, 65);                
        }
         if (valinta2 == 3)
        {      
              myGLCD.printNumI(3 ,65, 65);                 
        }
         if (valinta2 == 4)
        {      
              myGLCD.printNumI(4 ,65, 65);                 
        }
         if (valinta2 == 5)
        {      
              myGLCD.printNumI(5 ,65, 65);                 
        }
         if (valinta2 == 6)
        {      
              myGLCD.printNumI(6 ,65, 65);                 
        }
         if (valinta2 == 7)
        {       
              myGLCD.printNumI(7 ,65, 65);                 
        }
         if (valinta2 == 8)
        {      
              myGLCD.printNumI(8 ,65, 65);                 
        }
         if (valinta2 == 9)
        {     
              myGLCD.printNumI(9 ,65, 65);                 
        }
                                    
      }
      if (rulla == 3)
      {
        if (ylos == HIGH && valinta3 < 9)
        {            
          valinta3++;
          delay(200);
        }
        if (alas == HIGH && valinta3 > 1)
        {
          valinta3--;
          delay(200);
        }
        if (vasen == HIGH && rulla > 1)
        {
          rulla--;
          indikaattoriViiva = true;
          delay(200);
        }
        if (valinta3 == 1)
        {     
              myGLCD.printNumI(1 ,110, 65);                 
        }
         if (valinta3 == 2)
        {  
              myGLCD.printNumI(2 ,110, 65);                 
        }
         if (valinta3 == 3)
        {   
              myGLCD.printNumI(3 ,110, 65);                  
        }
         if (valinta3 == 4)
        {   
              myGLCD.printNumI(4 ,110, 65);                  
        }
         if (valinta3 == 5)
        {    
              myGLCD.printNumI(5 ,110, 65);                 
        }
         if (valinta3 == 6)
        {    
              myGLCD.printNumI(6 ,110, 65);                  
        }
         if (valinta3 == 7)
        {     
              myGLCD.printNumI(7 ,110, 65);                  
        }
         if (valinta3 == 8)
        {     
              myGLCD.printNumI(8 ,110, 65);                  
        }
         if (valinta3 == 9)
        {      
              myGLCD.printNumI(9 ,110, 65);                  
        }         
      }
      if (rulla == 4)
      {
        if (ylos == HIGH && valinta4 < 9)
        {            
          valinta4++;
          delay(200);
        }
        if (alas == HIGH && valinta4 > 1)
        {
          valinta4--;
          delay(200);
        }
        if (vasen == HIGH && rulla > 1)
        {
          rulla--;
          indikaattoriViiva = true;
          delay(200);
        }
        if (valinta4 == 1)
        {    
              myGLCD.printNumI(1 ,155, 65);                 
        }
         if (valinta4 == 2)
        {   
              myGLCD.printNumI(2 ,155, 65);                
        }
         if (valinta4 == 3)
        {   
              myGLCD.printNumI(3 ,155, 65);                 
        }
         if (valinta4 == 4)
        {    
              myGLCD.printNumI(4 ,155, 65);                 
        }
         if (valinta4 == 5)
        {   
              myGLCD.printNumI(5 ,155, 65);                
        }
         if (valinta4 == 6)
        {    
              myGLCD.printNumI(6 ,155, 65);                
        }
         if (valinta4 == 7)
        {     
              myGLCD.printNumI(7 ,155, 65);                 
        }
         if (valinta4 == 8)
        {   
              myGLCD.printNumI(8 ,155, 65);                
        }
         if (valinta4 == 9)
        {  
              myGLCD.printNumI(9 ,155, 65);                 
        }                               
      }
    }
    
    
  
    if (tutki == HIGH)            //Tutki näppäintä painamalla tarkistetaan annettu koodi
    {
      if (valinta1 == 8 && valinta2 == 6 && valinta3 == 3 && valinta4 == 9) // Oikea koodi 8639
      {
        koodi = true;
      }
      if (koodi == true)
      { 
        txtBox();    //txtBox(); ja siirrytään seuraavaan huoneeseen
        myGLCD.print("Koodi oikein. Ovet avautuvat.", 2, 3, 0);
        delay(4000);
        valinta1 = 1;
        valinta2 = 1;
        valinta3 = 1;
        valinta4 = 1;
        rulla = 1;
        huoneNumero = 7;
        pelaajanX = 40;
        pelaajanY = 120;
        piirraHuone = 1;
        tutkiminen = false;
      }
      if (koodi == false)     //Koodi väärin 
      {
        kk++; //väärästä yrityksestä +1 ja kolmannesta ilmestyy helppo vihje huoneeseen 1.
        txtBox();
        myGLCD.print("Koodi vaarin. Yrita uudelleen.", 2, 3,0);
        if(kk == 3)
        {
          myGLCD.print("(Viereisesta huoneesta", 2, 23,0);
          myGLCD.print("kuuluu ryminaa.)", 2, 33,0);
        }
        delay(4000);
        valinta1 = 1;
        valinta2 = 1;
        valinta3 = 1;
        valinta4 = 1;
        rulla = 1;
        huoneNumero = 4;
        pelaajanX = 280;
        pelaajanY = 120;           
        piirraHuone = 1;
        tutkiminen = false;
      }
    }
  }
}
