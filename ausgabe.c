#include "ausgabe.h"

// setzt den Cursor auf (x, y) im Terminal
void gotoxy(short x, short y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};
    SetConsoleCursorPosition(hStdout, position);
}

void initialisiereKonsole()
{
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
}

void handkartenAnzeige(const Spielkarte *handkarten, int zugAnzahl)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < zugAnzahl; i++)
    {
        gotoxy(x + i * 8, y);
        printf("+=====+");
        /*printf("|     |\n");
        printf("|     |\n");
        printf("|     |\n");
        printf("|     |\n");
        printf("+=====+\n");*/
    }
}