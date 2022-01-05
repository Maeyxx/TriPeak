#include "Game.h"



/*
  (Changed from operating system) : clear terminal function / Fonction pour nettoyer le terminal
  @void
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
  (Changed from operating system) : pause terminal function / Fonction pour mettre en pause le terminal
  @param : time : time to sleep / temps de pause du terminal
  @void
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

/*
  Initialize the card package and increment each card structure in the arraycard array / Initialise le paquet de carte et incremente chaque structure de carte dans le tableau arraycard
  @param : arraycard : card package / Packet de carte du jeu
  @return : 0
*/
int InitializeCard(Card arraycard[])
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
		default:
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
  Card shuffle function / Fonction de melange des cartes
  @param : arraycard : card package / Packet de carte du jeu
  @void
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
  Assignment of cards to the different layer function / Fonction attribution des cartes au different layer
  @param : arraylayer1 : card of layer 1 / Packet de carte de la couche 1
  @param : arraylayer2 : card of layer 2 / Packet de carte de la couche 2
  @param : arraylayer3 : card of layer 3 / Packet de carte de la couche 3
  @param : arraylayer4 : card of layer 4 / Packet de carte de la couche 4
  @param : arraydeck : card of deck / Packet de carte du deck
  @param : arraycard : card package / Packet de carte du jeu
  @void
*/
void attribueCards(Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraydeck[], Card arraycard[])
{
	int counter = 0;
	for (int a = 0; a <= 23; a++)
	{
		arraydeck[a] = arraycard[a];
	}
	for (int a = 24; a <= 26; a++)
	{
		arraylayer1[counter] = arraycard[a];
		counter++;
	}
	counter = 0;
	for (int a = 27; a <= 32; a++)
	{
		arraylayer2[counter] = arraycard[a];
		counter++;
	}
	counter = 0;
	for (int a = 33; a <= 41; a++)
	{
		arraylayer3[counter] = arraycard[a];
		counter++;
	}
	counter = 0;
	for (int a = 42; a <= 51; a++)
	{
		arraylayer4[counter] = arraycard[a];
		counter++;
	}
}

/*
  Game function / Fonction de jeu
  @param : arraygame : card of game / Packet de carte du jeu
  @param : arraylayer1 : card of layer 1 / Packet de carte de la couche 1
  @param : arraylayer2 : card of layer 2 / Packet de carte de la couche 2
  @param : arraylayer3 : card of layer 3 / Packet de carte de la couche 3
  @param : arraylayer4 : card of layer 4 / Packet de carte de la couche 4
  @param : arraydeck : card of deck / Packet de carte du deck
  @void
*/
void game(Card arraygame[], Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraydeck[])
{
	int cardplay = 0;
	int* pointercardplay = &cardplay;
	int x = 0;
	int* pointerx = &x;
	int m = 23;
	int* pointerm = &m;
	int plays = 0;
	int* pointerplays = &plays;
	int choicemenu;
	char* loop = "enter";
	arraygame[x] = arraydeck[m];
	m--;
	welcome();
	sleeping(3);
	while (strcmp(loop, "enter") == 0) {
		plays++;
		clearInterface();
		visual(arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraygame, &x);
		scanf("%d", &choicemenu);
		switch (choicemenu) {
		case 0:
			if (m < 0) {
				printf("\n No more cards in the deck \n");
			}
			else {
				arraygame[x + 1] = arraydeck[m];
				x++;
				m--;
			}
			break;
		case 1:
			printf("\nWhich card play (1 to 3) : ");
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
				printf("\nInvalid choice\n");
			}
			break;
		case 2:
			printf("\nWhich card play (1 to 6) : ");
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
				printf("\nInvalid choice\n");

			}
			break;
		case 3:
			printf("\nWhich card play (1 to 9) : ");
			askingCardPlay(&cardplay);
			if (arraylayer4[cardplay - 1].value == 0 && arraylayer4[cardplay].value == 0 && ((arraylayer3[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer3[cardplay - 1].value - 1) == arraygame[x].value))
			{
				replaceHand(arraygame, arraylayer3, &cardplay, &x);
				toZero(arraygame, arraylayer3, &cardplay);
			}
			else {
				printf("\nInvalid choice\n");
			}
			break;
		case 4:
			printf("\nWhich card play (1 to 10) : ");
			askingCardPlay(&cardplay);

			if ((arraylayer4[cardplay - 1].value + 1) == arraygame[x].value || (arraylayer4[cardplay - 1].value - 1) == arraygame[x].value)
			{
				replaceHand(arraygame, arraylayer4, &cardplay, &x);
				toZero(arraygame, arraylayer4, &cardplay);
			}
			else {
				printf("\nInvalid choice\n");
			}

			break;
		case 5:
			printf("\nThanks for playing, hope to see you again !\n");
			clearInterface();
			goodbye();
			sleeping(1);
			loop = "end";
			break;
		case 6:
			restart();
			break;
		case 7:
			saveGame(arraygame, arraydeck, &plays);
			clearInterface();
			goodbye();
			sleeping(1);
			loop = "end";
			break;
		default:
			printf("\nInvalid choice \n");
			break;
		}
		sleeping(1);
	}
}


