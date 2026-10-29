#include <raylib.h>
#include "config.h"
#include "menu.h"
#include "game.h"
#include "graphics.h"
#include "audio.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int screenWidth = 1920;
int screenHeight = 1080;
int refreshRate = 60;

int particleLife;
int particleHalfLife;

int score[2];
Vector2 circleVelocity;

Rectangle player1;
Rectangle player2;
Rectangle circle;

bool quitGame = false;

enum Screen currentScreen;

void UpdateDrawFrame(void) {
    #if defined(PLATFORM_WEB)
    if (IsWindowResized()) {
        SetWindowSize(GetScreenWidth(), GetScreenHeight());
    }
    #endif

    UpdateResolution();

    if(currentScreen == MENU) {
        UpdateMenu();
        DrawMenu();
    }
    else if(currentScreen == SETTINGS) {
        UpdateSettingsMenu();
        DrawSettingsMenu();
    }
    else if(currentScreen == PLAYERSELECT) {
        UpdatePlayerMenu();
        DrawPlayerMenu();
    }
    else if(currentScreen == GAME1P || GAME2P) {
        UpdateGame();
        DrawGame();
    }

    #if defined(PLATFORM_WEB)
    if (quitGame || WindowShouldClose()) {
        emscripten_cancel_main_loop();
    }
    #endif
}

#if defined(PLATFORM_WEB)
    float playerSpeed = 6.5f * 2.75f;
    int circleStartSpeed = (int)(5 * 2.75f);
#else
    float playerSpeed = 6.5f;
    int circleStartSpeed = 5;
#endif

int main() {
    InitGame();
    InitAudio();

    PlayMainMusic();

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
    #else
        while(!WindowShouldClose() && !quitGame) {
            UpdateDrawFrame();
        }
    #endif

    CloseWindow();
    return 0;
}