#ifndef AUSGABE_H
#define AUSGABE_H

#include <stdio.h>
#include <windows.h>
#include "spieler.h"
#include "karten.h"

void initialisiereKonsole();
void handkartenAnzeige(const Spielkarte *handkarten, int anzahlHandkarten);
int auswahlHandkarte(int anzahlHandkarten);
void anzeigeGespielteComputerKarte(const Spielkarte computerKarte);

#endif