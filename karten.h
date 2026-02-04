#ifndef KARTEN_H
#define KARTEN_H

#include <time.h>
#include <stdlib.h>

#define FARBEN_ANZAHL 4
#define WERTE_ANZAHL 13
#define HANDKARTEN_ANZAHL 10
#define DECK_GROESSE 52

typedef enum
{
    Karo,
    Herz,
    Pik,
    Kreuz
} Kartenfarbe;

typedef enum
{
    Zwei,
    Drei,
    Vier,
    Fuenf,
    Sechs,
    Sieben,
    Acht,
    Neun,
    Zehn,
    Bube,
    Dame,
    Koenig,
    Ass
} Kartenwert;

extern const char *symbolFarbe[];
extern const char *symbolWert[];

typedef struct
{
    Kartenfarbe kartenfarbe;
    Kartenwert kartenwert;
} Spielkarte;

void kartenVergabe(Spielkarte *menschHandkarten, Spielkarte *computerHandkarten);
void kartenstapelErstellen(Spielkarte *kartenStapel);
void kartenMischen(Spielkarte *kartenStapel);
void kartenAusteilen(Spielkarte *kartenStapel, Spielkarte *menschHandKarten, Spielkarte *computerHandkarten);

int auswahlHandkarte();

void karteLegen();

#endif