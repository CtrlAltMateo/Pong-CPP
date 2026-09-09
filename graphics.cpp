#include <raylib.h>
#include "config.h"

void DrawBetterRectangle(int x, int y, int width, int height, Color color) {
    DrawRectangle(x - (width / 2), y - (height / 2), width, height, color);
}

void DrawBetterCircle(int x, int y, int radius, Color color) {
    DrawCircle(x - (radius / 2), y - (radius / 2), radius, color);
}

void DrawGame() {
    ClearBackground(BLACK);

    BeginDrawing();
        DrawBetterRectangle(player1Pos[0], player1Pos[1], playerSize[0], playerSize[1], WHITE);
        DrawBetterRectangle(player2Pos[0], player2Pos[1], playerSize[0], playerSize[1], WHITE);
        DrawBetterCircle(circlePos[0], circlePos[1], circleSize, WHITE);
        DrawText(TextFormat("%i : %i", score[0], score[1]), 852, 15, 100, WHITE);
    EndDrawing();
}