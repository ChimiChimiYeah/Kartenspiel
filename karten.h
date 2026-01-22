typedef enum
{
    Karo = 0,
    Herz,
    Pik,
    Kreuz
} Kartenfarbe;

typedef enum
{
    Zwei = 0,
    Drei,
    Vier,
    Fuenf,
    Sechs,
    Sieben,
    Acht,
    Neun,
    Zehn,
    Bube,
    Dame,
    Koenig,
    Ass
} Kartenwert;

const char *symbolFarbe[] = {"♦", "♥", "♠", "♣"};

const char *symbolWert[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "B", "D", "K", "A"};

typedef struct
{
    Kartenfarbe kartenfarbe;
    Kartenwert kartenwert;
} Spielkarte;

void kartenVergabe(Spielkarte *menschHandKarten, Spielkarte *computerHandKarten);
void kartenstapelErstellen(Spielkarte *kartenStapel);
void kartenMischen(Spielkarte *kartenStapel);
void kartenAusteilen(Spielkarte *menschHandKarten, Spielkarte *computerHandKarten, Spielkarte *kartenStapel);