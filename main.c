#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "karten.c"
#include "spieler.c"

int main(int argc, char const *argv[])
{
    spieler mensch;
    spieler computer;
    srand(time(NULL));
    initialisiereSpieler(&mensch, &computer);

    printf("\n");

    kartenVergabe(&mensch.handkarten[0], &computer.handkarten[0]);

    printf("Spieler: %s, Punkte: %d\n", mensch.spielername, mensch.punkte);
    printf("Computer: %s, Punkte: %d\n", computer.spielername, computer.punkte);

    return 0;
}