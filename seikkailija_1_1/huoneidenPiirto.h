void piirraOvet()  //funktio piirtää huoneeseen ovet
{
  myGLCD.setColor(OVIAUKKO);  // valitaan oviaukon väri
  
  if (ylaOvi == true) // if-lause suoritetaan, jos yläOvi == true, piirrettävät ovet määritellään joka huoneessa erikseen näiden booleanien avulla
  {
     myGLCD.fillRect(130, 0, 190, 20);  //piirtää yläoven täyttämällä suorakulmion värillä
  }
  if (alaOvi == true) // muiden ovien piirto toimii samalla periaatteella kuin yläoven
  {
    myGLCD.fillRect(130, 220, 190, 240);
  }
  if (oikeaOvi == true)
  {
    myGLCD.fillRect(300, 90, 320, 150);
  }
  if (vasenOvi == true)
  {
    myGLCD.fillRect(0, 90, 20, 150);
  }
}

void uusiHuone() // funktio piirtää koko huoneen ja pelaajan
{
  myGLCD.fillScreen(TAUSTAVARI);    // täytetään näyttö taustavärillä
  myGLCD.setColor(SEINAVARI);   // valitaan seuraavaksi seinien väri, ja piirretään seinät jokaiseen näytön reunaan koordinaattien avulla
  myGLCD.fillRect(0, 0, 20, 240);   //funktio piirtää näytön vasempaan reunaan suorakulmion(x1, y1, x2, y2) ja täyttää sen seinävärillä. Toistetaan tämä kaikille neljälle reunalle
  myGLCD.fillRect(0, 0, 320, 20);
  myGLCD.fillRect(300, 0, 320, 240);
  myGLCD.fillRect(0, 220, 320, 240);
 
  piirraOvet();   // suoritetaan piirraOvet-funktio, joka piirtää huoneeseen ovet tässä funktiossa aimmin määritettyjen booleanien mukaan
  myGLCD.setColor(PELAAJANVARI);  //  valitaan väriksi pelaajan väri
  myGLCD.fillCircle(pelaajanX, pelaajanY, 10); // piirretään pelaaja pelaajan koordinaatteihin. Pelaaja on ympyrä, joka on täytetty pelaajan värillä
}



/*funktiot huoneiden piirtämiseen */


void huone1()
{
  ylaOvi = true;    // booleanit kertovat, mitkä ovet piirretään
  alaOvi = false;
  oikeaOvi = true;
  vasenOvi = false;
  
  uusiHuone();

        if (kk >= 3) // Jos 3 krt väärin, helppo vihje ilmestyy huoneeseen 1.
        {
          myGLCD.setColor(VIHJE);  // Vihjeväri

          myGLCD.drawLine(145,222,160,222); //Neliö
          myGLCD.drawLine(160,222,160,236);
          myGLCD.drawLine(160,236,145,236);
          myGLCD.drawLine(145,236,145,222);
        
          myGLCD.drawLine(175,226,185,226); //yhtäsuuruusmerkki
          myGLCD.drawLine(175,232,185,232);
        
          myGLCD.drawLine(205,222,205,236); //Numero 4
          myGLCD.drawLine(207,230,200,230);
          myGLCD.drawLine(200,230,205,222);
        }
}

void huone2()  // muiden huoneiden piirto toimii täysin samalla tavalla kuin ensimmäisen
{
  ylaOvi = false;
  alaOvi = true;
  oikeaOvi = true;
  vasenOvi = false;

  uusiHuone(); 

        myGLCD.setColor(VIHJE); //Vihjeväri
      
        myGLCD.drawLine(121,2,128,9); //Seitsenkulmio
        myGLCD.drawLine(128,9,125,9);
        myGLCD.drawLine(125,9,125,16);
        myGLCD.drawLine(125,16,117,16);
        myGLCD.drawLine(117,16,117,9);
        myGLCD.drawLine(117,9,114,9);
        myGLCD.drawLine(114,9,121,2);
      
        myGLCD.drawLine(136,9,146,9); //- merkki
      
        myGLCD.drawLine(154,2,166,2); //Neliö
        myGLCD.drawLine(166,2,166,16);
        myGLCD.drawLine(166,16,154,16);
        myGLCD.drawLine(154,16,154,2);
      
        myGLCD.drawLine(174,6,184,6); // yhtäsuuruusmerkki
        myGLCD.drawLine(174,12,184,12);
      
        myGLCD.drawLine(192,3,206,3); // Kärkikolmio
        myGLCD.drawLine(206,3,199,17);
        myGLCD.drawLine(199,17,192,3);
}


