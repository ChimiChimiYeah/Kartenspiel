#ifndef AUSGABE_H
#define AUSGABE_H

#include <stdio.h>
#include <windows.h>
#include "spieler.h"

void gotoxy(short x, short y);
void initialisiereKonsole();
void handkartenAnzeige(const Spielkarte *handkarten, int zugAnzahl);

#endif