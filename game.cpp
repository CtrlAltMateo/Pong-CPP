#include <raylib.h>
#include <raymath.h>
#include "config.h"

void ResetPlayerPos() {
    player1.y = 540;
    player2.y = 540;
}

void ResetBall(bool right) {
    circle.x = screenWidth / 2;
    circle.y = screenHeight / 2;
    if(right) {
        circleVelocity.x = circleStartSpeed;
    }
    else {
        circleVelocity.x = -circleStartSpeed;
    }
    circleVelocity.y = 0;
}

void InitGame() {
    InitWindow(1920, 1080, "Pong!");
    SetTargetFPS(165);

    score[0] = 0;
    score[1] = 0;
    player1 = {10, 540, 30, 160};
    player2 = {1880, 540, 30, 160};
    circle = {960, 540, 30, 30};
    circleVelocity.x = circleStartSpeed;
    circleVelocity.y = 0;
}

void UpdateGame() {
    if(IsKeyDown(KEY_W)) {player1.y -= playerSpeed;}
    if(IsKeyDown(KEY_S)) {player1.y += playerSpeed;}
    if(IsKeyDown(KEY_UP)) {player2.y -= playerSpeed;}
    if(IsKeyDown(KEY_DOWN)) {player2.y += playerSpeed;}

    if(player1.y < 0) {
        player1.y = 0;
    }

    if(player1.y + player1.height > screenHeight) {
        player1.y = screenHeight - player1.height;
    }

    if(player2.y < 0) {
        player2.y = 0;
    }

    if(player2.y + player2.height > screenHeight) {
        player2.y = screenHeight - player2.height;
    }

    if(circle.y <= 0) {
        circleVelocity.y *= -1;
    }

    if(circle.y + 30 > screenHeight) {
        circleVelocity.y *= -1;
    }

    if(CheckCollisionRecs(player1, circle)) {
        circleVelocity *= circleAcceleration;
        circleVelocity = Vector2Reflect((Vector2){circleVelocity.x, (circle.y - (player1.y + player1.height / 2))*0.045}, (Vector2){1, 0});
    }

    if(CheckCollisionRecs(player2, circle)) {
        circleVelocity *= circleAcceleration;
        circleVelocity = Vector2Reflect((Vector2){circleVelocity.x, (circle.y - (player2.y + player2.height /2))*0.045}, (Vector2){1, 0});
    }

    if(circle.x + circle.width * 2 <= 0) {
        score[1]++;
        ResetBall(false);
        ResetPlayerPos();
    }

    if(circle.x - circle.width * 2 >= screenWidth) {
        score[0]++;
        ResetBall(true);
        ResetPlayerPos();
    }

    circle.x += circleVelocity.x;
    circle.y += circleVelocity.y;
}