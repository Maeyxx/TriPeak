#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct card
{
  char symbol;
  // c = Clubs | h = Hearts | d = Diamonds | s = Spades
  int value;
  // From 1 to 13
};
typedef struct card Card;

