#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int pickcard;
int i;

void affectcard(Card arraylayer[], int y) {
	int j = 0;
	// Affectation des cartes a un layer
	for (i = 0; i <= y; i++) {
		pickcard = rand() % (sizeof(arraycard) / sizeof(Card));
		if (arraycard[pickcard].value != 0) {
			arraylayer[i-j] = arraycard[pickcard];
			arraycard[pickcard].value = 0;
		}
		else {
			j++;
			y++;
		}
	}
}

void affectcarddeck (Card arraydeck[]){
	int h = 0;
	int g = (sizeof(arraydeck) / sizeof(Card));
	// Affectation des cartes a la pioche
	for (i = 0; i <= g; i++) {
		pickcard = rand() % (sizeof(arraycard) / sizeof(Card));
		if (arraycard[pickcard].value != 0) {
			arraydeck[i-h] = arraycard[pickcard];
			arraycard[pickcard].value = 0;
		}
		else {
			h++;
			g++;
		}
	}
}

int main(int argc, char* argv[]) {
	// Tableau couche 1 à 4
	Card arraylayer1[3];
	Card arraylayer2[6];
	Card arraylayer3[9];
	Card arraylayer4[10];
	// Tableau pioche
	Card arraydeck[24];
	srand(time(NULL));
	InitializeCard();
	affectcard(arraylayer1, 2);
	affectcard(arraylayer2, 5);
	affectcard(arraylayer3, 8);
	affectcard(arraylayer4, 9);
	affectcarddeck(arraycard);
	return 0;
}
