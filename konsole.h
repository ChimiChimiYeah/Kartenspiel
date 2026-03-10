#ifndef KONSOLE_H
#define KONSOLE_H

#include <stdio.h>
#include <windows.h>
#include "karten.h"

void initialisiereKonsole(void);
void anzeigeSpielstart(void);
char *auswahlSpielername(void);
void anzeigeZug(int zugAnzahl);
void handkartenAnzeige(const Spielkarte *handkarten, int maxHandkartenIndex);
int auswahlHandkarte(int maxHandkartenIndex);
void anzeigeGespielteKarte(const char *spielername, const Spielkarte computerKarte);
void anzeigeStichSieger(const char *spielername);
void anzeigePunkte(const char *ersterSpielername, int ersterSpielerPunkte, const char *computerSpielername, int computerSpielerPunkte);
void anzeigeGewinner(const char *ersterSpielername, int ersterSpielerPunkte, const char *computerSpielername, int computerSpielerPunkte);

#endif