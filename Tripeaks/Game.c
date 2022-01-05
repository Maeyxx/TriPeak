#include "Game.h"


/*
  > Changed from operating system
  Fonction pour nettoyer le terminal
  clear terminal function
*/
void clearInterface()
{
#ifdef _WIN32	
	system("cls");
#endif
#ifdef __unix__
	system("clear");
#endif
}


/*
  > Changed from operating system
  Fonction pour prendre en pause le terminal
  pause terminal function
*/
void sleeping(int time)
{
#ifdef __unix__
	sleep(time);
#endif
#ifdef _WIN32
	Sleep(time * 1000);
#endif
}

int InitializeCard(Card arraycard[])
/*
Initialise le paquet de carte et incr�mente chaque structure de carte dans le tableau arraycard.
Initialize the card package and increment each card structure in the arraycard array.

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
			arraycard[specific_card].value = a;
			arraycard[specific_card].symbol = symbol;
			specific_card++;
			if (specific_card > 52)
			{
				exit(-1);
			}
		}
	}
	return 0;
}

/*
Fonction de melange des cartes
Card shuffle function

*/
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

/*
  Fonction attribution des cartes au different layer
  Assignment of cards to the different layer function
*/
void AttribueCards(Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraydeck[], Card arraycard[])
{
	int compteur = 0;
	for (int a = 0; a <= 23; a++)
	{
		arraydeck[a] = arraycard[a];
	}
	for (int a = 24; a <= 26; a++)
	{
		arraylayer1[compteur] = arraycard[a];
		compteur++;
	}
	compteur = 0;
	for (int a = 27; a <= 32; a++)
	{
		arraylayer2[compteur] = arraycard[a];
		compteur++;
	}
	compteur = 0;
	for (int a = 33; a <= 41; a++)
	{
		arraylayer3[compteur] = arraycard[a];
		compteur++;
	}
	compteur = 0;
	for (int a = 42; a <= 51; a++)
	{
		arraylayer4[compteur] = arraycard[a];
		compteur++;
	}
}

