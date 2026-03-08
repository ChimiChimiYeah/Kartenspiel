#ifndef KONSOLE_H
#define KONSOLE_H

#include <stdio.h>
#include <windows.h>
#include "karten.h"

void initialisiereKonsole();
void handkartenAnzeige(const Spielkarte *handkarten, int anzahlHandkarten);
int auswahlHandkarte(int anzahlHandkarten);
void anzeigeGespielteKarte(const char *spielername, const Spielkarte computerKarte);

#endif