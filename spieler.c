#include "spieler.h"
#include "konsole.h"

// Initialisiert die Spieler-Structs für Mensch und Computer
// Parameter:
// - Spieler *mensch: Zeiger auf den Spieler-Struct des Menschen
// - Spieler *computer: Zeiger auf den Spieler-Struct des Computers
void initialisiereSpieler(Spieler *mensch, Spieler *computer)
{
    // Initialisiere den Menschen
    mensch->spielername = spielername();
    // Handkarten werden später verteilt
    mensch->punkte = 0;
    mensch->zugPointer = &spielerzug;

    // Initialisiere den Computer
    computer->spielername = "Computer";
    // Handkarten werden später verteilt
    computer->punkte = 0;
    // Computerstrategie wird später zufällig gewählt
}

// Fragt den Spielernamen ab
// Return: Zeiger auf den eingegebenen Namen
char *spielername(void)
{
    return auswahlSpielername();
}

// Implementierung des Zuges des menschlichen Spielers
// Zeigt die Handkarten an und lässt den Spieler eine Karte wählen
// Parameter:
// - Spielkarte *menschHandkarten: Liste der Handkarten des Spielers
// - const Spielkarte *gespielteKarte: Bereits gespielte Karte (wird hier nicht verwendet)
// - int maxHandkartenIndex: Höchster gültiger Index der Handkarten
// Return: Index der gewählten Karte
int spielerzug(Spielkarte *menschHandkarten, const Spielkarte *gespielteKarte, int maxHandkartenIndex)
{
    (void)gespielteKarte; // Parameter wird nicht verwendet
    int indexGewaehlterKarte;
    handkartenAnzeige(menschHandkarten, maxHandkartenIndex);
    indexGewaehlterKarte = auswahlHandkarte(maxHandkartenIndex);
    return indexGewaehlterKarte;
}

// Wählt zufällig eine Strategie für den Computergegner und sortiert die Karten entsprechend
// Parameter:
// - Spieler *computer: Zeiger auf den Computer-Spieler
// Strategien:
// - 0: Einfacher Gegner (spielt Karten der Reihe nach, unsortiert)
// - 1: Strategischer Gegner (spielt von höchster zu niedrigster Karte)
// - 2: Wechselnder Gegner (spielt abwechselnd kleinste und größte Karte)
// - 3: Reaktiver Gegner (versucht zu übertrumpfen, sonst kleinste Karte)
void zufaelligeComputerStrategie(Spieler *computer)
{
    int zufallsZahl = rand() % 4;

    // Sortiere Karten für strategischen und wechselnden Gegner
    if (zufallsZahl != 0)
        sortiereHandkartenGrossNachKlein(computer->handkarten);

    // Zusätzliche Sortierung für wechselnden Gegner
    if (zufallsZahl == 2)
        sortiereHandkartenKleinsteGroesste(computer->handkarten);

    // Setze Funktionszeiger entsprechend der gewählten Strategie
    switch (zufallsZahl)
    {
    case 0: // Einfacher Gegner
    case 1: // Strategischer Gegner
    case 2: // Wechselnder Gegner
        computer->zugPointer = &einfacherStrategischerWechselnderComputer;
        break;
    case 3: // Reaktiver Gegner
        computer->zugPointer = &reaktiverComputer;
        break;
    default:
        computer->zugPointer = &reaktiverComputer;
        break;
    }
}

// Sortiert die Handkarten von größtem zu kleinstem Wert (Bubble Sort)
// Parameter:
// - Spielkarte *computerHandkarten: Liste der zu sortierenden Handkarten
void sortiereHandkartenGrossNachKlein(Spielkarte *computerHandkarten)
{
    for (int i = 0; i < HANDKARTEN_ANZAHL - 1; i++)
    {
        for (int j = i + 1; j < HANDKARTEN_ANZAHL; j++)
        {
            if (computerHandkarten[i].kartenwert < computerHandkarten[j].kartenwert)
            {
                Spielkarte zwischenSpeicher = computerHandkarten[i];
                computerHandkarten[i] = computerHandkarten[j];
                computerHandkarten[j] = zwischenSpeicher;
            }
        }
    }
}

// Sortiert die Handkarten abwechselnd: kleinste, größte, zweitkleinste, zweitgrößte, ...
// Parameter:
// - Spielkarte *computerHandkarten: Liste der zu sortierenden Handkarten
// Voraussetzung: Karten müssen bereits von groß nach klein sortiert sein
void sortiereHandkartenKleinsteGroesste(Spielkarte *computerHandkarten)
{
    Spielkarte sortierteHandkarten[10];

    // Fülle Array abwechselnd mit größten und kleinsten Karten
    for (int i = 0; i < HANDKARTEN_ANZAHL / 2; i++)
    {
        sortierteHandkarten[i * 2] = computerHandkarten[(HANDKARTEN_ANZAHL - 1) - i]; // Kleinste
        sortierteHandkarten[i * 2 + 1] = computerHandkarten[i];                       // Größte
    }

    // Bei ungerader Anzahl: Füge mittlere Karte am Ende hinzu
    if ((HANDKARTEN_ANZAHL % 2) == 1)
    {
        sortierteHandkarten[HANDKARTEN_ANZAHL - 1] = computerHandkarten[HANDKARTEN_ANZAHL / 2];
    }

    // Kopiere sortiertes Array zurück in die Handkarten
    for (int i = 0; i < HANDKARTEN_ANZAHL; i++)
    {
        computerHandkarten[i] = sortierteHandkarten[i];
    }
}

// Implementierung für einfachen, strategischen und wechselnden Computergegner
// Spielt immer die erste Karte in der (vorsortierten) Liste
// Parameter:
// - Spielkarte *computerHandkarten: Liste der Handkarten (wird nicht verwendet)
// - const Spielkarte *gespielteKarte: Bereits gespielte Karte (wird nicht verwendet)
// - int maxHandkartenIndex: Höchster gültiger Index (wird nicht verwendet)
// Return: Immer 0 (erste Karte in der Liste)
int einfacherStrategischerWechselnderComputer(Spielkarte *computerHandkarten, const Spielkarte *gespielteKarte, int maxHandkartenIndex)
{
    (void)computerHandkarten; // Parameter wird nicht verwendet
    (void)gespielteKarte;     // Parameter wird nicht verwendet
    (void)maxHandkartenIndex; // Parameter wird nicht verwendet
    return 0;                 // Spielt immer die erste Karte
}

// Implementierung für reaktiven Computergegner
// Versucht die Karte des Gegners zu übertrumpfen, sonst spielt er die kleinste Karte
// Parameter:
// - Spielkarte *computerHandkarten: Liste der Handkarten des Computers
// - const Spielkarte *gespielteKarte: Bereits gespielte Karte des Gegners (NULL wenn Computer beginnt)
// - int maxHandkartenIndex: Höchster gültiger Index der Handkarten
// Return: Index der zu spielenden Karte
int reaktiverComputer(Spielkarte *computerHandkarten, const Spielkarte *gespielteKarte, int maxHandkartenIndex)
{
    // Wenn Computer beginnt, spiele erste Karte
    if (gespielteKarte == NULL)
        return 0;
    else
    {
        // Suche nach einer Karte, die die gespielte Karte übertrumpft
        for (int i = 0; i <= maxHandkartenIndex; i++)
        {
            if (gespielteKarte->kartenwert < computerHandkarten[i].kartenwert)
                return i; // Übertrumpfe mit dieser Karte
        }

        // Keine höhere Karte gefunden, spiele kleinste Karte (Index 0)
        return 0;
    }
}