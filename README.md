# DHBW-Kartenspiel

Ein textbasiertes Kartenspiel in C, bei dem ein menschlicher Spieler gegen einen Computergegner mit verschiedenen Strategien antritt.

## Inhaltsverzeichnis

- [Autor](#autor)
- [Beschreibung](#beschreibung)
- [Spielregeln](#spielregeln)
- [Funktionen](#funktionen)
- [Installation](#installation)

## Autor

**Michael Weber**  
Matrikelnummer: 9513126
Kurs: T4INF-1004-1-Programmieren-1
Duale Hochschule Baden-Württemberg Stuttgart
Abgabedatum: 10.03.2026

## Beschreibung

Das DHBW-Kartenspiel ist ein Stichspiel für zwei Spieler, bei dem ein menschlicher Spieler gegen einen computergesteuerten Gegner antritt. Der Computer wählt zu Beginn jeder Partie zufällig eine von vier verschiedenen Spielstrategien aus.

## Spielregeln

### Kartendeck

- **52 Karten**: Werte 2–10, Bube (B), Dame (D), König (K), Ass (A)
- **4 Farben**: ♠ (Pik), ♥ (Herz), ♦ (Karo), ♣ (Kreuz)
- **Kartenhierarchie**: 2 < 3 < ... < 10 < B < D < K < A

### Punktewertung

| Karte | Punkte      |
|-------|-------------|
| 2-10  | Kartenwert  |
| Bube  | 2           |
| Dame  | 3           |
| König | 4           |
| Ass   | 11          |

### Spielablauf

1. Das Deck wird gemischt
2. Jeder Spieler erhält 10 Handkarten
3. Der Computer beginnt und legt eine Karte
4. Der Gegenspieler legt eine Karte
5. Die höhere Karte gewinnt den Stich
6. Bei Gleichstand gewinnt die zuerst gespielte Karte
7. Der Gewinner des Stichs beginnt die nächste Runde
8. Nach 10 Runden werden die Punkte gezählt
9. Der Spieler mit den meisten Punkten gewinnt
10. Bei Gleichstand gewinnt der menschliche Spieler

## Funktionen

### Computergegner-Strategien

Das Spiel bietet vier verschiedene KI-Strategien:

1. **Einfacher Gegner**
   - Spielt Karten in der Reihenfolge, wie sie ausgeteilt wurden
   - Keine strategische Planung

2. **Strategischer Gegner**
   - Spielt Karten von der höchsten zur niedrigsten
   - Versucht früh hohe Punkte zu sammeln

3. **Wechselnder Gegner**
   - Spielt abwechselnd die kleinste und größte Karte
   - Unvorhersehbare Spielweise

4. **Reaktiver Gegner**
   - Versucht die Karte des Gegners zu übertrumpfen
   - Spielt sonst die kleinste verfügbare Karte
   - Passt sich dem Spielverlauf an

## Installation

### Voraussetzungen

- **Betriebssystem**: Windows (verwendet Windows-spezifische Funktionen)
- **Compiler**: GCC (MinGW) oder ein anderer C-Compiler
- **C-Standard**: C11 oder höher

### Dateien

Stellen Sie sicher, dass alle folgenden Dateien im selben Verzeichnis liegen:

- `main.c`
- `karten.c` / `karten.h`
- `spieler.c` / `spieler.h`
- `konsole.c` / `konsole.h`

### Kompilierung

Führen Sie die Datei `main.c` aus.
