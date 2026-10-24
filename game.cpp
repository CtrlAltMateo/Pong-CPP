#include <raylib.h>
#include <raymath.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "config.h"
#include "audio.h"
#include "particles.h"

void ResetPlayerPos() {
    player1.y = 460;
    player2.y = 460;
}

void ResetBall(bool isBallRight) {
    circle.x = screenWidth / 2;
    circle.y = screenHeight / 2;
    if(isBallRight) {
        circleVelocity.x = -ballStartSpeed;
    }
    else {
        circleVelocity.x = ballStartSpeed;
    }
    circleVelocity.y = 0;
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
    if(circle.y < player2.y + (player2.height / 2)) {player2.y -= playerSpeed * aiSpeedRatio;}
    else if(circle.y > player2.y + (player2.height / 2)) {player2.y += playerSpeed * aiSpeedRatio;}
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

void UpdateBall(Rectangle& ball, Vector2& ballVelocity) { 
    if(ball.y <= 0) {
        PlayHitWallSound();
        ballVelocity.y *= -1;
    }

    if(ball.y + 30 > screenHeight) {
        PlayHitWallSound();
        ballVelocity.y *= -1;
    }

    if(CheckCollisionRecs(player1, ball)) {
        PlayHitPlayerSound();
        ballVelocity.x *= ballAcceleration;
        ballVelocity = Vector2Reflect((Vector2){ballVelocity.x, (ball.y - (player1.y + player1.height / 2)) * 0.045f}, (Vector2){1, 0});
    }

    if(CheckCollisionRecs(player2, ball)) {
        PlayHitPlayerSound();
        ballVelocity.x *= ballAcceleration;
        ballVelocity = Vector2Reflect((Vector2){ballVelocity.x, (ball.y - (player2.y + player2.height /2))  * 0.045f}, (Vector2){1, 0});
    }

    if(ball.x + ball.width * 2 <= 0 && particleCountdown < 0) {
        PlayScoreSound();
        score[1]++;
        InitParticles(false);
        ResetPlayerPos();
    }

    if(ball.x - ball.width * 2 >= screenWidth && particleCountdown < 0) {
        PlayScoreSound();
        score[0]++;
        InitParticles(true);
        ResetPlayerPos();
    }

    ball.x += ballVelocity.x;
    ball.y += ballVelocity.y;
}

void InitGame() {
    InitWindow(1920, 1080, "Pong!");
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
    circleVelocity.x = ballStartSpeed;
    circleVelocity.y = 0;
}

void UpdateGame() {
    UpdateAudio();
    UpdateParticles();
    UpdateP1();
    UpdateP2();
    UpdateBall(circle, circleVelocity);
}