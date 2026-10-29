#include <raylib.h>
#include <raymath.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "config.h"
#include "audio.h"
#include "particles.h"

Vector2 lastCircleVelocity;

void ResetPlayerPos() {
    player1.y = screenHeight / 2 - (player2.height / 2);
    player2.y = screenHeight / 2 - (player2.height / 2);
}

void ResetBall(bool iscircleRight) {
    circle.x = screenWidth / 2;
    circle.y = screenHeight / 2;
    if(iscircleRight) {
        circleVelocity.x = -circleStartSpeed;
    }
    else {
        circleVelocity.x = circleStartSpeed;
    }
    circleVelocity.y = 0;
}

void UpdateResolution() {
    #if defined(PLATFORM_WEB)
        screenWidth = (float)GetRenderWidth();
        screenHeight = (float)GetRenderHeight();
    #else
        screenWidth = (float)GetScreenWidth();
        screenHeight = (float)GetScreenHeight();
    #endif

    player2.x = screenWidth - 40;
}

void UpdateP1() {
    if(IsKeyDown(KEY_W)) {player1.y -= playerSpeed;}
    if(IsKeyDown(KEY_S)) {player1.y += playerSpeed;}

    if(player1.y < 0) {
        player1.y = 0;
    }

    if(player1.y + player1.height > screenHeight) {
        player1.y = screenHeight - player1.height;
    }
}

void UpdateAI() {
    if(circle.y < player2.y + (player2.height / 2)) {player2.y -= playerSpeed;}
    else if(circle.y > player2.y + (player2.height / 2)) {player2.y += playerSpeed;}
}

void UpdateP2() {
    if(currentScreen == GAME1P) {
        UpdateAI();
    }
    else {
        if(IsKeyDown(KEY_UP)) {player2.y -= playerSpeed;}
        if(IsKeyDown(KEY_DOWN)) {player2.y += playerSpeed;}
    }
    if(player2.y < 0) {
        player2.y = 0;
    }

    if(player2.y + player2.height > screenHeight) {
        player2.y = screenHeight - player2.height;
    }
}

void Updatecircle() { 
    if(circle.y <= 0) {
        PlayHitWallSound();
        circleVelocity.y *= -1;
    }

    if(circle.y + 30 > screenHeight) {
        PlayHitWallSound();
        circleVelocity.y *= -1;
    }

    if(CheckCollisionRecs(player1, circle)) {
        PlayHitPlayerSound();
        circleVelocity.x *= circleAcceleration;
        circleVelocity = Vector2Reflect((Vector2){circleVelocity.x, (circle.y - (player1.y + player1.height / 2)) * 0.045f}, (Vector2){1, 0});
    }

    if(CheckCollisionRecs(player2, circle)) {
        PlayHitPlayerSound();
        circleVelocity.x *= circleAcceleration;
        circleVelocity = Vector2Reflect((Vector2){circleVelocity.x, (circle.y - (player2.y + player2.height /2))  * 0.045f}, (Vector2){1, 0});
    }

    if(circle.x + circle.width * 2 <= 0 && particleCountdown < 0) {
        PlayScoreSound();
        score[1]++;
        InitParticles(false);
        ResetPlayerPos();
    }

    if(circle.x - circle.width * 2 >= screenWidth && particleCountdown < 0) {
        PlayScoreSound();
        score[0]++;
        InitParticles(true);
        ResetPlayerPos();
    }

    circle.x += circleVelocity.x;
    circle.y += circleVelocity.y;
}

bool IsParticleAcceleratorOn() {
    static int accelerationFrames = 0;
    if(circleVelocity.x * circleVelocity.x > lastCircleVelocity.x * lastCircleVelocity.x) {
        accelerationFrames++;
        return accelerationFrames >= 2;
    }
    accelerationFrames = 0;
    return false;
}

void InitGame() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "Pong!");
    #ifndef PLATFORM_WEB
        refreshRate = GetMonitorRefreshRate(0);
    #endif
    SetTargetFPS(refreshRate);
    SetExitKey(KEY_NULL);
    std::srand(std::time({}));

    particleLife = 2 * refreshRate;
    particleHalfLife = particleLife / 2;

    score[0] = 0;
    score[1] = 0;
    player1 = {10, 460, 30, 160};
    player2 = {1880, 460, 30, 160};
    circle = {960, 540, 30, 30};
    circleVelocity.x = circleStartSpeed;
    circleVelocity.y = 0;
}

void UpdateGame() {
    static bool particleAcceleratorWasOn = false;
    lastCircleVelocity = circleVelocity;
    UpdateAudio();
    UpdateParticles();
    UpdateP1();
    UpdateP2();
    Updatecircle();
    bool particleAcceleratorIsOn = IsParticleAcceleratorOn();
    if(particleAcceleratorIsOn && !particleAcceleratorWasOn) {
        KABOOM();
    }
    particleAcceleratorWasOn = particleAcceleratorIsOn;
}