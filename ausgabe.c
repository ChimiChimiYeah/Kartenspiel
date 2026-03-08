#include "ausgabe.h"

void initialisiereKonsole()
{
    // system("cls");
    // SetConsoleOutputCP(CP_UTF8);
}

/*
Gibt die Handkarten des Spielers im Terminal aus
Parameter:
- Struct "Spielkarte" mit den Handkarten des Spielers
- int anzahlHandkarten, um alle Handkarten des Spielers auszugeben
*/
void handkartenAnzeige(const Spielkarte *handkarten, int anzahlHandkarten)
{
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("+=====+  ");
    }
    printf("\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("|%-2s  %s|  ", symbolWert[handkarten[i].kartenwert], symbolFarbe[handkarten[i].kartenfarbe]);
    }
    printf("\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("|     |  ");
    }
    printf("\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("|%s  %2s|  ", symbolFarbe[handkarten[i].kartenfarbe], symbolWert[handkarten[i].kartenwert]);
    }
    printf("\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("+=====+  ");
    }
    printf("\n");
}

void anzeigeGespielteComputerKarte(const Spielkarte computerKarte)
{
    printf("+=====+\n");
    printf("|%-2s  %s|\n", symbolWert[computerKarte.kartenwert], symbolFarbe[computerKarte.kartenfarbe]);
    printf("|     |\n");
    printf("|%s  %2s|\n", symbolFarbe[computerKarte.kartenfarbe], symbolWert[computerKarte.kartenwert]);
    printf("+=====+\n");
}