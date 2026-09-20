#include <raylib.h>
#include "config.h"
#include "game.h" 
#include "graphics.h"
#include "audio.h"

int score[2];
Vector2 circleVelocity;

Rectangle player1;
Rectangle player2;
Rectangle circle;

int main() {
    InitGame();
    InitAudio();

    PlayDrums();

    while(!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }

    CloseWindow();
    return 0;
}