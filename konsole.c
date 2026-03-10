#include "konsole.h"
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// Initialisiert die Konsole (löscht Bildschirm und setzt UTF-8-Encoding)
void initialisiereKonsole(void)
{
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
}

// Zeigt die Willkommensnachricht beim Spielstart an
void anzeigeSpielstart(void)
{
    printf("Herzlich Willkommen beim allerneusten, super-interessanten, von allen gespielten DHBW-Kartenspiel in C.\n");
}

// Fragt den Spielernamen ab und allokiert dynamisch Speicher dafür
// Return: Zeiger auf den eingegebenen Namen (muss später mit free() freigegeben werden)
//         oder NULL bei Speicherfehler
char *auswahlSpielername(void)
{
    size_t bufferSize = 50;
    size_t length = 0;
    char *buffer = (char *)malloc(bufferSize);

    if (buffer == NULL)
    {
        return NULL;
    }

    printf("\nBitte gebe zuerst deinen Namen ein: ");
    fflush(stdout);
    int c;
    // Liest Zeichen ein, bis Newline oder EOF erreicht wird
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Vergrößert den Buffer bei Bedarf
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

// Zeigt die Zugnummer an
// Parameter:
// - int zugAnzahl: Nummer des aktuellen Zugs (1-10)
void anzeigeZug(int zugAnzahl)
{
    printf("\n══════════════════════════════════════════════════════");
    printf("\n[Zug %d]\n", zugAnzahl);
}

// Gibt die Handkarten des Spielers formatiert im Terminal aus
// Parameter:
// - const Spielkarte *handkarten: Liste der Handkarten des Spielers
// - int maxHandkartenIndex: Höchster gültiger Index der Handkarten
void handkartenAnzeige(const Spielkarte *handkarten, int maxHandkartenIndex)
{
    printf("\nDu bist am Zug!\n");
    printf("\nDeine Handkarten sind:\n");

    // Obere Kartenkante
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("╭─────╮   ");
    }
    printf("\n");

    // Obere Zeile mit Wert und Farbe
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("│%-2s  %s│   ", symbolWert[handkarten[i].kartenwert - 2], symbolFarbe[handkarten[i].kartenfarbe]);
    }
    printf("\n");

    // Mittlere leere Zeile
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("│     │   ");
    }
    printf("\n");

    // Untere Zeile mit Farbe und Wert
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("│%s  %2s│   ", symbolFarbe[handkarten[i].kartenfarbe], symbolWert[handkarten[i].kartenwert - 2]);
    }
    printf("\n");

    // Untere Kartenkante
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("╰─────╯   ");
    }
    printf("\n");

    // Indexanzeige unter den Karten
    for (int i = 0; i <= maxHandkartenIndex; i++)
    {
        printf("Index: %d  ", i);
    }
    printf("\n");
}

// Fragt den Spieler nach dem Index der zu spielenden Karte
// Parameter:
// - int maxHandkartenIndex: Höchster gültiger Index der Handkarten
// Return: Gültiger Index der gewählten Karte (0 bis maxHandkartenIndex)
int auswahlHandkarte(int maxHandkartenIndex)
{
    int index;
    int c;
    printf("\nSchreibe den Index der Karte, die du legen willst: ");
    fflush(stdout);

    // Wiederholt die Eingabe, bis ein gültiger Index eingegeben wurde
    while (scanf("%d", &index) != 1 || index < 0 || index > maxHandkartenIndex)
    {
        // Leert den Input-Buffer
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Ungültige Eingabe. Bitte Index 0-%d eingeben: ", maxHandkartenIndex);
    }

    // Leert den Input-Buffer nach erfolgreicher Eingabe
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return index;
}

// Zeigt eine gespielte Karte formatiert an
// Parameter:
// - const char *spielername: Name des Spielers, der die Karte gelegt hat
// - const Spielkarte computerKarte: Die gespielte Karte
void anzeigeGespielteKarte(const char *spielername, const Spielkarte computerKarte)
{
    printf("\n%s hat gelegt:\n", spielername);
    printf("╭─────╮\n");
    printf("│%-2s  %s│\n", symbolWert[computerKarte.kartenwert - 2], symbolFarbe[computerKarte.kartenfarbe]);
    printf("│     │\n");
    printf("│%s  %2s│\n", symbolFarbe[computerKarte.kartenfarbe], symbolWert[computerKarte.kartenwert - 2]);
    printf("╰─────╯\n");
}

// Zeigt den Gewinner des aktuellen Stichs an
// Parameter:
// - const char *spielername: Name des Spielers, der den Stich gewonnen hat
void anzeigeStichSieger(const char *spielername)
{
    printf("\n%s hat den Stich gewonnen!\n", spielername);
}

// Zeigt den Endstand des Spiels an
// Parameter:
// - const char *ersterSpielername: Name des ersten Spielers (Mensch)
// - int ersterSpielerPunkte: Punktzahl des ersten Spielers
// - const char *computerSpielername: Name des zweiten Spielers (Computer)
// - int computerSpielerPunkte: Punktzahl des zweiten Spielers
void anzeigePunkte(const char *ersterSpielername, int ersterSpielerPunkte, const char *computerSpielername, int computerSpielerPunkte)
{
    printf("\n╔══════════════════════════════════╗");
    printf("\n║            Endstand:             ║");
    printf("\n╚══════════════════════════════════╝\n\n");
    printf("%s hat %d Punkt(e) erzielt.\n", ersterSpielername, ersterSpielerPunkte);
    printf("%s hat %d Punkt(e) erzielt.\n", computerSpielername, computerSpielerPunkte);
}

// Zeigt den Gewinner des Spiels an
// Parameter:
// - const char *ersterSpielername: Name des ersten Spielers (Mensch)
// - int ersterSpielerPunkte: Punktzahl des ersten Spielers
// - const char *computerSpielername: Name des zweiten Spielers (Computer)
// - int computerSpielerPunkte: Punktzahl des zweiten Spielers
// Hinweis: Bei Gleichstand gewinnt der menschliche Spieler
void anzeigeGewinner(const char *ersterSpielername, int ersterSpielerPunkte, const char *computerSpielername, int computerSpielerPunkte)
{
    printf("\n══════════════════════════════════════════════════════\n");
    if (ersterSpielerPunkte > computerSpielerPunkte)
        printf("%s hat das Spiel gewonnen! Gut gemacht!\n", ersterSpielername);
    else if (computerSpielerPunkte > ersterSpielerPunkte)
        printf("Leider verloren! %s hat das Spiel gewonnen!\n", computerSpielername);
    else
        printf("Ihr habt gleich viele Punkte! Damit gewinnt %s!\n", ersterSpielername);
    printf("══════════════════════════════════════════════════════\n");
}
