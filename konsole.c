#include "konsole.h"
#include <windows.h>
#include <string.h>
#include <stdlib.h>

void initialisiereKonsole()
{
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
}

char *auswahlSpielername(void)
{
    size_t bufferSize = 50;
    size_t length = 0;
    char *buffer = (char *)malloc(bufferSize);

    if (buffer == NULL)
    {
        return NULL;
    }

    printf("Gib deinen Namen ein: ");
    fflush(stdout);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (length >= bufferSize - 1)
        {
            bufferSize *= 2;
            char *newBuffer = (char *)realloc(buffer, bufferSize);
            if (newBuffer == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = newBuffer;
        }
        buffer[length++] = (char)c;
    }

    buffer[length] = '\0';
    return buffer;
}

void anzeigeZug(int zugAnzahl)
{
    printf("[Zug %d]\n", zugAnzahl);
}

/*
Gibt die Handkarten des Spielers im Terminal aus
Parameter:
- Struct "Spielkarte" mit den Handkarten des Spielers
- int maxHandkartenIndex, um alle Handkarten des Spielers auszugeben
*/
void handkartenAnzeige(const Spielkarte *handkarten, int maxHandkartenIndex)
{
    printf("Deine Handkarten sind:\n");
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("+=====+   ");
    }
    printf("\n");
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("|%-2s  %s|   ", symbolWert[handkarten[i].kartenwert - 2], symbolFarbe[handkarten[i].kartenfarbe]);
    }
    printf("\n");
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("|     |   ");
    }
    printf("\n");
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("|%s  %2s|   ", symbolFarbe[handkarten[i].kartenfarbe], symbolWert[handkarten[i].kartenwert - 2]);
    }
    printf("\n");
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("+=====+   ");
    }
    printf("\n");
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("Index: %d  ", i);
    }
    printf("\n");
}

int auswahlHandkarte(int maxHandkartenIndex)
{
    int index;
    int c;
    printf("Schreibe den Index der Karte, die du legen willst: ");
    fflush(stdout);
    while (scanf("%d", &index) != 1 || index < 0 || index > maxHandkartenIndex)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Ungültige Eingabe. Bitte Index 0-%d eingeben: ", maxHandkartenIndex);
    }
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return index;
}

void anzeigeGespielteKarte(const char *spielername, const Spielkarte computerKarte)
{
    printf("%s hat gelegt:\n", spielername);
    printf("+=====+\n");
    printf("|%-2s  %s|\n", symbolWert[computerKarte.kartenwert - 2], symbolFarbe[computerKarte.kartenfarbe]);
    printf("|     |\n");
    printf("|%s  %2s|\n", symbolFarbe[computerKarte.kartenfarbe], symbolWert[computerKarte.kartenwert - 2]);
    printf("+=====+\n");
}

void anzeigeStichSieger(const char *spielername)
{
    printf("%s hat den Stich gewonnen!\n", spielername);
}

void anzeigePunkte(const char *ersterSpielername, int ersterSpielerPunkte, const char *computerSpielername, int computerSpielerPunkte)
{
    printf("Endstand:\n");
    printf("%s hat %d Punkt(e) erzielt.\n", ersterSpielername, ersterSpielerPunkte);
    printf("%s hat %d Punkt(e) erzielt.\n", computerSpielername, computerSpielerPunkte);
}

void anzeigeGewinner(const char *ersterSpielername, int ersterSpielerPunkte, const char *computerSpielername, int computerSpielerPunkte)
{
    if (ersterSpielerPunkte > computerSpielerPunkte)
        printf("%s hat das Spiel gewonnen! Gut gemacht!\n", ersterSpielername);
    else if (computerSpielerPunkte > ersterSpielerPunkte)
        printf("Leider verloren! %s hat das Spiel gewonnen!\n", computerSpielername);
    else
        printf("Ihr habt gleich viele Punkte! Damit gewinnt %s!\n", ersterSpielername);
}