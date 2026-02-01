#ifndef SPIELER_H
#define SPIELER_H

#include <time.h>
#include <stdlib.h>
#include "karten.h"

#define RUNDEN_ANZAHL 10

// Struktur und Funktionen für Spieler im Kartenspiel
typedef struct
{
    char *spielername;                                                          // name des spielers
    Spielkarte handkarten[ANZAHL_HANDKARTEN];                                   // maximal 10 karten
    int punkte;                                                                 // startpunkte
    int (*zugPointer)(Spielkarte *, Spielkarte *gespielteKarte, int zugAnzahl); // funktionspointer
} Spieler;

void initialisiereSpieler(Spieler *mensch, Spieler *computer);

char *spielername(void);
int spielerzug(Spielkarte *menschHandkarten, Spielkarte *gespielteKarte, int zugAnzahl);
int auswahlHandkarte();

void zufaelligeComputerStrategie(Spieler *computer);
void vorbereitungStrategischerComputer(Spielkarte *computerHandkarten);
void vorbereitungWechselnderComputer(Spielkarte *computerHandkarten);
int einfacherStrategischerWechselnderComputer(Spielkarte *computerHandkarten, Spielkarte *gespielteKarte, int zugAnzahl);
int reaktiverComputer(Spielkarte *computerHandkarten, Spielkarte *gespielteKarte, int zugAnzahl);

#endif