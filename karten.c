#include "karten.h"

void kartenstapelErstellen(void)
{
    // Implementation for creating the deck of cards
    // Create a standard 52-card deck
    // Initialize the deck with all 52 cards
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            // Create card with Kartenwert i and Kartenfarbe j
            Spielkarte karte =
                {
                    .Kartenfarbe = (Kartenfarbe)i,
                    .Kartenwert = (Kartenwert)j,
                };
            // Add card to deck (implementation of deck storage not shown)
        }
    }
}