/*
  Fonction de jeu
  Game function
*/
void game(Card arraygame[], Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraydeck[]) {
	int cardplay = 0;
	int* pointeurcardplay = &cardplay;
	int x = 0;
	int* pointeurx = &cardplay;
	int m = 23;
	int* pointeurm = &m;
	int plays = 0;
	int* pointeurplays = &plays;
	int choicemenu;
	arraygame[x] = arraydeck[m];
	m--;
	welcome();
	sleeping(3);
	while (1) {
		plays++;
		clearInterface();
		visual(arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraygame, &x);
		scanf("%d", &choicemenu);
		switch (choicemenu) {
		case 0:
			if (m < 0) {
				printf("\n Plus de carte dans la pioches \n");
			}
			else {
				arraygame[x + 1] = arraydeck[m];
				x++;
				m--;
			}
			break;
		case 1:
			printf("\nQuel carte jouer (1 a 3) : ");
			askingCardPlay(&cardplay);
			if (cardplay == 1 && arraylayer2[0].value == 0 && arraylayer2[1].value == 0 && ((arraylayer1[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer1[cardplay - 1].value - 1) == arraygame[x].value)) {
				replaceHand(arraygame, arraylayer1, &cardplay, &x);
				toZero(arraygame, arraylayer1, &cardplay);
			}
			else if (cardplay == 2 && arraylayer2[2].value == 0 && arraylayer2[3].value == 0 && ((arraylayer1[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer1[cardplay - 1].value - 1) == arraygame[x].value)) {
				replaceHand(arraygame, arraylayer1, &cardplay, &x);
				toZero(arraygame, arraylayer1, &cardplay);
			}
			else if (cardplay == 3 && arraylayer2[4].value == 0 && arraylayer2[5].value == 0 && ((arraylayer1[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer1[cardplay - 1].value - 1) == arraygame[x].value)) {
				replaceHand(arraygame, arraylayer1, &cardplay, &x);
				toZero(arraygame, arraylayer1, &cardplay);
			}
			else {
				printf("Choix invalide\n");
			}
			break;
		case 2:
			printf("\nQuel carte jouer (1 a 6) : ");
			askingCardPlay(&cardplay);
			if (cardplay == 1 && arraylayer3[0].value == 0 && arraylayer3[1].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				replaceHand(arraygame, arraylayer2, &cardplay, &x);
				toZero(arraygame, arraylayer2, &cardplay);
			}
			else if (cardplay == 2 && arraylayer3[1].value == 0 && arraylayer3[2].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				replaceHand(arraygame, arraylayer2, &cardplay, &x);
				toZero(arraygame, arraylayer2, &cardplay);
			}
			else if (cardplay == 3 && arraylayer3[3].value == 0 && arraylayer3[4].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				replaceHand(arraygame, arraylayer2, &cardplay, &x);
				toZero(arraygame, arraylayer2, &cardplay);
			}
			else if (cardplay == 4 && arraylayer3[4].value == 0 && arraylayer3[5].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				replaceHand(arraygame, arraylayer2, &cardplay, &x);
				toZero(arraygame, arraylayer2, &cardplay);
			}
			else if (cardplay == 5 && arraylayer3[6].value == 0 && arraylayer3[7].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				replaceHand(arraygame, arraylayer2, &cardplay, &x);
				toZero(arraygame, arraylayer2, &cardplay);
			}
			else if (cardplay == 6 && arraylayer3[7].value == 0 && arraylayer3[8].value == 0 && ((arraylayer2[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer2[cardplay - 1].value - 1) == arraygame[x].value)) {
				replaceHand(arraygame, arraylayer2, &cardplay, &x);
				toZero(arraygame, arraylayer2, &cardplay);
			}
			else {
				printf("Choix invalide\n");

			}
			break;
		case 3:
			printf("\nQuel carte jouer (1 a 9) : ");
			askingCardPlay(&cardplay);
			if (arraylayer4[cardplay - 1].value == 0 && arraylayer4[cardplay].value == 0 && ((arraylayer3[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer3[cardplay - 1].value - 1) == arraygame[x].value))
			{
				replaceHand(arraygame, arraylayer3, &cardplay, &x);
				toZero(arraygame, arraylayer3, &cardplay);
			}
			else {
				printf("Choix invalide\n");
			}
			break;
		case 4:
			printf("\nQuel carte jouer (1 a 10) : ");
			askingCardPlay(&cardplay);

			if ((arraylayer4[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer4[cardplay - 1].value - 1) == arraygame[x].value)
			{
				replaceHand(arraygame, arraylayer4, &cardplay, &x);
				toZero(arraygame, arraylayer4, &cardplay);
			}
			else {
				printf("\nChoix invalide\n");
			}

			break;
		case 5:
			printf("\nMerci d'avoir jouer, au plaisir de vous revoir !\n");
			clearInterface();
			goodbye();
			exit(0);
			break;
		case 6:
			restart();
			break;
		case 7:
			saveGame(arraygame, arraydeck, &plays);
			clearInterface();
			goodbye();
			exit(0);
			break;
		default:
			printf("\nChoix invalide \n");
			break;
		}
		sleeping(1);
	}
}


/*
  Fonction de demande de carte
  Function to ask card
*/
void askingCardPlay(int* pointeurcardplay)
{
	scanf("%d", pointeurcardplay);
	printf("\n");
}


/*
  Fonction d'affichage de message de bienvenue
  Visual welcome message function
*/
void welcome()
{
	printf("\n\n88888888888         d8b 8888888b.                    888               \n");
	printf("    888             Y8P 888   Y88b                   888               \n");
	printf("    888                 888    888                   888               \n");
	printf("    888     888d888 888 888   d88P  .d88b.   8888b.  888  888 .d8888b  \n");
	printf("    888     888P\"   888 8888888P\"  d8P  Y8b     \"88b 888 .88P 88K      \n");
	printf("    888     888     888 888        88888888 .d888888 888888K  \"Y8888b. \n");
	printf("    888     888     888 888        Y8b.     888  888 888 \"88b      X88 \n");
	printf("    888     888     888 888         \"Y8888  \"Y888888 888  888  88888P' \n\n");
}

/*
  Fonction d'affichage de fin de partie
  Visual goodbye message function
*/
void goodbye()
{
	printf("\n\n .d8888b.                         888 888888b.                     \n");
	printf("d88P  Y88b                        888 888  \"88b                    \n");
	printf("888    888                        888 888  .88P                    \n");
	printf("888         .d88b.   .d88b.   .d88888 8888888K.  888  888  .d88b.  \n");
	printf("888  88888 d88\"\"88b d88\"\"88b d88\" 888 888  \"Y88b 888  888 d8P  Y8b \n");
	printf("888    888 888  888 888  888 888  888 888    888 888  888 88888888 \n");
	printf("Y88b  d88P Y88..88P Y88..88P Y88b 888 888   d88P Y88b 888 Y8b.     \n");
	printf(" \"Y8888P88  \"Y88P\"   \"Y88P\"   \"Y88888 8888888P\"   \"Y88888  \"Y8888  \n");
	printf("                                                      888          \n");
	printf("                                                 Y8b d88P          \n");
	printf("                                                  \"Y88P\"           \n\n");
}


/*
  Fonction d'affichage de la partie
  Visual game
*/
void visual(Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraygame[], int* pointeurx)
{
	printf("------------------------------------------------     ----------    -----------\n");
	printf("|  Tripeaks game by Alexis, Gabriel and Roman  |     |  Game  |    |  layer  |\n");
	printf("---------------------------------------------------------------    -----------\n");
	printf("|                                                             |    |         |\n");
	printf("|           %02d%c               %02d%c               %02d%c           |    |    1    |\n", arraylayer1[0].value, arraylayer1[0].symbol, arraylayer1[1].value, arraylayer1[1].symbol, arraylayer1[2].value, arraylayer1[2].symbol);
	printf("|                                                             |    |         |\n");
	printf("|        %02d%c   %02d%c         %02d%c   %02d%c         %02d%c   %02d%c        |    |    2    |\n", arraylayer2[0].value, arraylayer2[0].symbol, arraylayer2[1].value, arraylayer2[1].symbol, arraylayer2[2].value, arraylayer2[2].symbol, arraylayer2[3].value, arraylayer2[3].symbol, arraylayer2[4].value, arraylayer2[4].symbol, arraylayer2[5].value, arraylayer2[5].symbol);
	printf("|                                                             |    |         |\n");
	printf("|     %02d%c   %02d%c   %02d%c   %02d%c   %02d%c   %02d%c   %02d%c   %02d%c   %02d%c     |    |    3    |\n", arraylayer3[0].value, arraylayer3[0].symbol, arraylayer3[1].value, arraylayer3[1].symbol, arraylayer3[2].value, arraylayer3[2].symbol, arraylayer3[3].value, arraylayer3[3].symbol, arraylayer3[4].value, arraylayer3[4].symbol, arraylayer3[5].value, arraylayer3[5].symbol, arraylayer3[6].value, arraylayer3[6].symbol, arraylayer3[7].value, arraylayer3[7].symbol, arraylayer3[8].value, arraylayer3[8].symbol);
	printf("|                                                             |    |         |\n");
	printf("|  %02d%c   %02d%c   %02d%c   %02d%c   %02d%c   %02d%c   %02d%c   %02d%c   %02d%c   %02d%c  |    |    4    |\n", arraylayer4[0].value, arraylayer4[0].symbol, arraylayer4[1].value, arraylayer4[1].symbol, arraylayer4[2].value, arraylayer4[2].symbol, arraylayer4[3].value, arraylayer4[3].symbol, arraylayer4[4].value, arraylayer4[4].symbol, arraylayer4[5].value, arraylayer4[5].symbol, arraylayer4[6].value, arraylayer4[6].symbol, arraylayer4[7].value, arraylayer4[7].symbol, arraylayer4[8].value, arraylayer4[8].symbol, arraylayer4[9].value, arraylayer4[9].symbol);
	printf("|                                                             |    |         |\n");
	printf("---------------------------------------------------------------    -----------\n");
	printf("\n--------------\n");
	printf("| Hand : %02d%c |\n", arraygame[*pointeurx].value, arraygame[*pointeurx].symbol);
	printf("--------------\n");
	printf("\n\n0. \tDraw from deck\n1-4.Layer choice\n5. \tEnd Game\n6. \tNew Game\n7. \tSave\n");
	printf("\nChoice\n:");
}



/*
  Fonction de remplacement de carte par une carte par 0
  Card replacement function by a card by 0
*/
void toZero(Card arraygame[], Card layer[], int* pointeurcardplay)
{
	layer[*pointeurcardplay - 1].value = 0;
	layer[*pointeurcardplay - 1].symbol = 'x';
}


/*
  fonction qui remplace la carte dans la main
  function that replaces the card in the hand
*/

void replaceHand(Card arraygame[], Card layer[], int* pointeurcardplay, int* pointeurx)
{
	arraygame[*pointeurx + 1] = layer[*pointeurcardplay - 1];
	*pointeurx += 1;
}

/*
  Fonction de restart et appel de la generation du jeu
  Restart function and call generation of the game
*/
void restart()
{
	printf("\nVous avez decider de relancer la partie\n");
	printf("... Nouvelle partie en cours ... \n");
	generateGame();
}

/*
  Fonction de generation du jeu
  generate game function
*/

void generateGame() {

	// Packet de cartes entier
	// Entire card pack

	Card arraycard[52];

	// Tableau couche 1 a 4
	// Table layer 1 to 4

	Card arraylayer1[3];
	Card arraylayer2[6];
	Card arraylayer3[9];
	Card arraylayer4[10];

	// Tableau pioche
	// Draw array

	Card arraydeck[24];
	Card arraygame[52];

	// Initialisation du random
	// Initialize the random

	srand(time(NULL));

	// Fonction d'initialisation des cartes
	// Card initialization function

	InitializeCard(arraycard);

	// Fonction de melange des cartes
	// Card shuffle function

	shuffle(arraycard);

	// Fonction attribution des cartes au different layer
	// Assignment of cards to the different layer function

	AttribueCards(arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraydeck, arraycard);

	// Fonction de jeu
	// Game function 

	game(arraygame, arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraydeck);
}

/*
	Fonction qui sauvegarde un resum� de la partie
	Function which saves a summary of the game
*/

void saveGame(Card arraygame[], Card arraydeck[], int* plays) {

	char path[200];
	getcwd(path, 200);

	FILE* fptr;
	fptr = fopen("resume.txt", "a+");

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	fprintf(fptr, "\nVous avez demande un resume le: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	fprintf(fptr, "Vous avez joue ces cartes :\n");
	for (int i = 0; i < *plays; i++) {
		fprintf(fptr, "%d%c - ", arraygame[i].value, arraygame[i].symbol);
	}

	fprintf(fptr, "\nIl y avait ces cartes dans la reserve :\n");
	for (int i = 0; i < 23; i++) {
		fprintf(fptr, "%d%c - ", arraydeck[i].value, arraydeck[i].symbol);
	}
	fprintf(fptr, "\n---FIN DE PARTIE---\n");
	fclose(fptr);

	clearInterface();

	printf("---SAUVEGARDE TERMINE ---\n");
	printf("Fichier sauvegarde a l'espace de fichier : %s\\resume.txt \n", path);
	system("pause");
}

