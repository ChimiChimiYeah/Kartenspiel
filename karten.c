#include "karten.h"

void kartenVergabe(Spielkarte *menschHandKarten, Spielkarte *computerHandKarten)
{
    // Implementation for dealing cards to players
    // Assuming a standard deck of 52 cards and dealing 10 cards each
    Spielkarte kartenStapel[52];
    kartenstapelErstellen(kartenStapel);
    kartenMischen(kartenStapel);
    kartenAusteilen(menschHandKarten, computerHandKarten, kartenStapel);

    for (int i = 0; i < 20; i++)
    {
        printf("Kartenfarbe: %s, Kartenwert: %s\n", symbolFarbe[kartenStapel[i].kartenfarbe], symbolWert[kartenStapel[i].kartenwert]);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("C Kartenfarbe: %s, C Kartenwert: %s\n", symbolFarbe[computerHandKarten[i].kartenfarbe], symbolWert[computerHandKarten[i].kartenwert]);
        printf("M Kartenfarbe: %s, M Kartenwert: %s\n", symbolFarbe[menschHandKarten[i].kartenfarbe], symbolWert[menschHandKarten[i].kartenwert]);
    }
}

void kartenstapelErstellen(Spielkarte *kartenStapel)
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
                    .kartenfarbe = (Kartenfarbe)i,
                    .kartenwert = (Kartenwert)j,
                };
            // Add card to deck
            kartenStapel[i * 13 + j] = karte;
        }
    }
}

void kartenMischen(Spielkarte *kartenStapel)
{
    // Implementation for shuffling the deck of cards
    // Shuffle the deck using fisher-yates algorithm
    /*
    -- To shuffle an array a of n elements (indices 0..n − 1):
    for i from n − 1 down to 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]
    */
    for (int i = 51; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Spielkarte zwischenSpeicher = kartenStapel[j];
        kartenStapel[j] = kartenStapel[i];
        kartenStapel[i] = zwischenSpeicher;
    }
}

void kartenAusteilen(Spielkarte *menschHandKarten, Spielkarte *computerHandKarten, Spielkarte *kartenStapel)
{
    // giving out cards for free
    for (int i = 0; i < 10; i++)
    {
        computerHandKarten[i] = kartenStapel[2 * i];
        menschHandKarten[i] = kartenStapel[2 * i + 1];
    }
}