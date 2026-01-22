#include "karten.c"
#include "spieler.c"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    spieler mensch;
    spieler computer;
    initialisiereSpieler(&mensch, &computer);
    kartenstapelErstellen();

    printf("\n");
    printf("Spieler: %s, Punkte: %d\n", mensch.spielername, mensch.punkte);
    printf("Computer: %s, Punkte: %d\n", computer.spielername, computer.punkte);

    return 0;
}