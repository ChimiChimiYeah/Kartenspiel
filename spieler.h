// Struktur und Funktionen für Spieler im Kartenspiel
typedef struct
{
    char *spielername;         // name des spielers
    Spielkarte handkarten[10]; // maximal 10 karten
    int punkte;                // startpunkte
    void (*zugPointer)();      // funktionspointer
} spieler;

void spielername(char *spielername);
void spielerzug();

void zufaelligerComputerZug();
void vorbereitungStrategischerComputer();
void vorbereitungWechselnderComputer();
void einfacheStrategischWechselnderComputer();
void reaktiverComputer();