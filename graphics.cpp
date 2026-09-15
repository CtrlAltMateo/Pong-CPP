#include <raylib.h>
#include "config.h"

void DrawBetterRectangle(Rectangle rectangle, Color color) {
    DrawRectangle(rectangle.x - (rectangle.width / 2), rectangle.y - (rectangle.height / 2), rectangle.width, rectangle.height, color);
}

void DrawBetterCircle(Rectangle circle, Color color) {
    DrawCircle(circle.x - (circle.width / 2), circle.y - (circle.width / 2), circle.width, color);
}

void DrawGame() {
    ClearBackground(BLACK);

    BeginDrawing();
        DrawBetterRectangle(player1, WHITE);
        DrawBetterRectangle(player2, WHITE);
        DrawBetterCircle(circle, WHITE);
        DrawText(TextFormat("%i : %i", score[0], score[1]), 852, 15, 100, WHITE);
    EndDrawing();
}