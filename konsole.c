#include "konsole.h"

void initialisiereKonsole()
{
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    fflush(stdin);
}

/*
Gibt die Handkarten des Spielers im Terminal aus
Parameter:
- Struct "Spielkarte" mit den Handkarten des Spielers
- int anzahlHandkarten, um alle Handkarten des Spielers auszugeben
*/
void handkartenAnzeige(const Spielkarte *handkarten, int anzahlHandkarten)
{
    printf("Deine Handkarten sind:\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("+=====+   ");
    }
    printf("\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("|%-2s  %s|   ", symbolWert[handkarten[i].kartenwert], symbolFarbe[handkarten[i].kartenfarbe]);
    }
    printf("\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("|     |   ");
    }
    printf("\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("|%s  %2s|   ", symbolFarbe[handkarten[i].kartenfarbe], symbolWert[handkarten[i].kartenwert]);
    }
    printf("\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("+=====+   ");
    }
    printf("\n");
    for (int i = 0; i <= anzahlHandkarten; i++)
    {
        printf("Index: %d  ", i);
    }
    printf("\n");
}

int auswahlHandkarte(int anzahlHandkarten)
{
    int index;
    int c;
    printf("Schreibe den Index der Karte, die du legen willst: ");
    fflush(stdout);
    while (scanf("%d", &index) != 1 || index < 0 || index > anzahlHandkarten)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ; // clear buffer
        printf("Ungültige Eingabe. Bitte Index 0-%d eingeben: ", anzahlHandkarten);
    }
    return index;
}

void anzeigeGespielteKarte(const char *spielername, const Spielkarte computerKarte)
{
    printf("%s hat gelegt:\n", spielername);
    printf("+=====+\n");
    printf("|%-2s  %s|\n", symbolWert[computerKarte.kartenwert], symbolFarbe[computerKarte.kartenfarbe]);
    printf("|     |\n");
    printf("|%s  %2s|\n", symbolFarbe[computerKarte.kartenfarbe], symbolWert[computerKarte.kartenwert]);
    printf("+=====+\n");
}