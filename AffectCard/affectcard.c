#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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



// Tableau couche 1 à 4
Card arraylayer1[3];
Card arraylayer2[6];
Card arraylayer3[9];
Card arraylayer4[10];

// Tableau pioche
Card arraydeck[24];


void affectcard(arraycard) {
	int x;
	int i;
	int pickcard;

	// Affectation des cartes a la couche 1
	x = 3;
	for (i = 0; i <= x; i++) {
		pickcard = rand() % len(arraycard);
		if (arraycard[&pickcard] != NULL) {
			arraylayer1[i] = arraycard[&pickcard];
			arraycard[&pickcard] = NULL;
		}
		else {
			x++;
		}
	}

	// Affectation des cartes a la couche 2
	x = 6;
	for (i = 0; i <= x; i++) {
		pickcard = rand() % len(arraycard);
		if (arraycard[&pickcard] != NULL) {
			arraylayer2[i] = arraycard[&pickcard];
			arraycard[&pickcard] = NULL;
		}
		else {
			x++;
		}
	}

	// Affectation des cartes a la couche 3
	x = 9;
	for (i = 0; i <= x; i++) {
		pickcard = rand() % len(arraycard);
		if (arraycard[&pickcard] != NULL) {
			arraylayer3[i] = arraycard[&pickcard];
			arraycard[&pickcard] = NULL;
		}
		else {
			x++;
		}
	}

	// Affectation des cartes a la couche 4
	x = 10;
	for (i = 0; i <= x; i++) {
		pickcard = rand() % len(arraycard);
		if (arraycard[&pickcard] != NULL) {
			arraylayer4[i] = arraycard[&pickcard];
			arraycard[&pickcard] = NULL;
		}
		else {
			x++;
		}
	}

	// Affectation des cartes a la pioche
	x = len(arraycard);
	for (i = 0; i <= x; i++) {
		pickcard = rand() % len(arraycard);
		if (arraycard[&pickcard] != NULL) {
			arraydeck[i] = arraycard[&pickcard];
		}
		else {
			x++;
		}
	}
	return arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraydeck;
}



int main(int argc, char* argv[]) {
	srand(time(NULL));
	InitializeCard();
	affectcard(arraycard);
	return 0;
}