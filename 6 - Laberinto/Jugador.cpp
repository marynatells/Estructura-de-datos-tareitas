#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>

class Jugador {
private:
    int x, y;
    int vidas;
    int llavesObtenidas;
    int pasos;

public:
    Jugador() {
        x = 1;
        y = 1;
        vidas = 5;
        llavesObtenidas = 0;
        pasos = 0;
    }

    void reiniciarNivel() {
        x = 1;
        y = 1;
        llavesObtenidas = 0;
        pasos = 0;
    }

    void perderVida() {
        if (vidas > 0) vidas--;
    }

    void recogerPocion() {
        vidas++;
        std::cout << "Pocion recogida. Vidas actuales: " << vidas << std::endl;
    }

    void recogerLlave() {
        llavesObtenidas++;
        std::cout << "Llave obtenida. Total: " << llavesObtenidas << std::endl;
    }

    // Getters básicos
    int getX() { return x; }
    int getY() { return y; }
    int getVidas() { return vidas; }
    void setPosicion(int nx, int ny) { x = nx; y = ny; }
};

#endif
