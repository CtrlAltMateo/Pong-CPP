#include <raylib.h>
#include <vector>
#include "config.h"
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

void DrawGame() {
    ClearBackground(BLACK);

    BeginDrawing();
        DrawRectangleRec(player1, WHITE);
        DrawRectangleRec(player2, WHITE);
        DrawBetterCircle(circle, WHITE);
        DrawCenterLine(WHITE, centerLineSegments);
        const char *text = TextFormat("%i   %i", score[0], score[1]);
        DrawText(text, 1920 / 2 - MeasureText(text, 100) / 2, 15, 100, WHITE);
        DrawText(TextFormat("%i", particles.size()), 15, 15, 25, WHITE);
        DrawParticles(particles);
    EndDrawing();
}