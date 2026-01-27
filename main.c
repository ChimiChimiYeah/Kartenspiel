#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "karten.h"
#include "spieler.h"

int main()
{
    spieler mensch;
    spieler computer;
    srand(time(NULL));
    SetConsoleOutputCP(CP_UTF8);
    initialisiereSpieler(&mensch, &computer);

    kartenVergabe(&mensch.handkarten[0], &computer.handkarten[0]);
    zufaelligeComputerStrategie(&computer);
    for (int i = 0; i < 10; i++)
    {
        printf("C Kartenfarbe: %s, C Kartenwert: %s\n", symbolFarbe[computer.handkarten[i].kartenfarbe], symbolWert[computer.handkarten[i].kartenwert]);
        // printf("M Kartenfarbe: %s, M Kartenwert: %s\n", symbolFarbe[mensch.handkarten[i].kartenfarbe], symbolWert[mensch.handkarten[i].kartenwert]);
    }
    vorbereitungStrategischerComputer(&computer.handkarten[0]);
    printf("\n============================================\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("C Kartenfarbe: %s, C Kartenwert: %s\n", symbolFarbe[computer.handkarten[i].kartenfarbe], symbolWert[computer.handkarten[i].kartenwert]);
        // printf("M Kartenfarbe: %s, M Kartenwert: %s\n", symbolFarbe[mensch.handkarten[i].kartenfarbe], symbolWert[mensch.handkarten[i].kartenwert]);
    }
    printf("Spieler: %s, Punkte: %d\n", mensch.spielername, mensch.punkte);
    printf("Computer: %s, Punkte: %d\n", computer.spielername, computer.punkte);

    return 0;
}