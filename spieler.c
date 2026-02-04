#include "spieler.h"

void initialisiereSpieler(Spieler *mensch, Spieler *computer)
{
    // Implementation for initializing player data
    // Initialize human player
    mensch->spielername = spielername();
    // Handkarten werden später verteilt
    mensch->punkte = 0;
    mensch->zugPointer = &spielerzug;

    // Initialize computer player
    computer->spielername = "Computer";
    // Handkarten werden später verteilt
    computer->punkte = 0;
    // Computergegner wird gesetzt, wenn Handkarten verteilt sind
}

char *spielername(void)
{
    // Implementation for getting and setting the player's name
    return "Mensch";
}

int spielerzug(Spielkarte *menschHandkarten, const Spielkarte *gespielteKarte, int zugAnzahl)
{
    // Implementation for handling the player's move
    (void)gespielteKarte;
    int indexGewaehlterKarte;

    handkartenAnzeige(menschHandkarten, zugAnzahl);
    indexGewaehlterKarte = auswahlHandkarte();
    return indexGewaehlterKarte;
}

int auswahlHandkarte()
{
    return 0;
}

void zufaelligeComputerStrategie(Spieler *computer)
{
    // implementation to set a random computer strategy
    // random selection of one of the four strategies
    // einfach, strategisch, wechselnd, reaktiv
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

void sortiereHandkartenGrossNachKlein(Spielkarte *computerHandkarten)
{
    // implmentation for sorting the computer's hand cards
    // sorting cards in descending order based on their value
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

void sortiereHandkartenKleinsteGroesste(Spielkarte *computerHandkarten)
{
    // implementation for sorting the computer's hand cards
    // sorting cards to alternate between low and high value cards
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