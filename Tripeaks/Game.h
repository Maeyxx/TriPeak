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

// Prototype des fonctions
// Prototyp of functions
int InitializeCard();
void shuffle();
void AttribueCards();
void game();
void restart();
void generateGame();
void saveGame();
void tozero(Card arraygame[], Card layer[], int* pointeurcardplay);
void welcome();
void visual(Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraygame[], int* pointeurx);
void askingcardplay();
void replacehand(Card arraygame[], Card layer[], int* pointeurcardplay, int* pointeurx);
void goodbye();