void huone3()     //vihje 3 tässä huoneessa
{
  ylaOvi = false;
  alaOvi = false;
  oikeaOvi = true;
  vasenOvi = false;
 
  uusiHuone();
       
        myGLCD.setColor(VIHJE);  // Vihjeväri
        
        myGLCD.drawLine(113,3,99,17);  //Ensimmäinen kolmio
        myGLCD.drawLine(99,17,127,17);
        myGLCD.drawLine(127,17,113,3);
        
        myGLCD.drawLine(136,5,136,15); //+ merkki
        myGLCD.drawLine(131,10,141,10);
        
        myGLCD.drawLine(160,3,146,17); //Toinen kolmio
        myGLCD.drawLine(146,17,174,17);
        myGLCD.drawLine(174,17,160,3);
        
        myGLCD.drawLine(180,6,190,6); //Yhtäsuuruusmerkki
        myGLCD.drawLine(180,14,190,14);
        
        myGLCD.drawLine(200,3,207,10); //Kuusikulmio
        myGLCD.drawLine(207,10,200,17);
        myGLCD.drawLine(200,17,210,17);
        myGLCD.drawLine(210,17,217,10);
        myGLCD.drawLine(217,10,210,3);
        myGLCD.drawLine(210,3,200,3);
}

void huone4()
{
  ylaOvi = false;
  alaOvi = false;
  oikeaOvi = true;
  vasenOvi = true;
  
  uusiHuone();

  if (koodi == false)         //Jos kombinaatiolukon yhdistelmä on väärin, näytä ovi eri värillä
  {
    myGLCD.setColor(LUKITTUOVIVARI);
    myGLCD.fillRect(300, 90, 320, 150);
  }
}

void huone5()   //Vihje 3 tässä huoneessa
{
  ylaOvi = true;
  alaOvi = false;
  oikeaOvi = false;
  vasenOvi = true;

  uusiHuone();

      myGLCD.setColor(VIHJE);  // Vihjeväri
    
      myGLCD.drawCircle(160,230,7); //Ympyrä
    
      myGLCD.drawLine(113,222,127,222); //Viisikulmio
      myGLCD.drawLine(127,222,127,236);
      myGLCD.drawLine(127,236,113,236);
      myGLCD.drawLine(113,236,120,229);
      myGLCD.drawLine(120,229,113,222);
    
      myGLCD.drawLine(140,224,140,234); //+ merkki
      myGLCD.drawLine(135,229,145,229);
    
      myGLCD.drawLine(175,226,185,226); //yhtäsuuruusmerkki
      myGLCD.drawLine(175,232,185,232);
    
      myGLCD.drawLine(200,222,214,222); //Viisikulmio
      myGLCD.drawLine(214,222,214,236);
      myGLCD.drawLine(214,236,200,236);
      myGLCD.drawLine(200,236,193,229);
      myGLCD.drawLine(193,229,200,222);
}

void huone6()     //Welho tässä huoneessa
{
  ylaOvi = false;
  alaOvi = true;
  oikeaOvi = true;
  vasenOvi = true;

  uusiHuone();
  myGLCD.setColor(WELHONVARI);          //NPC joka varoittaa möröstä
  myGLCD.fillCircle(welhonX, welhonY, 10);
}

void huone7() //Kassakaappi tässä huoneessa
{
  ylaOvi = false;
  alaOvi = false;
  oikeaOvi = false;
  vasenOvi = true;

  uusiHuone();
  
  myGLCD.setColor(SEINAVARI);           //Kassakaappi piirrettynä
  myGLCD.fillRect(200, 80, 240, 160);
  myGLCD.setColor(KASSAKAAPPIRULLA);
  myGLCD.fillCircle(220, 120, 12);
  myGLCD.setColor(SEINAVARI);
  myGLCD.fillCircle(220, 120, 8);
  myGLCD.setColor(OVIAUKKO);
  myGLCD.drawCircle(220, 120, 12);
  myGLCD.drawCircle(220, 120, 8);
  myGLCD.drawLine(220,112,220,117);
  myGLCD.drawRect(200, 80, 240, 160);

}

