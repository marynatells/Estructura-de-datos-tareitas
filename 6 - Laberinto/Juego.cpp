#include <SFML/Graphics.hpp>
#include "Laberinto.h"
#include "Jugador.h"

class MotorJuego {
private:
    sf::RenderWindow window;
    Laberinto* laberinto;
    Jugador jugador;
    const int TAM_CELDA = 40;

public:
    MotorJuego() {
        window.create(sf::VideoMode(800, 800), "Laberinto");
        laberinto = new Laberinto(20, 20);
    }

    void procesarEntrada() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                int dx = 0, dy = 0;
                if (event.key.code == sf::Keyboard::Up) dy = -1;
                if (event.key.code == sf::Keyboard::Down) dy = 1;
                if (event.key.code == sf::Keyboard::Left) dx = -1;
                if (event.key.code == sf::Keyboard::Right) dx = 1;

                int nx = jugador.getX() + dx;
                int ny = jugador.getY() + dy;

                if (!laberinto->esPared(nx, ny)) {
                    jugador.setPosicion(nx, ny);
                    verificarColisiones(nx, ny);
                }
            }
        }
    }

    void verificarColisiones(int x, int y) {
        int celda = laberinto->getCelda(x, y);
        if (celda == Laberinto::POCION) {
            jugador.recogerPocion();
        } else if (celda == Laberinto::SALIDA) {
            std::cout << "Nivel completado. Pasando al siguiente." << std::endl;
            // Aquí iría la lógica de reiniciar nivel
        }
    }

    void renderizar() {
        window.clear();
        // Aquí dibujarías los rectángulos de SFML basándote en laberinto->getCelda
        // Por brevedad, se omite el bucle de dibujo de sf::RectangleShape
        window.display();
    }

    void ejecutar() {
        while (window.isOpen()) {
            procesarEntrada();
            renderizar();
        }
    }
};

int main() {
    srand(time(NULL));
    std::cout << "Iniciando sistema de laberinto..." << std::endl;
    MotorJuego juego;
    juego.ejecutar();
    return 0;
}
