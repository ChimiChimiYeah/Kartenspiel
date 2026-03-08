#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "karten.h"
#include "spieler.h"
#include "konsole.h"

#define RUNDEN_ANZAHL 10 // Anzahl der Runden
#define MENSCH 0         // Index des Menschen in der Liste "spieler"
#define COMPUTER 1       // Index des Computer in der Liste "spieler"

int main(void)
{
    Spieler spieler[2];
    int spielerAmZug = COMPUTER;
    int indexGespielteKarte;
    Spielkarte ersteKarte;
    Spielkarte zweiteKarte;

    srand(time(NULL));
    initialisiereKonsole();
    initialisiereSpieler(&spieler[MENSCH], &spieler[COMPUTER]);

    kartenVergabe(&spieler[MENSCH].handkarten[0], &spieler[COMPUTER].handkarten[0]);
    zufaelligeComputerStrategie(&spieler[COMPUTER]);

    // for (int zugAnzahl = 1; zugAnzahl < RUNDEN_ANZAHL; zugAnzahl++)
    for (int zugAnzahl = 1; zugAnzahl < 2; zugAnzahl++)
    {
        int anzahlHandkarten = RUNDEN_ANZAHL - zugAnzahl;

        indexGespielteKarte = spieler[spielerAmZug].zugPointer(spieler[spielerAmZug].handkarten, NULL, anzahlHandkarten);
        ersteKarte = spieler[spielerAmZug].handkarten[indexGespielteKarte];
        karteLegen(&spieler[spielerAmZug], anzahlHandkarten, indexGespielteKarte);

        indexGespielteKarte = spieler[1 - spielerAmZug].zugPointer(spieler[1 - spielerAmZug].handkarten, &ersteKarte, anzahlHandkarten);
        zweiteKarte = spieler[spielerAmZug].handkarten[indexGespielteKarte];
        karteLegen(&spieler[1 - spielerAmZug], anzahlHandkarten, indexGespielteKarte);
    }
    printf("Spieler: %s, Punkte: %d\n", spieler[MENSCH].spielername, spieler[MENSCH].punkte);
    printf("Computer: %s, Punkte: %d\n", spieler[COMPUTER].spielername, spieler[COMPUTER].punkte);

    return 0;
}