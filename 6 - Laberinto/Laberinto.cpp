#ifndef LABERINTO_H
#define LABERINTO_H

#include <vector>
#include <random>
#include <ctime>

class Laberinto {
public:
    enum TipoCelda { VACIO, PARED, ENTRADA, SALIDA, TRAMPA, LLAVE, PUERTA, POCION };

private:
    int ancho, alto;
    std::vector<std::vector<int>> celdas;
    std::vector<std::vector<bool>> descubierto;

public:
    Laberinto(int w, int h) : ancho(w), alto(h) {
        celdas.assign(ancho, std::vector<int>(alto, PARED));
        descubierto.assign(ancho, std::vector<bool>(alto, false));
        generarBasico();
    }

    void generarBasico() {
        // Lógica simplificada de generación (similar a tu algoritmo de excavación)
        for(int i = 1; i < ancho - 1; i++) {
            for(int j = 1; j < alto - 1; j++) {
                if(rand() % 10 > 2) celdas[i][j] = VACIO;
            }
        }
        celdas[1][1] = ENTRADA;
        celdas[ancho-2][alto-2] = SALIDA;
    }

    bool esPared(int x, int y) {
        if (x < 0 || x >= ancho || y < 0 || y >= alto) return true;
        return celdas[x][y] == PARED;
    }

    int getCelda(int x, int y) { return celdas[x][y]; }
    void setDescubierto(int x, int y) { descubierto[x][y] = true; }
};

#endif
