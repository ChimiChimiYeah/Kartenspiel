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
} spieler;

void initialisiereSpieler(spieler *mensch, spieler *computer);

char *spielername(void);
void spielerzug(Spielkarte *menschHandkarte, Spielkarte *gespielteKarte);

void zufaelligeComputerStrategie(spieler *computer);
void vorbereitungStrategischerComputer(Spielkarte *computerHandkarten);
void vorbereitungWechselnderComputer(Spielkarte *computerHandkarten);
void einfacherStrategischerWechselnderComputer(Spielkarte *computerHandkarten, Spielkarte *gespielteKarte);
void reaktiverComputer(Spielkarte *computerHandkarten, Spielkarte *gespielteKarte);

#endif