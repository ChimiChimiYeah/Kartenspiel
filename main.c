#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "karten.h"
#include "spieler.h"
#include "ausgabe.h"

int main(void)
{
    Spieler mensch;
    Spieler computer;
    srand(time(NULL));
    SetConsoleOutputCP(CP_UTF8);
    initialisiereSpieler(&mensch, &computer);

    kartenVergabe(&mensch.handkarten[0], &computer.handkarten[0]);
    zufaelligeComputerStrategie(&computer);

    for (int zugAnzahl = 0; zugAnzahl < RUNDEN_ANZAHL; zugAnzahl++)
    {
        /* code */
    }
    test(&computer);
    printf("Spieler: %s, Punkte: %d\n", mensch.spielername, mensch.punkte);
    printf("Computer: %s, Punkte: %d\n", computer.spielername, computer.punkte);

    return 0;
}