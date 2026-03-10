#include <time.h>
#include <stdlib.h>
#include "karten.h"
#include "spieler.h"
#include "konsole.h"

#define RUNDEN_ANZAHL 10 // Anzahl der Runden
#define MENSCH 0         // Index des Menschen in der Liste "spieler"
#define COMPUTER 1       // Index des Computer in der Liste "spieler"

int main(void)
{
    Spieler spieler[2];          // Liste mit den Spieler Structs
    int spielerAmZug = COMPUTER; // gibt an, welcher Spieler am Zug ist. Anfangs der Computer
    int indexGespielteKarte;     // gibt den Index der gelegten Karte in der Liste Handkarten an
    int spielerStich;            // gibt an, welcher Spieler den Stich gewonnen hat
    Spielkarte ersteKarte;       // gibt die erste gelegte Karte der Runde an
    Spielkarte zweiteKarte;      // gibt die zweite gelegte Karte der Runde an

    srand(time(NULL));
    initialisiereKonsole();
    initialisiereSpieler(&spieler[MENSCH], &spieler[COMPUTER]);

    kartenVergabe(&spieler[MENSCH].handkarten[0], &spieler[COMPUTER].handkarten[0]);
    zufaelligeComputerStrategie(&spieler[COMPUTER]);

    for (int zugAnzahl = 1; zugAnzahl <= RUNDEN_ANZAHL; zugAnzahl++)
    {
        int maxHandkartenIndex = RUNDEN_ANZAHL - zugAnzahl;

        anzeigeZug(zugAnzahl);
        indexGespielteKarte = spieler[spielerAmZug].zugPointer(spieler[spielerAmZug].handkarten, NULL, maxHandkartenIndex);
        ersteKarte = spieler[spielerAmZug].handkarten[indexGespielteKarte];
        karteLegen(&spieler[spielerAmZug], maxHandkartenIndex, indexGespielteKarte);

        indexGespielteKarte = spieler[1 - spielerAmZug].zugPointer(spieler[1 - spielerAmZug].handkarten, &ersteKarte, maxHandkartenIndex);
        zweiteKarte = spieler[1 - spielerAmZug].handkarten[indexGespielteKarte];
        karteLegen(&spieler[1 - spielerAmZug], maxHandkartenIndex, indexGespielteKarte);

        spielerStich = kartenStich(spielerAmZug, ersteKarte.kartenwert, zweiteKarte.kartenwert);
        spieler[spielerStich].punkte += kartenPunkte(ersteKarte.kartenwert) + kartenPunkte(zweiteKarte.kartenwert);
        anzeigeStichSieger(spieler[spielerStich].spielername);
        spielerAmZug = spielerStich;
    }
    anzeigePunkte(spieler[MENSCH].spielername, spieler[MENSCH].punkte, spieler[COMPUTER].spielername, spieler[COMPUTER].punkte);
    anzeigeGewinner(spieler[MENSCH].spielername, spieler[MENSCH].punkte, spieler[COMPUTER].spielername, spieler[COMPUTER].punkte);

    free(spieler[MENSCH].spielername);
    return 0;
}