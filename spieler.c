#include "spieler.h"

// Initialisiere die Structs für Mensch und Computer
// Parameter: Zwei "Spieler"-Structs
void initialisiereSpieler(Spieler *mensch, Spieler *computer)
{
    // Initialisiere den Menschen
    mensch->spielername = spielername();
    // Handkarten werden später verteilt
    mensch->punkte = 0;
    mensch->zugPointer = &spielerzug;

    // Initialisere den Computer
    computer->spielername = "Computer";
    // Handkarten werden später verteilt
    computer->punkte = 0;
    // Computergegner wird gesetzt, wenn Handkarten verteilt sind
}

// Verlangt einen Spielernamen
// Return: Spielername
char *spielername(void)
{
    return "Mensch";
}

/*
// Implemention des Zuges des Menschen
 Zeigt die Handkarten des Spielers an und lässt ihn eine wählen
 Paramter:
 - Struct "Spielkarte" mit den Handkarten des Spielers
 - Struct "SPielkarte" wird in dieser Funktion nicht benötigt
 - int anzahlHandkarten
 Return: den Index der gewählten Karte
*/
int spielerzug(Spielkarte *menschHandkarten, const Spielkarte *gespielteKarte, int anzahlHandkarten)
{
    (void)gespielteKarte;
    int indexGewaehlterKarte;

    handkartenAnzeige(menschHandkarten, anzahlHandkarten);
    indexGewaehlterKarte = auswahlHandkarte();
    return indexGewaehlterKarte;
}

// Auswahl einer Handkarte des Spieles
int auswahlHandkarte()
{
    return 0;
}

// Wählt eine zufällige Strategie des Computer fest
void zufaelligeComputerStrategie(Spieler *computer)
{
    int zufallsZahl = rand() % 4;

    if (zufallsZahl != 0)
        sortiereHandkartenGrossNachKlein(computer->handkarten);

    if (zufallsZahl == 3)
        sortiereHandkartenKleinsteGroesste(computer->handkarten);

    switch (zufallsZahl)
    {
    case 0:
    case 1:
    case 2:
        computer->zugPointer = &einfacherStrategischerWechselnderComputer;
        break;
    case 3:
        computer->zugPointer = &reaktiverComputer;
        break;
    default:
        computer->zugPointer = &reaktiverComputer;
        break;
    }
}

// Sortiert Handkarten von kleinstem Wert nach größtem Wert
void sortiereHandkartenGrossNachKlein(Spielkarte *computerHandkarten)
{
    for (int i = 0; i < HANDKARTEN_ANZAHL - 1; i++)
    {
        for (int j = i + 1; j < HANDKARTEN_ANZAHL; j++)
        {
            if (computerHandkarten[i].kartenwert < computerHandkarten[j].kartenwert)
            {
                Spielkarte zwischenSpeicher = computerHandkarten[i];
                computerHandkarten[i] = computerHandkarten[j];
                computerHandkarten[j] = zwischenSpeicher;
            }
        }
    }
}

// Sortiert Handkarten wie folgt:
// Kleinster Wert -> Größter Wert -> Zweitkleinster Wert -> Zweitgrößter Wert -> ...
//
void sortiereHandkartenKleinsteGroesste(Spielkarte *computerHandkarten)
{
    Spielkarte sortierteHandkarten[10];
    for (int i = 0; i < HANDKARTEN_ANZAHL / 2; i++)
    {
        sortierteHandkarten[i * 2] = computerHandkarten[(HANDKARTEN_ANZAHL - 1) - i];
        sortierteHandkarten[i * 2 + 1] = computerHandkarten[i];
    }
    if ((HANDKARTEN_ANZAHL % 2) == 1)
    {
        sortierteHandkarten[HANDKARTEN_ANZAHL - 1] = computerHandkarten[HANDKARTEN_ANZAHL / 2 + 1];
    }
    for (int i = 0; i < HANDKARTEN_ANZAHL; i++)
    {
        computerHandkarten[i] = sortierteHandkarten[i];
    }
}

int einfacherStrategischerWechselnderComputer(Spielkarte *computerHandkarten, const Spielkarte *gespielteKarte, int zugAnzahl) // zweiter Parameter für gelegte Karte vom Menschen
{
    // Implementation for preparing a simple strategic changing computer player
    // basic strategy for selecting a card to play
    (void)computerHandkarten;
    (void)gespielteKarte;
    (void)zugAnzahl;
    return 0;
}

int reaktiverComputer(Spielkarte *computerHandkarten, const Spielkarte *gespielteKarte, int zugAnzahl) // zweiter Param für gelegte karte des menschen
{
    // Implementation for handling the computer's move
    // reactive strategy for selecting a card to play
    return 0;
}