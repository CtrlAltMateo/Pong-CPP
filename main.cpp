#include <raylib.h>
#include "config.h"
#include "game.h" 
#include "graphics.h"

int score[2];
Vector2 circleVelocity;

Rectangle player1;
Rectangle player2;
Rectangle circle;

int main() {
    InitGame();

    while(!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }

    CloseWindow();
    return 0;
}