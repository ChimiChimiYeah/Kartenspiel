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

int spielerzug(Spielkarte *menschHandkarten, Spielkarte *gespielteKarte, int zugAnzahl)
{
    // Implementation for handling the player's move
    (void)gespielteKarte;
    int indexGewaehlterKarte;

    handkartenAnzeige(menschHandkarten, zugAnzahl);
    indexGewaehlterKarte = auswahlHandkarte();
    return indexGewaehlterKarte;
}

void zufaelligeComputerStrategie(Spieler *computer)
{
    // implementation to set a random computer strategy
    // random selection of one of the four strategies
    // einfach, strategisch, wechselnd, reaktiv
    int zufallsZahl = rand() % 4;
    switch (zufallsZahl)
    {
    case 0:
        computer->zugPointer = &einfacherStrategischerWechselnderComputer;
    case 1:
        vorbereitungStrategischerComputer(computer->handkarten);
        computer->zugPointer = &einfacherStrategischerWechselnderComputer;
        break;
    case 2:
        vorbereitungWechselnderComputer(computer->handkarten);
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

void vorbereitungStrategischerComputer(Spielkarte *computerHandkarten)
{
    // implmentation for sorting the computer's hand cards
    // sorting cards in descending order based on their value
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
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

void vorbereitungWechselnderComputer(Spielkarte *computerHandkarten)
{
    // implementation for sorting the computer's hand cards
    // sorting cards to alternate between low and high value cards
    vorbereitungStrategischerComputer(&computerHandkarten[0]);
    Spielkarte sortierteHandkarten[10];
    for (int i = 0; i < 10 / 2; i++)
    {
        sortierteHandkarten[i * 2] = computerHandkarten[9 - i];
        sortierteHandkarten[i * 2 + 1] = computerHandkarten[i];
    }
    if ((10 % 2) == 1)
    {
        sortierteHandkarten[10 - 1] = computerHandkarten[10 / 2 + 1];
    }
    for (int i = 0; i < 10; i++)
    {
        computerHandkarten[i] = sortierteHandkarten[i];
    }
}

int einfacherStrategischerWechselnderComputer(Spielkarte *computerHandkarten, Spielkarte *gespielteKarte, int zugAnzahl) // zweiter Parameter für gelegte Karte vom Menschen
{
    // Implementation for preparing a simple strategic changing computer player
    // basic strategy for selecting a card to play
    (void)computerHandkarten;
    (void)gespielteKarte;
    (void)zugAnzahl;
    return 0;
}

int reaktiverComputer(Spielkarte *computer, Spielkarte *gespielteKarte, int zugAnzahl) // zweiter Param für gelegte karte des menschen
{
    // Implementation for handling the computer's move
    // reactive strategy for selecting a card to play
    return 0;
}