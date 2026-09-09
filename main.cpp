#include <raylib.h>
#include "config.h"
#include "game.h" 
#include "graphics.h"

int score[2];
int playerSize[2];
int player1Pos[2];
int player2Pos[2];
int circlePos[2];
float circleVelocity[2];

int main() {
    InitGame();

    while(!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }

    CloseWindow();
    return 0;
}