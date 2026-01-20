#include "karten.c"

typedef struct
{
    // name
    Spielkarte handkarten[10]; // maximal 10 karten
    int punkte;                // startpunkte
    void (*zugPointer)();      // funktionspointer
} spieler;

void spielername();
void spielerzug();