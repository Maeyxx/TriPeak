#include "Game.h"

int main(int argc, char* argv[]) {

	// Packet de cartes entier
	Card arraycard[52];

	// Carte tirer pour le triage
	int pickcard;

	// Tableau couche 1 à 4
	Card arraylayer1[3];
	Card arraylayer2[6];
	Card arraylayer3[9];
	Card arraylayer4[10];

	// Tableau pioche
	Card arraydeck[24];
	Card arraygame[52];

	// Initialisation du random
	srand(time(NULL));

	// Fonction d'initialisation des cartes
	InitializeCard(arraycard);

	// Fonction de mélange des cartes
	shuffle(arraycard);

	// Fonction attribution des cartes au différent layer
	AttribueCards(arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraydeck, arraycard);

	// Fonction de jeu
	game(arraygame, arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraydeck);

	return 0;
}