#include <raylib.h>
#include <raymath.h>
#include "config.h"
#include "audio.h"

int highlighted = 0;
const int mainOptions = 3;
const int settingsOptions = 4;
const int playerOptions = 2;

void HandleMenuClick() {
    if(highlighted == 0) {
        currentScreen = PLAYERSELECT;
    }
    else if(highlighted == 1) {
        highlighted = 0;
        currentScreen = SETTINGS;
    }
    else if(highlighted == 2) {
        quitGame = true;
    }
}

void HandleSettingsMenuClick() {
    if(highlighted == 0) {
        
    }
    else if(highlighted == 1) {
        
    }
    else if(highlighted == 2) {
        
    }
    else if(highlighted == 3) {

    }
}

void HandlePlayerMenuClick() {
    if(highlighted == 0) {
        currentScreen = GAME1P;
    }
    else if(highlighted == 1) {
        currentScreen = GAME2P;
    }
}

void UpdateMenu() {
    if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        highlighted--;
        PlayHightlightSound();
    }
    if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
        highlighted++;
        PlayHightlightSound();
    }
    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        HandleMenuClick();
        PlaySelectSound();
    }
    highlighted = highlighted % mainOptions;
    if(highlighted < 0) {
        highlighted = mainOptions - 1;
    }
}

void UpdatePlayerMenu() {
    if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        highlighted--;
        PlayHightlightSound();
    }
    if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
        highlighted++;
        PlayHightlightSound();
    }
    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        HandlePlayerMenuClick();
        PlaySelectSound();
    }
    highlighted = highlighted % playerOptions;
    if(highlighted < 0) {
        highlighted = playerOptions - 1;
    }
}

void UpdateSettingsMenu() {
    if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
        highlighted--;
    }
    if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
        highlighted++;
    }
    /*if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
        HandleSettingsMenuClick();
    }*/
    if(GetKeyPressed() != 0) {
        currentScreen = MENU;
    }
    highlighted = highlighted % settingsOptions;
    if(highlighted < 0) {
        highlighted = settingsOptions - 1;
    }
}