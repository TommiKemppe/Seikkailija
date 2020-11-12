void siirtyminenHuoneeseen()
{
    if (pelaajanX > 135 && pelaajanX < 185 && pelaajanY <= 31 && ylaOvi == true)  //Jos pelaajan koordinaatit ovat yläoven lähellä ja ylaOvi == true, niin pelaaja siirtyy seuraavaan huoneeseen
    {
        huoneNumero++;  // lisätään huonenumeroon yksi - tämä muttuja kertoo mikä huone piirretään. Ylöspäin mentäessä huonenumero kasvaa yhdellä
        pelaajanX = 160;  // asetetaan pelaajan koordinaatit niin, että seuraavassa huoneessa näyttää siltä, että pelaaja on kulkenut ovesta sisään uuteen huoneeseen
        pelaajanY = 200;
        
        piirraHuone = 1; // asetetaan piirraHuone = 1, jolloin jokin ylläolevista while-loopeista piirtää haluamamme huoneen
    }

    if (pelaajanX > 135 && pelaajanX < 185 && pelaajanY >= 208 && alaOvi == true)  //Jos pelaajan koordinaatit ovat alaoven lähellä ja alaOvi == true, niin pelaaja siirtyy seuraavaan huoneeseen
    {
        huoneNumero--;  // vähennetään huonenumerosta yksi. alaspäin mentäessä huonenumero pienenee yhdellä

        pelaajanX = 160;  // asetetaan pelaajan koordinaatit niin, että seuraavassa huoneessa näyttää siltä, että pelaaja on kulkenut ovesta sisään uuteen huoneeseen
        pelaajanY = 40;
        
        piirraHuone = 1;  // asetetaan piirraHuone = 1, jolloin jokin ylläolevista while-loopeista piirtää haluamamme huoneen
    }

    if (pelaajanX >= 288 && pelaajanY > 95 && pelaajanY < 145 && oikeaOvi == true) //Jos pelaajan koordinaatit ovat oikean oven lähellä ja oikeaOvi == true, niin pelaaja siirtyy seuraavaan huoneeseen
    {
        huoneNumero = huoneNumero + 3;  // nyt jos meillä on 9 huonetta eli 3x3 pelikentällä, niin oikealle siirryttäessä huonenumero kasvaa kolmella. 

        pelaajanX = 40;  // asetetaan pelaajan koordinaatit niin, että seuraavassa huoneessa näyttää siltä, että pelaaja on kulkenut ovesta sisään uuteen huoneeseen
        pelaajanY = 120;
        
        piirraHuone = 1;  // asetetaan piirraHuone = 1, jolloin jokin ylläolevista while-loopeista piirtää haluamamme huoneen
    }

    if (pelaajanX <= 31 && pelaajanY > 95 && pelaajanY < 145 && vasenOvi == true)  //Jos pelaajan koordinaatit ovat vasemman oven lähellä ja vasenOvi == true, niin pelaaja siirtyy seuraavaan huoneeseen
    {
        huoneNumero = huoneNumero - 3;  // vastoin kuin oikealle siirryttäessä kun huonenumeroon lisättiin 3, niin luonnollisesti vasemmalle siirryttäessä huonenumero pienenee kolmella

        pelaajanX = 280;  // asetetaan pelaajan koordinaatit niin, että seuraavassa huoneessa näyttää siltä, että pelaaja on kulkenut ovesta sisään uuteen huoneeseen
        pelaajanY = 120;
        
        piirraHuone = 1;  // asetetaan piirraHuone = 1, jolloin jokin ylläolevista while-loopeista piirtää haluamamme huoneen
    }
}