void huone8()         //Kombinaatiolukon vihje tässä huoneessa
{
  ylaOvi = true;
  alaOvi = false;
  oikeaOvi = false;
  vasenOvi = false;

  uusiHuone();
    
      myGLCD.setColor(GLYFITAUSTA);       //Punainen tausta
      myGLCD.fillRect(21, 120, 299, 220);
      
      myGLCD.setColor(GLYFIVARI); //Kombinaatiolukon oikea yhdistelmä puzzle
    
      myGLCD.drawLine(25,130,65,130); //Kahdeksankulmio
      myGLCD.drawLine(65,130,85,150);
      myGLCD.drawLine(85,150,85,190);
      myGLCD.drawLine(85,190,65,210);
      myGLCD.drawLine(65,210,25,210);
      myGLCD.drawLine(25,210,45,190);
      myGLCD.drawLine(45,190,45,150);
      myGLCD.drawLine(45,150,25,130);
    
      myGLCD.drawLine(95,130,115,170); //Kuusikulmio
      myGLCD.drawLine(115,170,95,210);
      myGLCD.drawLine(95,210,155,210);
      myGLCD.drawLine(155,210,135,170);
      myGLCD.drawLine(135,170,155,130);
      myGLCD.drawLine(155,130,95,130);
    
      myGLCD.drawLine(165,130,165,210); //kärkikolmio
      myGLCD.drawLine(165,210,225,170);
      myGLCD.drawLine(225,170,165,130);
    
      myGLCD.drawLine(235,210,235,150); //Yhdeksänkulmio
      myGLCD.drawLine(235,150,255,130);
      myGLCD.drawLine(255,130,275,130);
      myGLCD.drawLine(275,130,295,150);
      myGLCD.drawLine(295,150,265,150);
      myGLCD.drawLine(265,150,265,170);
      myGLCD.drawLine(265,170,295,170);
      myGLCD.drawLine(295,170,295,210);
      myGLCD.drawLine(295,210,235,210);
}

void huone9()     //mörkö tässä huoneessa
                                                     
  {
  ylaOvi = false;
  alaOvi = true;
  oikeaOvi = false;
  vasenOvi = true;

  uusiHuone();   
  }

void huoneidenPiirto() // funktio jokaisen huoneen piirtämiseen, sekä alku- että loppunäytön piirtämiseen
{
    while (piirraHuone == 1 && huoneNumero == 0)
    {      
      alkuNaytto();      
    }
    while (piirraHuone == 1 && huoneNumero == 1)  // jos muuttuja piirraHuone == 1 ja huonenumero == 1, niin funktio piirtää huoneen 1 ja asettaa piirraHuone = 0, jotta ei jatkuvasti piirretä huonetta uudestaan.
    {
    huone1();
    piirraHuone = 0;
    }
    while (piirraHuone == 1 && huoneNumero == 2)  // jos muuttuja piirraHuone == 1 ja huonenumero == 2, niin funktio piirtää huoneen 2 ja asettaa piirraHuone = 0, jotta ei jatkuvasti piirretä huonetta uudestaan.
    {
    huone2();
    piirraHuone = 0;
    }
    while (piirraHuone == 1 && huoneNumero == 3)  // sama kuin edellä
    {
    huone3();
    piirraHuone = 0;
    }
    while (piirraHuone == 1 && huoneNumero == 4) // sama kuin edellä
    {
    huone4();
    piirraHuone = 0;
    }
    while (piirraHuone == 1 && huoneNumero == 5) // sama kuin edellä
    {
    huone5();
    piirraHuone = 0;
    }
    while (piirraHuone == 1 && huoneNumero == 6) // sama kuin edellä
    {
    huone6();
    piirraHuone = 0;
    }
    while (piirraHuone == 1 && huoneNumero == 7) // sama kuin edellä
    {
    huone7();
    piirraHuone = 0;
    }
    while (piirraHuone == 1 && huoneNumero == 8) // sama kuin edellä
    {
    huone8();
    piirraHuone = 0;
    }
    while (piirraHuone == 1 && huoneNumero == 9) // sama kuin edellä
    {
    huone9();
    piirraHuone = 0;
    }
    while (piirraHuone == 1 && huoneNumero == 10) // sama kuin edellä
    {
    loppuNaytto();
    huoneNumero = 0;
    }
}
