#ifndef AUSGABE_H
#define AUSGABE_H

#include <stdio.h>
#include <windows.h>
#include "spieler.h"
#include "karten.h"

void initialisiereKonsole();
void handkartenAnzeige(const Spielkarte *handkarten, int zugAnzahl);
void anzeigeGespielteComputerKarte(const Spielkarte computerKarte);

#endif