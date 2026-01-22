// Struktur und Funktionen für Spieler im Kartenspiel
typedef struct
{
    char *spielername;         // name des spielers
    Spielkarte handkarten[10]; // maximal 10 karten
    int punkte;                // startpunkte
    void (*zugPointer)(void);  // funktionspointer
} spieler;

void initialisiereSpieler(spieler *mensch, spieler *computer);

char *spielername(void);
void spielerzug(void);

void zufaelligeComputerStrategie(void);
void vorbereitungStrategischerComputer(void);
void vorbereitungWechselnderComputer(void);
void einfacherStrategischerWechselnderComputer(void);
void reaktiverComputer(void);