#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "karten.h"
#include "spieler.h"
#include "ausgabe.h"

#define RUNDEN_ANZAHL 10

int main(void)
{
    Spieler mensch;
    Spieler computer;
    srand(time(NULL));
    initialisiereKonsole();
    initialisiereSpieler(&mensch, &computer);

    kartenVergabe(&mensch.handkarten[0], &computer.handkarten[0]);
    zufaelligeComputerStrategie(&computer);

    // for (int zugAnzahl = 1; zugAnzahl < RUNDEN_ANZAHL; zugAnzahl++)
    for (int zugAnzahl = 1; zugAnzahl < 2; zugAnzahl++)
    {
        Spielkarte karte = {
            .kartenfarbe = 0,
            .kartenwert = 0,
        };
        mensch.zugPointer(mensch.handkarten, &karte, RUNDEN_ANZAHL - zugAnzahl);
    }
    printf("Spieler: %s, Punkte: %d\n", mensch.spielername, mensch.punkte);
    printf("Computer: %s, Punkte: %d\n", computer.spielername, computer.punkte);

    return 0;
}