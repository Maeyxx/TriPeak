#include "Game.h"

int i;

int InitializeCard(Card arraycard[])
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
      arraycard[specific_card].value=a;
      arraycard[specific_card].symbol=symbol;
      printf("%c%d\n", arraycard[specific_card].symbol , arraycard[specific_card].value);
      specific_card ++;
      //if (specific_card > sizeof(arraycard)/sizeof(Card))
      //{
	  //    exit(-1);
      //}
    }
  }
  return 0;
}

void shuffle(Card arraycard[])
{
    srand(time(0));
    for (int i = 0; i <= 51; i++) 
    {
      int j = rand() % 51;
      struct card t = arraycard[i];
      arraycard[i] = arraycard[j];
      arraycard[j] = t;
    }
}

void AttribueCards(Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraydeck[], Card arraycard[])
{
  printf("Deck----------\n");
  for (int a = 0; a <= 23; a++)
  {
      arraydeck[a] = arraycard[a];
      printf("%c%d\n", arraydeck[a].symbol, arraydeck[a].value);
  }
  printf("LAYER1----------\n");
  int compteur = 0;
  for (int a = 24; a <= 26; a++)
  {
      arraylayer1[compteur] = arraycard[a];
      printf("%c%d\n", arraylayer1[compteur].symbol, arraylayer1[compteur].value);
      compteur ++;
  }
  printf("LAYER2----------\n");
  compteur = 0;
  for (int a = 27; a <= 32; a++)
  {
      arraylayer2[compteur] = arraycard[a];
      printf("%c%d\n", arraylayer2[compteur].symbol, arraylayer2[compteur].value);
      compteur ++;
  }
  printf("LAYER3----------\n");
  compteur = 0;
  for (int a = 33; a <= 41; a++)
  {
      arraylayer3[compteur] = arraycard[a];
      printf("%c%d\n", arraylayer3[compteur].symbol, arraylayer3[compteur].value);
      compteur ++;
  }
  printf("LAYER4----------\n");
  compteur = 0;
  for (int a = 42; a <= 51; a++)
  {
      arraylayer4[compteur] = arraycard[a];
      printf("%c%d\n", arraylayer4[compteur].symbol, arraylayer4[compteur].value);
      compteur ++;
  }
}

