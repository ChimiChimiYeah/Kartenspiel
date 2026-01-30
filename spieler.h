#ifndef SPIELER_H
#define SPIELER_H

#include <time.h>
#include <stdlib.h>
#include "karten.h"

// Struktur und Funktionen für Spieler im Kartenspiel
typedef struct
{
    char *spielername;                                            // name des spielers
    Spielkarte handkarten[10];                                    // maximal 10 karten
    int punkte;                                                   // startpunkte
    void (*zugPointer)(Spielkarte *, Spielkarte *gespielteKarte); // funktionspointer
} Spieler;

void initialisiereSpieler(Spieler *mensch, Spieler *computer);

char *spielername(void);
int spielerzug(Spielkarte *menschHandkarten, Spielkarte *gespielteKarte, int zugAnzahl);

void zufaelligeComputerStrategie(Spieler *computer);
void vorbereitungStrategischerComputer(Spielkarte *computerHandkarten);
void vorbereitungWechselnderComputer(Spielkarte *computerHandkarten);
int einfacherStrategischerWechselnderComputer(Spielkarte *computerHandkarten, Spielkarte *gespielteKarte, int zugAnzahl);
int reaktiverComputer(Spielkarte *computerHandkarten, Spielkarte *gespielteKarte, int zugAnzahl);

#endif