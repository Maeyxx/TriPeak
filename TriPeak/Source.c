#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../InitializeCard/InitializeCard.h"

Card arraycard[52];
int pickcard;


int InitializeCard()
/*
Initialise le paquet de carte et incrémente chaque structure de carte dans le tableau arraycard.

*/
{
	int specific_card = 0;
	char symbol = '0';
	for (int i = 1; i <= 4; i++)
	{
		switch (i)
		{
		case 1:
			symbol = 'c';
			break;
		case 2:
			symbol = 'd';
			break;
		case 3:
			symbol = 'h';
			break;
		case 4:
			symbol = 's';
			break;
		}
		for (int a = 1; a <= 13; a++)
		{
			struct card c;
			c.value = a;
			c.symbol = symbol;
			arraycard[specific_card] = c;
			specific_card += 1;
		}
	}
	return 0;
}


int i;

void affectcard(Card arraylayer[], int y) {
	int j = 0;
	// Affectation des cartes a un layer
	for (i = 0; i <= y; i++) {
		pickcard = rand() % 52;
		if (arraycard[pickcard].value != 0) {
			arraylayer[i - j] = arraycard[pickcard];
			arraycard[pickcard].value = 0;
		}
		else {
			j++;
			y++;
		}
	}
}

void affectcarddeck(Card arraydeck[]) {
	int h = 0;
	int g = 23;
	// Affectation des cartes a la pioche
	for (i = 0; i <= g; i++) {
		pickcard = rand() % 52;
		if (arraycard[pickcard].value != 0) {
			arraydeck[i - h] = arraycard[pickcard];
			arraycard[pickcard].value = 0;
		}
		else {
			h++;
			g++;
		}
	}
}


void startGame() {
	/*char answer;
	printf("Hi, welcome on TriPeak game\n");
	printf("Would you like play a new game ?");
	scanf("%c", answer);

	switch (answer)
	{
	case 'y':
		printf("ok");
		break;
	case 'n':

		break;
	default:
		break;
	}
	*/
}


int main(int argc, char* argv[]) {
	// Initialize four array
	Card arraylayer1[3];
	Card arraylayer2[6];
	Card arraylayer3[9];
	Card arraylayer4[10];


	// Reserv 
	Card arraydeck[24];
	srand(time(NULL));
	InitializeCard();
	affectcard(arraylayer1, 2, pickcard);
	affectcard(arraylayer2, 5, pickcard);
	affectcard(arraylayer3, 8, pickcard);
	affectcard(arraylayer4, 9, pickcard);
	affectcarddeck(arraycard, pickcard);
	startGame();

	/*
	*
	* Loop to show all value sorted
	*
	*/

	for (int i = 0; i < 3; i++) {
		printf("%c%d \n", arraylayer1[i].symbol, arraylayer1[i].value);
	}
	for (int i = 0; i < 6; i++) {
		printf("%c%d \n", arraylayer2[i].symbol, arraylayer2[i].value);
	}
	for (int i = 0; i < 9; i++) {
		printf("%c%d \n", arraylayer3[i].symbol, arraylayer3[i].value);
	}
	for (int i = 0; i < 10; i++) {
		printf("%c%d \n", arraylayer4[i].symbol, arraylayer4[i].value);
	}

	return 0;
}







