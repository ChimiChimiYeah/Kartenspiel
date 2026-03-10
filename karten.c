#include "karten.h"
#include "spieler.h"
#include "konsole.h"

// Symbole für die Ausgabe der Kartenfarbe
const char *symbolFarbe[] = {
    "♦",
    "♥",
    "♠",
    "♣"};

// Symbole für die Ausgabe der Kartenwerte
const char *symbolWert[] = {
    "2", "3", "4", "5", "6", "7", "8", "9", "10", "B", "D", "K", "A"};

// Erstellt, mischt und verteilt ein Kartendeck mit 52 Karten an zwei Spieler
// Parameter:
// - Spielkarte *menschHandkarten: Liste, in der die Handkarten des Menschen gespeichert werden
// - Spielkarte *computerHandkarten: Liste, in der die Handkarten des Computers gespeichert werden
void kartenVergabe(Spielkarte *menschHandkarten, Spielkarte *computerHandkarten)
{
    Spielkarte kartenStapel[52];
    kartenstapelErstellen(kartenStapel);
    kartenMischen(kartenStapel);
    kartenAusteilen(kartenStapel, menschHandkarten, computerHandkarten);
}

// Erstellt ein Kartendeck mit 52 Karten
// Parameter:
// - Spielkarte *kartenStapel: Liste, in der die Karten gespeichert werden
void kartenstapelErstellen(Spielkarte *kartenStapel)
{
    for (int i = 0; i < FARBEN_ANZAHL; i++)
    {
        for (int j = 0; j < WERTE_ANZAHL; j++)
        {
            // Erstellt eine Karte
            Spielkarte karte =
                {
                    .kartenfarbe = (Kartenfarbe)i,
                    .kartenwert = (Kartenwert)(j + 2),
                };
            // Speichert die Karte im Deck
            kartenStapel[i * WERTE_ANZAHL + j] = karte;
        }
    }
}

// Mischt ein Kartendeck beliebiger Größe
// Parameter:
// - Spielkarte *kartenStapel: Liste, die mithilfe von Bubble-Sort gemischt wird
void kartenMischen(Spielkarte *kartenStapel)
{
    for (int i = DECK_GROESSE - 1; i > 0; i--)
    {
        int zufallsZahl = rand() % (i + 1);
        Spielkarte zwischenSpeicher = kartenStapel[zufallsZahl];
        kartenStapel[zufallsZahl] = kartenStapel[i];
        kartenStapel[i] = zwischenSpeicher;
    }
}

// Verteilt das Kartendeck an zwei Spieler
// Parameter:
// - Spielkarte *kartenStapel: Liste mit dem Kartendeck
// - Spielkarte *menschHandkarten: Liste, in der die Handkarten des Menschen gespeichert werden
// - Spielkarte *computerHandkarten: Liste, in der die Handkarten des Computers gespeichert werden
void kartenAusteilen(Spielkarte *kartenStapel, Spielkarte *menschHandkarten, Spielkarte *computerHandkarten)
{
    for (int i = 0; i < HANDKARTEN_ANZAHL; i++)
    {
        computerHandkarten[i] = kartenStapel[2 * i];
        menschHandkarten[i] = kartenStapel[2 * i + 1];
    }
}

void karteLegen(struct Spieler *spieler, int maxHandkartenIndex, int indexGespielteKarte)
{
    anzeigeGespielteKarte(spieler->spielername, spieler->handkarten[indexGespielteKarte]);
    entferneKarteVonHand(spieler->handkarten, maxHandkartenIndex, indexGespielteKarte);
}

int kartenStich(int spielerAmZug, int kartenwertErsteKarte, int kartenwertZweiteKarte)
{
    if (kartenwertErsteKarte >= kartenwertZweiteKarte)
        return spielerAmZug;
    else
        return 1 - spielerAmZug;
}
void entferneKarteVonHand(Spielkarte *handkarten, int maxHandkartenIndex, int indexGespielteKarte)
{
    for (int i = indexGespielteKarte; i < maxHandkartenIndex; i++)
    {
        handkarten[i] = handkarten[i + 1];
    }
}

int kartenPunkte(int kartenwert)
{
    switch (kartenwert)
    {
    case 11:
        return 2;
    case 12:
        return 3;
    case 13:
        return 4;
    case 14:
        return 11;
    default:
        return kartenwert;
    }
}