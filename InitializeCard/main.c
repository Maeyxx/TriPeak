#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InitializeCard.h"

Card arraycard[51];

int InitializeCard()
/*
Initialise le paquet de carte et incrémente chaque structure de carte dans le tableau arraycard.

*/
{
  int specific_card = 0;
  char symbol = '0';
  for (int i = 1; i <= 4; i++)
  {
    switch( i )
    {
    case 1:
        symbol = 'c';
        break;
    case 2 :
        symbol = 'd';
        break;
    case 3 :
        symbol = 'h';
        break;
    case 4 :
        symbol = 's';
        break;
    }
    for (int a = 1; a <= 13; a++)
    {
      struct card c;
      c.value = a; 
      c.symbol = symbol;
      arraycard[specific_card]=c;
      specific_card += 1;
    }
  }
  return 0;
}

int main(int argc, char const* argv[])
/*
Appel la fonction InitializeCard.

*/
{
  InitializeCard();
	return 0;
}

