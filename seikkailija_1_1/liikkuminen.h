void liikkuminen()
{
    if (oikea == HIGH ) // jos oikea painonappi on painettuna, niin pelaaja liikkuu oikealle
    {
        if (huoneNumero != 6 && pelaajanX < 289)  // if-lause suoritetaan, jos pelaaja ei ole liian oikealla (eli pelaaja ei voi kulkea piirrettyjen seinien läpi)
        {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX = pelaajanX + SPEED, pelaajanY, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan x-koordinaattiin lisätään SPEED-muuttujan arvo
        }
        else // jos pelaaja on liian oikealla, else-lause suoritetaan
        {
            Serial.print("Liian oikealla"); // printataan sarjamonitorille tieto, että pelaaja on liian oikealla
        }
    }
    
    if (ylos == HIGH) // jos ylös-painonappi on painettuna, niin pelaaja liikkuu ylös
    {
        if (huoneNumero != 6 && pelaajanY > 31 ) // if-lause suoritetaan, jos pelaaja ei ole liian ylhäällä (eli pelaaja ei voi kulkea piirrettyjen seinien läpi)
        {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX, pelaajanY = pelaajanY -SPEED, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan y-koordinaattista vähennetään SPEED-muuttujan arvo
        }
        else // jos pelaaja on liian ylhäällä, else-lause suoritetaan
        {
            Serial.print("Liian ylhäällä");
        }
    }
    
    if (vasen == HIGH) // jos vasen painonappi on painettuna, niin pelaaja liikkuu vasemmalle
    {
        if (pelaajanX > 31) // if-lause suoritetaan, jos pelaaja ei ole liian vasemmalla (eli pelaaja ei voi kulkea piirrettyjen seinien läpi)
        {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX = pelaajanX - SPEED, pelaajanY, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan x-koordinaattista vähennetään SPEED-muuttujan arvo
        }
        else // jos pelaaja on liian vasemmalla, else-lause suoritetaan
        {
            Serial.print("Liian vasemmalla");
        }
    }
    
    if (alas == HIGH) // jos alas-painonappi on painettuna, niin pelaaja liikkuu alas
    {
        if (huoneNumero != 8 && huoneNumero != 6 && pelaajanY < 209)// if-lause suoritetaan, jos pelaaja ei ole liian alhaalla (eli pelaaja ei voi kulkea piirrettyjen seinien läpi)
        {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX, pelaajanY = pelaajanY + SPEED, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan y-koordinaattiin lisätään SPEED-muuttujan arvo
        }
        else // jos pelaaja on liian alhaalla, else-lause suoritetaan
        {
            Serial.print("Liian alhaalla");
        }
    }


    /* Estetään pelaajan kulkeminen lattialle piirretyn kombinaation päälle huoneessa 8 */


    if (alas == HIGH) // jos alas-painonappi on painettuna, niin pelaaja liikkuu alas
    {
        if (huoneNumero == 8 && pelaajanY < 109)// Estetään pelaajan kulkeminen puzzle tehtävän päälle huoneessa 8
        {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX, pelaajanY = pelaajanY + SPEED, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan y-koordinaattiin lisätään SPEED-muuttujan arvo
        }
        else // jos pelaaja on liian alhaalla, else-lause suoritetaan
        {
            Serial.print("Liian alhaalla");
        }
    }


    /* Käynnistetään kombinaatiolukko puzzle */

    
    if (pelaajanX >= 288 && pelaajanY > 92 && pelaajanY < 148 && koodi == false && huoneNumero == 4)// Käynnistetään kombinaatiolukko puzzle
    {
    kombinaatioLukko();
    myGLCD.fillCircle(pelaajanX, pelaajanY, 10);
    }


    /* Kirjoitetaan näytölle, että pelaaja voi puhua welholle kun pelaaja on tarpeeksi lähellä welhoa, ja teksti katoaa, kun pelaaja poistuu welhon läheisyydestä */


    if(huoneNumero == 6 && pelaajanX > 250 && pelaajanX < 289 && pelaajanY > 130 && pelaajanY < 200) // jos pelaaja on tarpeeksi lähellä welhoa, asetetaan welhonLahella = true, muutoin false
    {
      welhonLahella = true;
    }
    else 
    {
      welhonLahella = false;
    }

    if (welhonLahella == true && kirjoita == true) // jos pelaaja on welhon lähellä ja kirjoita == true, niin näytölle kirjoitetaan että welholle voi puhua
    {
      myGLCD.setBackColor(TAUSTAVARI);
      myGLCD.setColor(255,255,255);
      myGLCD.print("Paina X puhuaksesi Welholle", CENTER, 50, 0);
      kirjoita = false; // asetetaan nyt kirjoita == false, jotta kirjoitetun tekstin pyyhkiminen on helppoa
    }
    if (welhonLahella == false && kirjoita == false) // tämä if lause tarkastaa, poistuuko pelaaja welhon läheisyydestä. Jos poistuu, niin if-lause pyyhkii tekstin pois.
    {
      myGLCD.setColor(TAUSTAVARI);
      myGLCD.fillRect(30, 40, 280, 60);
      kirjoita = true; // asetetaan kirjoita == true, jotta tekstin voi kirjoittaa uudelleen kun pelaaja lähestyy welhoa.
    }


    /* Welholle puhuminen */

    
    if(huoneNumero == 6 && pelaajanX > 250 && pelaajanX < 289 && pelaajanY > 130 && pelaajanY < 200 && tutki == HIGH)   // Jos pelaaja on welhon lähellä ja painaa X-näppäintä, niin suoritetaan welhoTxt()                                                                                                          
    {
    welhoTxt();
    }


    /* Estetään pelaajan kulkeminen Welhon päälle koodaamalla rajat, joiden yli pelaaja ei pääse */
    

    if (oikea == HIGH ) // jos oikea painonappi on painettuna, niin pelaaja liikkuu oikealle
    {
        if (huoneNumero == 6 && pelaajanX < 289)  // Rajataan missä koordinaateissa pelaaja voi liikkua huoneessa 6
        {
            if (pelaajanX < 257 || pelaajanX > 260) //Alue johon pelaaja ei pääse.
            {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX = pelaajanX + SPEED, pelaajanY, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan x-koordinaattiin lisätään SPEED-muuttujan arvo
            }
        
            else if (pelaajanY > 188 || pelaajanY < 140) // rajataan alue jossa pelaaja pääsee liikkumaan.
            {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX = pelaajanX + SPEED, pelaajanY, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan x-koordinaattiin lisätään SPEED-muuttujan arvo
            }
        
            else // jos pelaaja on liian oikealla, else-lause suoritetaan
            {
            Serial.print("Liian oikealla"); // printataan sarjamonitorille tieto, että pelaaja on liian oikealla
            }
        }
    }
    if (alas == HIGH) // jos alas-painonappi on painettuna, niin pelaaja liikkuu alas
    {
        if (huoneNumero == 6 && pelaajanY < 209)// Estetään pelaajan kulkeminen puzzle tehtävän päälle huoneessa 8
        {
            if (pelaajanY < 140 || pelaajanY > 143)
            {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX, pelaajanY = pelaajanY + SPEED, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan y-koordinaattiin lisätään SPEED-muuttujan arvo
            }

            else if (pelaajanX > 285 || pelaajanX < 257)
            {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX, pelaajanY = pelaajanY + SPEED, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan x-koordinaattiin lisätään SPEED-muuttujan arvo
            }
            else // jos pelaaja on liian alhaalla, else-lause suoritetaan
            {
            Serial.print("Liian alhaalla");
            }
        }
    }

    if (ylos == HIGH) // jos ylös-painonappi on painettuna, niin pelaaja liikkuu ylös
    {
        if (huoneNumero == 6 && pelaajanY > 31) // if-lause suoritetaan, jos pelaaja ei ole liian ylhäällä (eli pelaaja ei voi kulkea piirrettyjen seinien läpi)
        {
            if (pelaajanY > 188 || pelaajanY < 185)
            {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX, pelaajanY = pelaajanY -SPEED, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan y-koordinaattista vähennetään SPEED-muuttujan arvo
            }
            else if (pelaajanX > 285 || pelaajanX < 257)
            {
            myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
            myGLCD.fillCircle(pelaajanX, pelaajanY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
            myGLCD.setColor(PELAAJANVARI);  // asetetaan väriksi pelaajan väri
            myGLCD.fillCircle(pelaajanX, pelaajanY = pelaajanY -SPEED, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan y-koordinaattista vähennetään SPEED-muuttujan arvo
            }
            else // jos pelaaja on liian ylhäällä, else-lause suoritetaan
            {
            Serial.print("Liian ylhäällä");
            }
        }
    }
}
