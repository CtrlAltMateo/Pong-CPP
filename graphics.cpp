#include <raylib.h>
#include <vector>
#include "config.h"
#include "menu.h"
#include "particles.h"
using namespace std;

void DrawBetterCircle(Rectangle circle, Color color) {
    DrawCircle(circle.x, circle.y, circle.width, color);
}

void DrawCenterLine(Color color, int segments) {
    int size = screenHeight / segments;
    for(int i = 0; i < segments; i++) {
        DrawRectangle(screenWidth / 2 - size / 2, i * size * 2, size, size, WHITE);
    }
}

void DrawParticles(vector<Particle> particles) {
    for(Particle particle : particles) {
        Rectangle rectangle = {
            particle.pos.x,
            particle.pos.y,
            5,
            5
        };
        DrawRectangleRec(rectangle, ColorFromHSV(particle.hue, 1, 1));
    }
}

void DrawMenu() {
    ClearBackground(BLACK);

    BeginDrawing();
        DrawRectangle(screenWidth / 2 - 150, 497.5 + (highlighted * 60), 300, 50, WHITE);
        DrawText("PONG!", screenWidth / 2 - MeasureText("PONG!", 250) / 2, 50, 250, WHITE);
        DrawText("PLAY", screenWidth / 2 - MeasureText("PLAY", 50) / 2, 500, 50, (highlighted == 0) ? BLACK : WHITE);
        DrawText("SETTINGS", screenWidth / 2 - MeasureText("SETTINGS", 50) / 2, 560, 50, (highlighted == 1) ? BLACK : WHITE);
        DrawText("QUIT", screenWidth / 2 - MeasureText("QUIT", 50) / 2, 620, 50, (highlighted == 2) ? BLACK : WHITE);
    EndDrawing();
}

void DrawSettingsMenu() {
    ClearBackground(BLACK);

    BeginDrawing();
        DrawText("COMING SOON!", screenWidth / 2 - MeasureText("COMING SOON!", 200) / 2, screenHeight / 2 - 100, 200, WHITE);
        DrawText("PRESS ANYTHING TO GO BACK", screenWidth / 2 - MeasureText("PRESS ANYTHING TO GO BACK", 75) / 2, screenHeight / 2 + 100, 75, WHITE);
    EndDrawing();
}

void DrawPlayerMenu() {
    ClearBackground(BLACK);

    BeginDrawing();
        DrawRectangle(screenWidth / 2 - 150, 497.5 + (highlighted * 60), 300, 50, WHITE);
        DrawText("1 PLAYER", screenWidth / 2 - MeasureText("1 PLAYER", 50) / 2, 500, 50, (highlighted == 0) ? BLACK : WHITE);
        DrawText("2 PLAYER", screenWidth / 2 - MeasureText("2 PLAYER", 50) / 2, 560, 50, (highlighted == 1) ? BLACK : WHITE);
    EndDrawing();
}

void DrawGame() {
    ClearBackground(BLACK);

    BeginDrawing();
        DrawRectangleRec(player1, WHITE);
        DrawRectangleRec(player2, WHITE);
        DrawBetterCircle(circle, WHITE);
        DrawCenterLine(WHITE, centerLineSegments);
        const char *text = TextFormat("%i   %i", score[0], score[1]);
        DrawText(text, screenWidth / 2 - MeasureText(text, 100) / 2, 15, 100, WHITE);
        DrawParticles(particles);
    EndDrawing();
}