#include <raylib.h>
#include "config.h"

bool CollisionCheck(int pos1[2], int pos2[2], int size1[2], int size2[2]) {
    int hSize1[2] = {size1[0] / 2, size1[1] / 2};
    int hSize2[2] = {size2[0] / 2, size2[1] / 2};
    bool collidingX = pos1[0] + hSize1[0] >= pos2[0] - hSize2[0] && pos1[0] - hSize1[0] <= pos2[0] + hSize2[0];
    bool collidingY = pos1[1] + hSize1[1] >= pos2[1] - hSize2[1] && pos1[1] - hSize1[1] <= pos2[1] + hSize2[1];
    return collidingX && collidingY;
}

void ResetPlayerPos() {
    player1Pos[0] = 40;
    player1Pos[1] = 540;
    player2Pos[0] = 1920 - 40;
    player2Pos[1] = 540;
}

void InitGame() {
    InitWindow(1920, 1080, "Pong!");
    SetTargetFPS(165);

    score[0] = 0;
    score[1] = 0;

    playerSize[0] = 30;
    playerSize[1] = 160;
    player1Pos[0] = 40;
    player1Pos[1] = 540;
    player2Pos[0] = 1920 - 40;
    player2Pos[1] = 540;

    circleVelocity[0] = circleStartSpeed;
    circlePos[0] = 960;
    circlePos[1] = 540;
}

void UpdateGame() {
    if(IsKeyDown(KEY_W)) {player1Pos[1] -= playerSpeed;}
    if(IsKeyDown(KEY_S)) {player1Pos[1] += playerSpeed;}
    if(IsKeyDown(KEY_UP)) {player2Pos[1] -= playerSpeed;}
    if(IsKeyDown(KEY_DOWN)) {player2Pos[1] += playerSpeed;}

    if(player1Pos[1] - 80 < 0) {
        player1Pos[1] = 80;
    }

    if(player1Pos[1] + 80 > screenHeight) {
        player1Pos[1] = screenHeight - 80;
    }

    if(player2Pos[1] - 80 < 0) {
        player2Pos[1] = 80;
    }

    if(player2Pos[1] + 80 > screenHeight) {
        player2Pos[1] = screenHeight - 80;
    }

    if(CollisionCheck(player1Pos, circlePos, playerSize, (int[2]) {circleSize, circleSize})) {
        circleVelocity[0] *= -circleAcceleration;
        circleVelocity[1] *= -circleAcceleration;
    }

    if(CollisionCheck(player2Pos, circlePos, playerSize, (int[2]) {circleSize, circleSize})) {
        circleVelocity[0] *= -circleAcceleration;
        circleVelocity[1] *= -circleAcceleration;
    }

    if(circlePos[0] + circleSize * 2 <= 0) {
        score[1]++;
        circlePos[0] = screenWidth / 2;
        circlePos[1] = screenHeight / 2;
        circleVelocity[0] = circleStartSpeed;
        circleVelocity[1] = 0;
        ResetPlayerPos();
    }

    if(circlePos[0] - circleSize * 2 >= screenWidth) {
        score[0]++;
        circlePos[0] = screenWidth / 2;
        circlePos[1] = screenHeight / 2;
        circleVelocity[0] = -circleStartSpeed;
        circleVelocity[1] = 0;
        ResetPlayerPos();
    }

    circlePos[0] += circleVelocity[0];
    circlePos[1] += circleVelocity[1];
}