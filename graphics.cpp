#include <raylib.h>
#include "config.h"

void DrawBetterCircle(Rectangle circle, Color color) {
    DrawCircle(circle.x, circle.y, circle.width, color);
}

void DrawGame() {
    ClearBackground(BLACK);

    BeginDrawing();
        DrawRectangleRec(player1, WHITE);
        DrawRectangleRec(player2, WHITE);
        DrawBetterCircle(circle, WHITE);
        const char *text = TextFormat("%i : %i", score[0], score[1]);
        DrawText(text, 1920 / 2 - MeasureText(text, 100) / 2, 15, 100, WHITE);
    EndDrawing();
}