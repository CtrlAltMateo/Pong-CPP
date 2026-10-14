#include <raylib.h>
#include "config.h"
#include "menu.h"
#include "game.h"
#include "graphics.h"
#include "audio.h"

int particleLife;
int particleHalfLife;

int refreshRate = 60;
int score[2];
Vector2 circleVelocity;

Rectangle player1;
Rectangle player2;
Rectangle circle;

bool quitGame = false;

enum Screen currentScreen;

int main() {
    InitGame();
    InitAudio();

    PlayMainMusic();

    while(!WindowShouldClose() && !quitGame) {
        if(currentScreen == MENU) {
            UpdateMenu();
            DrawMenu();
        }
        else if(currentScreen == SETTINGS) {
            UpdateSettingsMenu();
            DrawSettingsMenu();
        }
        else if(currentScreen == GAME2P) {
            UpdateGame();
            DrawGame();
            // TODO: Add function parameter for player count
        }
    }

    CloseWindow();
    return 0;
}