void game(Card arraygame[], Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraydeck[]) {
	int x = 0;
	int m = 23;
	int choicelayer;
	char* loop = "enter";
	arraygame[x] = arraydeck[m];
	m--;
	while (loop == "enter") {
		printf("       %d%c             %d%c           %d%c\n", arraylayer1[0].value, arraylayer1[0].symbol, arraylayer1[1].value, arraylayer1[1].symbol, arraylayer1[2].value, arraylayer1[2].symbol);
		printf("     %d%c %d%c       %d%c %d%c      %d%c %d%c\n", arraylayer2[0].value, arraylayer2[0].symbol, arraylayer2[1].value, arraylayer2[1].symbol, arraylayer2[2].value, arraylayer2[2].symbol, arraylayer2[3].value, arraylayer2[3].symbol, arraylayer2[4].value, arraylayer2[4].symbol, arraylayer2[5].value, arraylayer2[5].symbol);
		printf("    %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c\n", arraylayer3[0].value, arraylayer3[0].symbol, arraylayer3[1].value, arraylayer3[1].symbol, arraylayer3[2].value, arraylayer3[2].symbol, arraylayer3[3].value, arraylayer3[3].symbol, arraylayer3[4].value, arraylayer3[4].symbol, arraylayer3[5].value, arraylayer3[5].symbol, arraylayer3[6].value, arraylayer3[6].symbol, arraylayer3[7].value, arraylayer3[7].symbol, arraylayer3[8].value, arraylayer3[8].symbol);
		printf("   %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c\n", arraylayer4[0].value, arraylayer4[0].symbol, arraylayer4[1].value, arraylayer4[1].symbol, arraylayer4[2].value, arraylayer4[2].symbol, arraylayer4[3].value, arraylayer4[3].symbol, arraylayer4[4].value, arraylayer4[4].symbol, arraylayer4[5].value, arraylayer4[5].symbol, arraylayer4[6].value, arraylayer4[6].symbol, arraylayer4[7].value, arraylayer4[7].symbol, arraylayer4[8].value, arraylayer4[8].symbol, arraylayer4[9].value, arraylayer4[9].symbol);
		printf("jeu : %d%c \n", arraygame[x].value, arraygame[x].symbol);
		int cardplay = 0;
		printf("Choissiez sur quel couche interagir (couche 1 = couche haute; couche 4 = couche basse; 0 = pioche; 5 = fin du jeu) : \n");
		scanf("%d", &choicelayer);
		switch (choicelayer) {
		case 0:
			arraygame[x + 1] = arraydeck[m];
			x++;
			m--;
			break;
		case 1:
			printf("Quel carte jouer (1 a 3) ? \n");
			scanf("%d", &cardplay);
			if (cardplay == 1 && arraylayer2[0].value == 0 && arraylayer2[1].value == 0 && ((arraylayer1[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer1[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer1[cardplay - 1];
				arraylayer1[cardplay - 1].value = 0;
				x++;
			}
			else if (cardplay == 2 && arraylayer2[2].value == 0 && arraylayer2[3].value == 0 && ((arraylayer1[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer1[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer1[cardplay - 1];
				arraylayer1[cardplay - 1].value = 0;
				x++;
			}
			else if (cardplay == 3 && arraylayer2[4].value == 0 && arraylayer2[5].value == 0 && ((arraylayer1[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer1[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer1[cardplay - 1];
				arraylayer1[cardplay - 1].value = 0;
				x++;
			}
			else {
				printf("Choix invalide\n");
			}
			break;
		case 2:
			printf("Quel carte jouer (1 a 6) ? \n");
			scanf("%d", &cardplay);
			if (cardplay == 1 && arraylayer3[0].value == 0 && arraylayer3[1].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer2[cardplay - 1];
				arraylayer2[cardplay - 1].value = 0;
				x++;
			}
			else if (cardplay == 2 && arraylayer3[1].value == 0 && arraylayer3[2].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer2[cardplay - 1];
				arraylayer2[cardplay - 1].value = 0;
				x++;
			}
			else if (cardplay == 3 && arraylayer3[3].value == 0 && arraylayer3[4].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer2[cardplay - 1];
				arraylayer2[cardplay - 1].value = 0;
				x++;
			}
			else if (cardplay == 4 && arraylayer3[4].value == 0 && arraylayer3[5].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer2[cardplay - 1];
				arraylayer2[cardplay - 1].value = 0;
				x++;
			}
			else if (cardplay == 5 && arraylayer3[6].value == 0 && arraylayer3[7].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer2[cardplay - 1];
				arraylayer2[cardplay - 1].value = 0;
				x++;
			}
			else if (cardplay == 6 && arraylayer3[7].value == 0 && arraylayer3[8].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer2[cardplay - 1];
				arraylayer4[cardplay - 1].value = 0;
				x++;
			}
			else {
				printf("Choix invalide\n");
			}
			break;
		case 3:
			printf("Quel carte jouer (1 a 9) ? \n");
			scanf("%d", &cardplay);
			if (arraylayer4[cardplay - 1].value == 0 && arraylayer4[cardplay].value == 0 && ((arraylayer3[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer3[cardplay - 1].value - 1) == arraygame[x].value)) {
				arraygame[x + 1] = arraylayer3[cardplay - 1];
				arraylayer3[cardplay - 1].value = 0;
				x++;
			}
			else {
				printf("Choix invalide\n");
			}
			break;
		case 4:
			printf("Quel carte jouer (1 a 10) ? \n");
			scanf("%d", &cardplay);
			if ((arraylayer4[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer4[cardplay - 1].value - 1) == arraygame[x].value) {
				arraygame[x + 1] = arraylayer4[cardplay - 1];
				arraylayer4[cardplay - 1].value = 0;
				x++;
			}
			else {
				printf("Choix invalide\n");
			}
			break;
		case 5:
			loop = "leave";
			break;
		default:
			break;
		}
	}
}
