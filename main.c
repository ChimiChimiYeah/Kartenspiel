#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "karten.h"
#include "spieler.h"
#include "ausgabe.h"

#define RUNDEN_ANZAHL 10 // Anzahl der Runden
#define MENSCH 0         // Index des Menschen in der Liste "spieler"
#define COMPUTER 1       // Index des Computer in der Liste "spieler"

int main(void)
{
    Spieler spieler[2];
    int spielerAmZug = COMPUTER;

    srand(time(NULL));
    // initialisiereKonsole();
    initialisiereSpieler(&spieler[MENSCH], &spieler[COMPUTER]);

    kartenVergabe(&spieler[MENSCH].handkarten[0], &spieler[COMPUTER].handkarten[0]);
    zufaelligeComputerStrategie(&spieler[COMPUTER]);

    // for (int zugAnzahl = 1; zugAnzahl < RUNDEN_ANZAHL; zugAnzahl++)
    for (int zugAnzahl = 1; zugAnzahl < 2; zugAnzahl++)
    {

        Spielkarte karte = {
            .kartenfarbe = 0,
            .kartenwert = 0,
        };
        spieler[spielerAmZug].zugPointer(spieler[spielerAmZug].handkarten, &karte, RUNDEN_ANZAHL - zugAnzahl);
        spieler[1 - spielerAmZug].zugPointer(spieler[1 - spielerAmZug].handkarten, &karte, RUNDEN_ANZAHL - zugAnzahl);
    }
    printf("Spieler: %s, Punkte: %d\n", spieler[MENSCH].spielername, spieler[MENSCH].punkte);
    printf("Computer: %s, Punkte: %d\n", spieler[COMPUTER].spielername, spieler[COMPUTER].punkte);

    return 0;
}