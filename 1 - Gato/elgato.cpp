#include <iostream>
#include <vector>

using namespace std;

void ver_tab(const vector<vector<char>>& tab) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tab[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
}

bool gana(const vector<vector<char>>& t, char jug) {
    for (int i = 0; i < 3; i++) {
        bool f = true;
        bool c = true;
        for (int j = 0; j < 3; j++) {
            if (t[i][j] != jug) f = false;
            if (t[j][i] != jug) c = false;
        }
        if (f || c) return true;
    }
    if (t[0][0] == jug && t[1][1] == jug && t[2][2] == jug) return true;
    if (t[0][2] == jug && t[1][1] == jug && t[2][0] == jug) return true;
    return false;
}

bool lleno(const vector<vector<char>>& t) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (t[i][j] == ' ') return false;
    return true;
}

int main() {
    vector<vector<char>> tab(3, vector<char>(3, ' '));
    char jug = 'X';

    while (true) {
        ver_tab(tab);
        cout << "Turno del jugador " << jug << "\n";

        int f, c;
        cout << "Fila (0,1,2): ";
        if (!(cin >> f)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Eso no es un numero.\n";
            continue;
        }

        cout << "Columna (0,1,2): ";
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Eso no es un numero.\n";
            continue;
        }

        if (f < 0 || f > 2 || c < 0 || c > 2) {
            cout << "Pos no, esa pos no existe.\n";
            continue;
        }

        if (tab[f][c] != ' ') {
            cout << "Esa ya esta ocupada.\n";
            continue;
        }

        tab[f][c] = jug;

        if (gana(tab, jug)) {
            ver_tab(tab);
            cout << "Gano el jugador " << jug << "\n";
            break;
        }

        if (lleno(tab)) {
            ver_tab(tab);
            cout << "Empate\n";
            break;
        }

        jug = (jug == 'X') ? 'O' : 'X';
    }

    return 0;
}