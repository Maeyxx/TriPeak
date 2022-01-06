void autoresolution(Card arraygame[], Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraydeck[])
{
  int hand = 0;
  int deckDraws = 23;
  int nbCardZeroInGame = 0;
  int x = 0;
  int i = 0;
  arraygame[hand] = arraydeck[deckDraws];
	deckDraws--;
  while (nbCardZeroInGame != 29)
  {
    for (i = 1; i <= 29; i++)
    {
      if (i <= 10)
      {
        x = i;
        if (((arraylayer4[i - 1].value + 1) == arraygame[hand].value || (arraylayer4[i - 1].value - 1) == (arraygame[hand].value)) && arraylayer4[i - 1].value != 0)
        {
          printf("\nI%d\n", i);
          replaceHand(arraygame, arraylayer4, &x, &hand);
          toZero(arraygame, arraylayer4, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
      }
      else if (i <= 19)
      {
        x = i - 10;
        if ((arraylayer4[i - 11].value == 0 && arraylayer4[i -10].value == 0 && ((arraylayer3[i - 11].value + 1) == arraygame[hand].value || (arraylayer3[i - 11].value - 1) == arraygame[hand].value)) && arraylayer3[i -11].value != 0)
        {          
          printf("\nI%d\n", i);
          replaceHand(arraygame, arraylayer3, &x, &hand);
          toZero(arraygame, arraylayer3, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
      }
      else if (i <= 25)
      {        
        x = i - 19;
        if ((x == 1 && arraylayer3[0].value == 0 && arraylayer3[1].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value)) && arraylayer2[i-20].value != 0)
        {
          replaceHand(arraygame, arraylayer2, &x, &hand);
          toZero(arraygame, arraylayer2, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
        else if ((x == 2 && arraylayer3[1].value == 0 && arraylayer3[2].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))&& arraylayer2[i-20].value != 0)
        {
          replaceHand(arraygame, arraylayer2, &x, &hand);
          toZero(arraygame, arraylayer2, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
        else if ((x == 3 && arraylayer3[3].value == 0 && arraylayer3[4].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))&& arraylayer2[i-20].value != 0)
        {
          replaceHand(arraygame, arraylayer2, &x, &hand);
          toZero(arraygame, arraylayer2, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
        else if ((x == 4 && arraylayer3[4].value == 0 && arraylayer3[5].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))&& arraylayer2[i-20].value != 0)
        {
          replaceHand(arraygame, arraylayer2, &x, &hand);
          toZero(arraygame, arraylayer2, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
        else if ((x == 5 && arraylayer3[6].value == 0 && arraylayer3[7].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))&& arraylayer2[i-20].value != 0)
        {
          replaceHand(arraygame, arraylayer2, &x, &hand);
          toZero(arraygame, arraylayer2, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
        else if ((x == 6 && arraylayer3[7].value == 0 && arraylayer3[8].value == 0 && ((arraylayer2[i - 20].value + 1) == arraygame[hand].value || (arraylayer2[i - 20].value - 1) == arraygame[hand].value))&& arraylayer2[i-20].value != 0)
        {
          replaceHand(arraygame, arraylayer2, &x, &hand);
          toZero(arraygame, arraylayer2, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
      }
      else if (i <= 28)
      {
        x = i - 25;
        if ((x == 1 && arraylayer2[0].value == 0 && arraylayer2[1].value == 0 && ((arraylayer1[i - 26].value + 1) == arraygame[hand].value || (arraylayer1[i - 26].value - 1) == arraygame[hand].value))&& arraylayer1[i-26].value != 0)
        {
          replaceHand(arraygame, arraylayer1, &x, &hand);
          toZero(arraygame, arraylayer1, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
        else if ((x == 2 && arraylayer2[2].value == 0 && arraylayer2[3].value == 0 && ((arraylayer1[i - 26].value + 1) == arraygame[hand].value || (arraylayer1[i - 26].value - 1) == arraygame[hand].value))&& arraylayer1[i-26].value != 0)
        {
          replaceHand(arraygame, arraylayer1, &x, &hand);
          toZero(arraygame, arraylayer1, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
        else if ((x == 3 && arraylayer2[4].value == 0 && arraylayer2[5].value == 0 && ((arraylayer1[i - 26].value + 1) == arraygame[hand].value || (arraylayer1[i - 26].value - 1) == arraygame[hand].value))&& arraylayer1[i-26].value != 0)
        {
          replaceHand(arraygame, arraylayer1, &x, &hand);
          toZero(arraygame, arraylayer1, &x);
          nbCardZeroInGame ++;
          i = 1;
          break;
        }
      }
      else if (i == 29)
      {
        if (nbCardZeroInGame == 28)
        {
          visual(arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraygame, &hand);
          printf("gégé weppé");
          exit(0);
        }
        else if (deckDraws < 0)
        {
          visual(arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraygame, &hand);
          printf("Perdu");
          exit(0);
        }
        else
        {
          arraygame[hand + 1] = arraydeck[deckDraws];
          hand ++;
          deckDraws --;
          i = 1;
          break;
        }
      }
    }
  }
}