/*
  Function to ask card / Fonction de demande de carte
  @param : pointercardplay : Card to current play / La carte courante à jouer
  @void
*/
void askingCardPlay(int* pointercardplay)
{
	scanf("%d", pointercardplay);
	printf("\n");
}


/*
  Visual welcome message function / Fonction d'affichage de message de bienvenue
  @void
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
  Visual goodbye message function / Fonction d'affichage de fin de partie
  @void
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
  Visual game / Fonction d'affichage de la partie
  @param : arraylayer1 : card of layer 1 / Packet de carte de la couche 1
  @param : arraylayer2 : card of layer 2 / Packet de carte de la couche 2
  @param : arraylayer3 : card of layer 3 / Packet de carte de la couche 3
  @param : arraylayer4 : card of layer 4 / Packet de carte de la couche 4
  @param : arraygame : card of game / Packet de carte du jeu
  @param : pointerx : x pointer / pointer de x
  @void
*/
void visual(Card arraylayer1[], Card arraylayer2[], Card arraylayer3[], Card arraylayer4[], Card arraygame[], int* pointerx)
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
	printf("| Hand : %02d%c |\n", arraygame[*pointerx].value, arraygame[*pointerx].symbol);
	printf("--------------\n");
	printf("\n\n0. \tDraw from deck\n1-4. \tLayer choice\n5. \tEnd Game\n6. \tNew Game\n7. \tSave\n");
	printf("\nChoice : ");
}


/*
  Card replacement function by a card by 0 / Fonction de remplacement de carte par une carte par 0
  @param : arraygame : card of game / Packet de carte du jeu
  @param : layer : array of current layer / Tableau courant de la couche
  @param : pointercardplay : cardPlay pointer / pointer de x
  @void
*/
void toZero(Card arraygame[], Card layer[], int* pointercardplay)
{
	layer[*pointercardplay - 1].value = 0;
	layer[*pointercardplay - 1].symbol = 'x';
}


/*
  function that replaces the card in the hand / fonction qui remplace la carte dans la main
  @param : arraygame : card of game / Packet de carte du jeu
  @param : layer : array of current layer / Tableau courant de la couche
  @param : pointercardplay : cardPlay pointer / pointer de x
  @param : pointerx : x pointer / pointer de x
  @void
*/
void replaceHand(Card arraygame[], Card layer[], int* pointercardplay, int* pointerx)
{
	arraygame[*pointerx + 1] = layer[*pointercardplay - 1];
	*pointerx += 1;
}


/*
  Restart function and call generation of the game / Fonction de restart et appel de la generation du jeu
  @void
*/
void restart()

{
	printf("\nYou have decided to restart the game\n");
	printf("... New game in progress ... \n");
	generateGame();
}


/*
generate game function / Fonction de generation du jeu
@void
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

	// Fonction d'initialisation des cartes
	// Card initialization function

	InitializeCard(arraycard);

	// Fonction de melange des cartes
	// Card shuffle function

	shuffle(arraycard);

	// Fonction attribution des cartes au different layer
	// Assignment of cards to the different layer function

	attribueCards(arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraydeck, arraycard);

	// Fonction de jeu
	// Game function 

	game(arraygame, arraylayer1, arraylayer2, arraylayer3, arraylayer4, arraydeck);
}


/*
Function which saves a summary of the game / Fonction qui sauvegarde un resume de la partie
@param : arraygame : card of game / Packet de carte du jeu
@param : arraydeck : Card into the deck / Les cartes dans le deck
@param : plays : number of play / Nombre de tour joue
@void
*/
void saveGame(Card arraygame[], Card arraydeck[], int* plays) {

	char path[200];
	getcwd(path, 200);

	FILE* fptr;
	fptr = fopen("summary.txt", "a+");

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	fprintf(fptr, "\nYou asked for a summary the : %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	fprintf(fptr, "You played these cards :\n");
	for (int i = 0; i < *plays; i++) {
		fprintf(fptr, "%d%c - ", arraygame[i].value, arraygame[i].symbol);
	}

	fprintf(fptr, "\nThese cards were left in the reserve :\n");
	for (int i = 0; i < 23; i++) {
		fprintf(fptr, "%d%c - ", arraydeck[i].value, arraydeck[i].symbol);
	}
	fprintf(fptr, "\n---End of the game---\n");
	fclose(fptr);

	clearInterface();

	printf("---Save end---\n");
	printf("File save to file space : %s\\summary.txt \n", path);
	system("pause");
}

