#include "functions.h"

int n, m;
int terkep[MAX_MERET][MAX_MERET];
int visited[MAX_MERET][MAX_MERET];
int max_hossz = -1;

// Mozgás: fel, le, balra, jobbra
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void backtrack(int x, int y, int aktualis_hossz) {
    // Ha elértük a célpontot (n-1, m-1)
    if (x == n - 1 && y == m - 1) {
        if (aktualis_hossz > max_hossz) {
            max_hossz = aktualis_hossz;
        }
        return;
    }

    // Aktuális mező megjelölése
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Ellenőrzések: pályán belül van-e, nem jártunk-e ott, és NEM kisebb a magasság
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
            if (terkep[nx][ny] >= terkep[x][y]) {
                backtrack(nx, ny, aktualis_hossz + 1);
            }
        }
    }

    // KRITIKUS LÉPÉS: Visszalépéskor felszabadítjuk a mezőt!
    // Ez teszi lehetővé, hogy más útvonalak is érinthessék ezt a cellát.
    visited[x][y] = 0;
}