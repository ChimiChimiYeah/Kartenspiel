#include "karten.c"
#include "spieler.c"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    spieler p1 = {
        .spielername = spielername(&p1->spielername),
        .punkte = 0,
        .zugPointer = &spielerzug,
    };
    printf("Spieler Punkte: %d\n", p1.punkte);

    spieler computer = {
        .spielername = "Computer",
        .punkte = 0,
    };
    // random computer strategy for zugPointer to be implemented

    return 0;
}