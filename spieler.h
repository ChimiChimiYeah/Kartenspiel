#ifndef SPIELER_H
#define SPIELER_H

#include <time.h>
#include <stdlib.h>
#include "karten.h"

// Struktur und Funktionen für Spieler im Kartenspiel
typedef struct Spieler
{
    char *spielername;                                                                // name des spielers
    Spielkarte handkarten[HANDKARTEN_ANZAHL];                                         // maximal 10 karten
    int punkte;                                                                       // startpunkte
    int (*zugPointer)(Spielkarte *, const Spielkarte *gespielteKarte, int zugAnzahl); // funktionspointer
} Spieler;

void initialisiereSpieler(Spieler *mensch, Spieler *computer);

char *spielername(void);
int spielerzug(Spielkarte *menschHandkarten, const Spielkarte *gespielteKarte, int zugAnzahl);

void zufaelligeComputerStrategie(Spieler *computer);
void sortiereHandkartenGrossNachKlein(Spielkarte *computerHandkarten);
void sortiereHandkartenKleinsteGroesste(Spielkarte *computerHandkarten);
int einfacherStrategischerWechselnderComputer(Spielkarte *computerHandkarten, const Spielkarte *gespielteKarte, int zugAnzahl);
int reaktiverComputer(Spielkarte *computerHandkarten, const Spielkarte *gespielteKarte, int zugAnzahl);

#endif