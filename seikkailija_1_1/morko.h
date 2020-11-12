void morko() // funktio mörön piirtämiseen ja mörköön törmäämiseen
{
    if(morkoOikea  == true && huoneNumero == 9) // jos morkoOikea == true, mörkö liikkuu oikealle
    {
        myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
        myGLCD.fillCircle(moronX, moronY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
        myGLCD.setColor(0,0,0);  // asetetaan väriksi pelaajan väri
        myGLCD.fillCircle(moronX = moronX + 3, moronY, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan y-koordinaattiin lisätään SPEED-muuttujan arvo
    }
    if(moronX > 270) // jos mörkö liikkuu näytön oikeaan reunaan, niin asetetaan morkoOikea = false, jolloin mörkö vaihtaa suuntaa
    {
    morkoOikea = false;
    }
    if(morkoOikea  == false && huoneNumero == 9) // jos morkoOikea == false, mörkö liikkuu vasemmalle
    {
    myGLCD.setColor(TAUSTAVARI);  // asetetaan väriksi taustaväri
    myGLCD.fillCircle(moronX, moronY, 10);  //täytetään pelaajan vanha koordinaatti taustavärillä
    myGLCD.setColor(0,0,0);  // asetetaan väriksi pelaajan väri
    myGLCD.fillCircle(moronX = moronX - 3, moronY, 10);  // täytetään pelaajan uusi koordinaatti pelaajan värillä, eli pelaajan y-koordinaattiin lisätään SPEED-muuttujan arvo   
    }
    if(moronX < 40)
    {
    morkoOikea = true; // jos mörkö liikkuu näytön vasempaan reunaan, niin asetetaan morkoOikea = true, jolloin mörkö vaihtaa suuntaa
    }
    osuma = moronX - pelaajanX;          //Tarkistaa moron ja pelaajan törmäämisen
    osuma1 = moronY - pelaajanY;
    osuma2 = pelaajanX - moronX;
    osuma3 = pelaajanY - moronY;
    
    if (huoneNumero == 9 && osuma <= 15 && osuma1 <= 15 && osuma2 <= 15 && osuma3 <= 15)       //Jos pelaaja törmää mörköön, niin tulostetaan hävionäyttö
    {
    havioNaytto();
    huoneNumero = 0;
    piirraHuone = 1;   
    }
}
