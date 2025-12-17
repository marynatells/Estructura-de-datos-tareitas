#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include "raylib.h"

using namespace std;

// Configuracion basica
const int BOARD_SIZE = 12;
const int TILE_SIZE = 50;
const int INITIAL_SNAKE_SIZE = 5;
const int TARGET_SIZE = 15;

struct Score {
    string name;
    int level;
    int size;

    // Para ordenar el ranking
    bool operator>(const Score& other) const {
        if (level != other.level) return level > other.level;
        return size > other.size;
    }
};

class SnakeGame {
private:
    deque<Vector2> snake;
    vector<Vector2> foods;
    vector<Vector2> traps;
    vector<Score> ranking;
    
    Vector2 direction = {1, 0};
    Vector2 nextDir = {1, 0};
    
    int level = 1;
    float timer = 0;
    float moveDelay = 0.2f;
    bool running = true;
    bool growing = false;

    void spawnItem(vector<Vector2>& targetList) {
        Vector2 pos;
        bool collision;
        do {
            collision = false;
            pos = {(float)GetRandomValue(0, BOARD_SIZE - 1), (float)GetRandomValue(0, BOARD_SIZE - 1)};
            
            for (auto& s : snake) if (s.x == pos.x && s.y == pos.y) collision = true;
            for (auto& f : foods) if (f.x == pos.x && f.y == pos.y) collision = true;
            for (auto& t : traps) if (t.x == pos.x && t.y == pos.y) collision = true;
        } while (collision);
        targetList.push_back(pos);
    }

    void resetLevel() {
        snake.clear();
        foods.clear();
        traps.clear();
        
        int startX = BOARD_SIZE / 2;
        int startY = BOARD_SIZE / 2;
        for (int i = 0; i < INITIAL_SNAKE_SIZE; i++) {
            snake.push_back({(float)startX - i, (float)startY});
        }

        for (int i = 0; i < level; i++) {
            spawnItem(foods);
            spawnItem(traps);
        }
        direction = {1, 0};
        nextDir = {1, 0};
        moveDelay = max(0.05f, 0.2f - (level * 0.02f));
    }

public:
    SnakeGame() {
        InitWindow(BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE, "Juego de Snake");
        SetTargetFPS(60);
        resetLevel();
    }

    ~SnakeGame() {
        CloseWindow();
    }

    void update() {
        if (!running) return;

        // Entradas de teclado
        if (IsKeyPressed(KEY_UP) && direction.y == 0) nextDir = {0, -1};
        if (IsKeyPressed(KEY_DOWN) && direction.y == 0) nextDir = {0, 1};
        if (IsKeyPressed(KEY_LEFT) && direction.x == 0) nextDir = {-1, 0};
        if (IsKeyPressed(KEY_RIGHT) && direction.x == 0) nextDir = {1, 0};

        timer += GetFrameTime();
        if (timer >= moveDelay) {
            timer = 0;
            direction = nextDir;

            Vector2 head = snake.front();
            head.x += direction.x;
            head.y += direction.y;

            // Atajos de bordes (wrap)
            if (head.x < 0) head.x = BOARD_SIZE - 1;
            if (head.x >= BOARD_SIZE) head.x = 0;
            if (head.y < 0) head.y = BOARD_SIZE - 1;
            if (head.y >= BOARD_SIZE) head.y = 0;

            // Colision con cuerpo
            for (auto& s : snake) {
                if (head.x == s.x && head.y == s.y) {
                    endGame();
                    return;
                }
            }

            snake.push_front(head);

            // Revisar comida
            bool ate = false;
            for (size_t i = 0; i < foods.size(); i++) {
                if (head.x == foods[i].x && head.y == foods[i].y) {
                    foods.erase(foods.begin() + i);
                    ate = true;
                    growing = true;
                    spawnItem(foods);
                    break;
                }
            }

            // Revisar trampas
            for (size_t i = 0; i < traps.size(); i++) {
                if (head.x == traps[i].x && head.y == traps[i].y) {
                    traps.erase(traps.begin() + i);
                    if (snake.size() > 2) {
                        snake.pop_back();
                        snake.pop_back();
                    } else {
                        endGame();
                        return;
                    }
                    spawnItem(traps);
                    break;
                }
            }

            if (!growing) {
                snake.pop_back();
            } else {
                growing = false;
            }

            if (snake.size() >= TARGET_SIZE) {
                level++;
                resetLevel();
            }
        }
    }

    void draw() {
        BeginDrawing();
        ClearBackground({20, 20, 20, 255});

        // Grid
        for (int i = 0; i < BOARD_SIZE; i++) {
            DrawLine(i * TILE_SIZE, 0, i * TILE_SIZE, GetScreenHeight(), DARKGRAY);
            DrawLine(0, i * TILE_SIZE, GetScreenWidth(), i * TILE_SIZE, DARKGRAY);
        }

        // Comida
        for (auto& f : foods) DrawCircle(f.x * TILE_SIZE + 25, f.y * TILE_SIZE + 25, 20, GOLD);
        
        // Trampas
        for (auto& t : traps) DrawRectangle(t.x * TILE_SIZE + 5, t.y * TILE_SIZE + 5, TILE_SIZE - 10, TILE_SIZE - 10, MAROON);

        // Snake
        for (size_t i = 0; i < snake.size(); i++) {
            Color c = (i == 0) ? FORESTGREEN : DARKGREEN;
            DrawRectangle(snake[i].x * TILE_SIZE, snake[i].y * TILE_SIZE, TILE_SIZE, TILE_SIZE, c);
            DrawRectangleLines(snake[i].x * TILE_SIZE, snake[i].y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
        }

        EndDrawing();
    }

    void endGame() {
        running = false;
        cout << "\n--- FIN DEL JUEGO ---" << endl;
        cout << "Nivel: " << level << " | Largo: " << snake.size() << endl;
        cout << "Nombre: ";
        string n; cin >> n;
        
        ranking.push_back({n, level, (int)snake.size()});
        sort(ranking.begin(), ranking.end(), greater<Score>());
        
        cout << "\nRanking Actual:" << endl;
        for(int i=0; i < min((int)ranking.size(), 5); i++) {
            cout << i+1 << ". " << ranking[i].name << " - Lvl " << ranking[i].level << endl;
        }

        cout << "\nReintentar? (s/n): ";
        char op; cin >> op;
        if (op == 's' || op == 'S') {
            level = 1;
            resetLevel();
            running = true;
        } else {
            exit(0);
        }
    }

    bool isWindowOpen() { return !WindowShouldClose(); }
};

int main() {
    SnakeGame game;
    while (game.isWindowOpen()) {
        game.update();
        game.draw();
    }
    return 0;
}
