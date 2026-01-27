#ifndef KARTEN_H
#define KARTEN_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    Karo = 0,
    Herz,
    Pik,
    Kreuz
} Kartenfarbe;

typedef enum
{
    Zwei = 0,
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

void kartenVergabe(Spielkarte *menschHandKarten, Spielkarte *computerHandKarten);
void kartenstapelErstellen(Spielkarte *kartenStapel);
void kartenMischen(Spielkarte *kartenStapel);
void kartenAusteilen(Spielkarte *menschHandKarten, Spielkarte *computerHandKarten, Spielkarte *kartenStapel);

#endif