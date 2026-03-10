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

// Erstellt ein Kartendeck mit 52 Karten (4 Farben × 13 Werte)
// Parameter:
// - Spielkarte *kartenStapel: Liste, in der die Karten gespeichert werden
void kartenstapelErstellen(Spielkarte *kartenStapel)
{
    for (int i = 0; i < FARBEN_ANZAHL; i++)
    {
        for (int j = 0; j < WERTE_ANZAHL; j++)
        {
            // Erstellt eine Karte mit Farbe i und Wert j+2
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

// Mischt ein Kartendeck mithilfe des Fisher-Yates-Algorithmus
// Parameter:
// - Spielkarte *kartenStapel: Liste, die gemischt wird
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

// Verteilt das Kartendeck abwechselnd an zwei Spieler (je 10 Karten)
// Parameter:
// - Spielkarte *kartenStapel: Liste mit dem gemischten Kartendeck
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

// Legt eine Karte eines Spielers und zeigt sie an
// Parameter:
// - struct Spieler *spieler: Zeiger auf den Spieler, der die Karte legt
// - int maxHandkartenIndex: Höchster gültiger Index der Handkarten
// - int indexGespielteKarte: Index der zu legenden Karte
void karteLegen(struct Spieler *spieler, int maxHandkartenIndex, int indexGespielteKarte)
{
    anzeigeGespielteKarte(spieler->spielername, spieler->handkarten[indexGespielteKarte]);
    entferneKarteVonHand(spieler->handkarten, maxHandkartenIndex, indexGespielteKarte);
}

// Bestimmt den Gewinner eines Stichs
// Parameter:
// - int spielerAmZug: Index des Spielers, der die erste Karte gelegt hat
// - int kartenwertErsteKarte: Wert der ersten gelegten Karte
// - int kartenwertZweiteKarte: Wert der zweiten gelegten Karte
// Return: Index des Spielers, der den Stich gewonnen hat
int kartenStich(int spielerAmZug, int kartenwertErsteKarte, int kartenwertZweiteKarte)
{
    if (kartenwertErsteKarte >= kartenwertZweiteKarte)
        return spielerAmZug;
    else
        return 1 - spielerAmZug;
}

// Entfernt eine gespielte Karte aus der Hand eines Spielers
// Parameter:
// - Spielkarte *handkarten: Liste der Handkarten
// - int maxHandkartenIndex: Höchster gültiger Index der Handkarten
// - int indexGespielteKarte: Index der zu entfernenden Karte
void entferneKarteVonHand(Spielkarte *handkarten, int maxHandkartenIndex, int indexGespielteKarte)
{
    // Verschiebt alle Karten nach der entfernten Karte um eine Position nach links
    for (int i = indexGespielteKarte; i < maxHandkartenIndex; i++)
    {
        handkarten[i] = handkarten[i + 1];
    }
}

// Berechnet die Punktzahl einer Karte
// Parameter:
// - int kartenwert: Wert der Karte (2-14)
// Return: Punktzahl der Karte (Bube=2, Dame=3, König=4, Ass=11, sonst Kartenwert)
int kartenPunkte(int kartenwert)
{
    switch (kartenwert)
    {
    case 11: // Bube
        return 2;
    case 12: // Dame
        return 3;
    case 13: // König
        return 4;
    case 14: // Ass
        return 11;
    default: // Zahlenkarten (2-10)
        return kartenwert;
    }
}
