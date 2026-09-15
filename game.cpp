#include <raylib.h>
#include "config.h"

void ResetPlayerPos() {
    player1.x = 40;
    player1.y = 540;
    player2.x = 1920 - 40;
    player2.y = 540;
}

void InitGame() {
    InitWindow(1920, 1080, "Pong!");
    SetTargetFPS(165);

    score[0] = 0;
    score[1] = 0;

    player1 = {40, 540, 30, 160};
    player2 = {1880, 540, 30, 160};

    circle = {960, 540, 30, 30};
    circleVelocity.x = circleStartSpeed;
}

void UpdateGame() {
    if(IsKeyDown(KEY_W)) {player1.y -= playerSpeed;}
    if(IsKeyDown(KEY_S)) {player1.y += playerSpeed;}
    if(IsKeyDown(KEY_UP)) {player2.y -= playerSpeed;}
    if(IsKeyDown(KEY_DOWN)) {player2.y += playerSpeed;}

    if(player1.y - 80 < 0) {
        player1.y = 80;
    }

    if(player1.y + 80 > screenHeight) {
        player1.y = screenHeight - 80;
    }

    if(player2.y - 80 < 0) {
        player2.y = 80;
    }

    if(player2.y + 80 > screenHeight) {
        player2.y = screenHeight - 80;
    }

    if(CheckCollisionRecs(player1, circle)) {
        circleVelocity.x *= -circleAcceleration;
        circleVelocity.y *= -circleAcceleration;
    }

    if(CheckCollisionRecs(player2, circle)) {
        circleVelocity.x *= -circleAcceleration;
        circleVelocity.y *= -circleAcceleration;
    }

    if(circle.x + circle.width * 2 <= 0) {
        score[1]++;
        circle.x = screenWidth / 2;
        circle.y = screenHeight / 2;
        circleVelocity.x = circleStartSpeed;
        circleVelocity.y = 0;
        ResetPlayerPos();
    }

    if(circle.x - circle.width * 2 >= screenWidth) {
        score[0]++;
        circle.x = screenWidth / 2;
        circle.y = screenHeight / 2;
        circleVelocity.x = -circleStartSpeed;
        circleVelocity.y = 0;
        ResetPlayerPos();
    }

    circle.x += circleVelocity.x;
    circle.y += circleVelocity.y;
}