#include "spieler.h"

void initialisiereSpieler(spieler *mensch, spieler *computer)
{
    // Implementation for initializing player data
    // Initialize human player
    mensch->punkte = 0;
    mensch->zugPointer = &spielerzug;
    mensch->spielername = spielername();

    // Initialize computer player
    computer->punkte = 0;
    computer->zugPointer = zufaelligeComputerStrategie;
    computer->spielername = "Computer";
}

char *spielername(void)
{
    // Implementation for getting and setting the player's name
    return "Mensch";
}

void spielerzug(void)
{
    // Implementation for handling the player's move
    // show available hand cards
    // get players input for the played card
    // validate the move
}

void zufaelligeComputerStrategie(void)
{
    // implementation to set a random computer strategy
    // random selection of one of the four strategies
    // einfach, strategisch, wechselnd, reaktiv
}

void vorbereitungStrategischerComputer(void)
{
    // implmentation for sorting the computer's hand cards
    // sorting cards in descending order based on their value
}

void vorbereitungWechselnderComputer(void)
{
    // implementation for sorting the computer's hand cards
    // sorting cards to alternate between low and high value cards
}

void einfacherStrategischerWechselnderComputer(void)
{
    // Implementation for preparing a simple strategic changing computer player
    // basic strategy for selecting a card to play
}

void reaktiverComputer(void)
{
    // Implementation for handling the computer's move
    // reactive strategy for selecting a card to play
}