# TRIPEAKS 
### By FRICHOT Roman | GIBON Gabriel | PASQUIER ALEXIS

![N|Solid](https://www.polesup-delasalle.fr/wp-content/uploads/sites/5/2020/01/Sticker-Fili%C3%A8re-SI_Publi%C3%A9-250x250.jpg) 

## Introduction
This game look like [jeusol.fr](https://www.jeusol.fr/tripeaks) programming in C language.

## Installation
Clone this repository and let's it !

```sh
git clone git@github.com:rmfr35/TriPeak.git
```
## How to play ?
Launch program and enter your choice in the console.

## How it works ?
If your card than you take is valid (-1 or +1 of the current card) in the game you can see the card choose is remplace by '00x' card. 

You can choose 9 choice : 

| VALUE | (EN) | (FR) |
| ------ | ------ | ------ |
| 0 |  Draw card from deck | Prendre une carte de la pioche | 
| 1 |  Choose card from layer 1 | Choisir une carte de la couche 1 | 
| 2 |  Choose card from layer 2 | Choisir une carte de la couche 2 | 
| 3 |  Choose card from layer 3 | Choisir une carte de la couche 3 | 
| 4 |  Choose card from layer 4 | Choisir une carte de la couche 4 | 
| 5 |  End the game | Finir la partie |
| 6 |  New game | Nouvelle partie |
| 7 |  Save the game into a .txt file | Sauvegarder la partie dans un fichier resumé .txt | 
| 8 |  Play with auto-resolution mode | Jouer avec le mode d'auto-résolution (automatique) | 


###### Card is generate 1 from 13
| VALUE | (EN) | (FR) |
| ------ | ------ | ------ |
| 1 |  AS | AS | 
| 2 |  2 | 2 | 
| 3 |  3 | 3 | 
| 4 |  4 | 4 | 
| 5 |  5 | 5 |
| 6 |  6 | 6 |
| 7 |  7 | 7 | 
| 8 |  8 | 8 | 
| 9 |  9 | 9 | 
| 10 |  10 | 10 | 
| 11 |  Jack | Valet | 
| 12 |  Queen | Dame | 
| 13 |  King | Roi |

| SYMBOL | EN | FR |
| ------ | ------ | ------ |
| c |  clubs | Trèfle |
| d |  diamonds | Carreaux |
| h |  heart | Coeur |
| s |  spade | Pique |


## Program connect to libraries
To works properly this program `include libraries` available in **game.h** :
```sh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
```
> `Don't touch any libraries in this project if you don't wan't a crash !`

## It works with multiplateforms !
We have configure this game to works with linux. 
In fact, we see under which system the program is running to make it more ergonomic !
by using env def more informations at [this site](https://iq.opengenus.org/detect-operating-system-in-c/). `/!\ It make to avoid crash in others systems`

```sh
// Windows system
#ifdef _WIN32
    //code...
#endif

// Unix system
#ifdef __unix__
    //code...
#endif
```

## Program variables
We are using lot of variables in this program. You can see it below with their description

| VARIABLE | TYPE  | DESCRIPTION |
| ------ | ------ | ------ |
| arraycard | Card | All cards of the game |
| arraylayer1 | Card | First layer of the game from the top |
| arraylayer2 | Card | Second layer |
| arraylayer3 | Card | Third layer |
| arrayDeck | Card | Reserve deck of the game |

## Program functions
We use differents functions in this program 
| FUNCTION NAME | TYPE  | DESCRIPTION |
| ------ | ------ | ------ |
| InitializeCard() | int | This function initialize all cards in game |
| shuffle() | void | This function shuffle all cards |
| attribueCards() | void | This function attribue cards in differents layers |
| game() | void | This function to play game |
| restart() | void | This function restart the game |
| generateGame() | void | This function generate the game |
| saveGame() | void | This function save the game |

## Documentations
In directory **Algorithms/** you can take our algorithm of this program.
=======
| toZero() | void | Card replacement function by a card by 0 |
| welcome() | void | Visual welcome message function |
| visual() | void | Visual game |
| askingCardPlay() | void | Function to ask card |
| replaceHand() | void | function that replaces the card in the hand |
| goodbye() | void | Visual goodbye message function |
| clearInterface() | void | clear terminal function |
| sleeping() | void | pause terminal function |

## Documentations
Go to **[this site](https://docs.google.com/document/d/1Q2mAL1IWtuvaTlGDmiTICal7OWSXamm_RVFq7MhKx8c/edit)** and you see our algorithm of this program

