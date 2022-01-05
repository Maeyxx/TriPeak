#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __unix__
#include <unistd.h>
#endif



// Structure des cartes
// Card structure
struct card
{
	char symbol;
	// c = Clubs = Trefle | h = Hearts = Coeur | d = Diamonds = Diamand | s = Spades = Pique
	int value;
	// From 1 to 13
};
typedef struct card Card;


// Prototyp of functions
// Prototype des fonctions
// see game.c to know what function do
// Voir le fichier game.c pour connaître ce que fait la fonction ainsi que ses paramètres

int InitializeCard();
void shuffle();
void AttribueCards();
void game();
void restart();
void generateGame();
void saveGame();
void toZero(Card arraygame[], Card layer[], int* pointeurcardplay);
void welcome();
void visual(Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraygame[], int* pointeurx);
void askingCardPlay();
void replaceHand(Card arraygame[], Card layer[], int* pointeurcardplay, int* pointeurx);
void goodbye();