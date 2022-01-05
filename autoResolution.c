void autoresolution(Card arraygame[], Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraydeck[])
{
  int hand = 0;
  int deckDraws = 23;
  int nbCardZeroInGame = 0;
  while (nbCardZeroInGame != 28)
  {
    for (int i = 1; i <= 29; i++)
    {
      if (i <= 10)
      {
        if ((arraylayer4[i - 1].value + 1) == arraygame[hand].value || (arraylayer4[i].value - 1) == arraygame[hand].value)
        {
          replaceHand(arraygame, arraylayer4, &i, &hand);
          toZero(arraygame, arraylayer4, &i);
          nbCardZeroInGame ++;
        }
      }
      else if (i <= 19)
      {
        if (arraylayer4[i - 11].value == 0 && arraylayer4[i -10].value == 0 && ((arraylayer3[i - 11].value + 1) == arraygame[hand].value || (arraylayer3[i - 10].value - 1) == arraygame[hand].value))
        {          
          replaceHand(arraygame, arraylayer3, &i, &hand);
          toZero(arraygame, arraylayer3, &i);
          nbCardZeroInGame ++;
        }
      }
      else if (i <= 25)
      {        
        if (i - 19 == 1 && arraylayer3[0].value == 0 && arraylayer3[1].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))
        {
          replaceHand(arraygame, arraylayer2, &i, &hand);
          toZero(arraygame, arraylayer2, &i);
          nbCardZeroInGame ++;
        }
      }
        else if (i - 19 == 2 && arraylayer3[1].value == 0 && arraylayer3[2].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))
        {
          replaceHand(arraygame, arraylayer2, &i, &hand);
          toZero(arraygame, arraylayer2, &i);
          nbCardZeroInGame ++;
        }
        else if (i - 19 == 3 && arraylayer3[3].value == 0 && arraylayer3[4].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))
        {
          replaceHand(arraygame, arraylayer2, &i, &hand);
          toZero(arraygame, arraylayer2, &i);
          nbCardZeroInGame ++;
        }
        else if (i - 19 == 4 && arraylayer3[4].value == 0 && arraylayer3[5].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))
        {
          replaceHand(arraygame, arraylayer2, &i, &hand);
          toZero(arraygame, arraylayer2, &i);
          nbCardZeroInGame ++;	
        }
        else if (i - 19 == 5 && arraylayer3[6].value == 0 && arraylayer3[7].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))
        {
          replaceHand(arraygame, arraylayer2, &i, &hand);
          toZero(arraygame, arraylayer2, &i);
          nbCardZeroInGame ++;
        }
        else if (i - 19 == 6 && arraylayer3[7].value == 0 && arraylayer3[8].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))
        {
          replaceHand(arraygame, arraylayer2, &i, &hand);
          toZero(arraygame, arraylayer2, &i);
          nbCardZeroInGame ++;
        }
      else if (i <= 28)
      {
        if (i - 25 == 1 && arraylayer2[0].value == 0 && arraylayer2[1].value == 0 && ((arraylayer1[i - 26].value + 1) == arraygame[hand].value || (arraylayer1[i - 26].value - 1) == arraygame[hand].value))
        {
          replaceHand(arraygame, arraylayer1, &i, &hand);
          toZero(arraygame, arraylayer1, &i);
          nbCardZeroInGame ++;
        }
      }
        else if (i - 25 == 2 && arraylayer2[2].value == 0 && arraylayer2[3].value == 0 && ((arraylayer1[i - 26].value + 1) == arraygame[hand].value || (arraylayer1[i - 26].value - 1) == arraygame[hand].value))
        {
          replaceHand(arraygame, arraylayer1, &i, &hand);
          toZero(arraygame, arraylayer1, &i);
          nbCardZeroInGame ++;
        }
        else if (i - 25 == 3 && arraylayer2[4].value == 0 && arraylayer2[5].value == 0 && ((arraylayer1[i - 26].value + 1) == arraygame[hand].value || (arraylayer1[i - 26].value - 1) == arraygame[hand].value))
        {
          replaceHand(arraygame, arraylayer1, &i, &hand);
          toZero(arraygame, arraylayer1, &i);
          nbCardZeroInGame ++;
        }
      else if (i == 29)
      {
        if (deckDraws < 0)
        {
          printf("Perdu");
          exit(0);
        }
        else
        {
          arraygame[hand + 1] = arraydeck[deckDraws];
          hand ++;
          deckDraws --;
        }
      }
    }
  }
  printf("Gagné !");
  exit(0);
}
