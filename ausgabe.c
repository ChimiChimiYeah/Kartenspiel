#include "ausgabe.h"

void test(Spieler *computer)
{
    printf("\n============================================\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("C Kartenfarbe: %s, C Kartenwert: %s\n", symbolFarbe[computer->handkarten[i].kartenfarbe], symbolWert[computer->handkarten[i].kartenwert]);
        // printf("M Kartenfarbe: %s, M Kartenwert: %s\n", symbolFarbe[mensch.handkarten[i].kartenfarbe], symbolWert[mensch.handkarten[i].kartenwert]);
    }
}

void handkartenAnzeige(Spielkarte *handkarten, int zugAnzahl)
{
}