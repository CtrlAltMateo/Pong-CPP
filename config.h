#ifndef CONFIG_H
#define CONFIG_H

const int screenWidth = 1920;
const int screenHeight = 1080;
const int centerLineSegments = 108;
const int particleCount = 100;

const float playerSpeed = 6.5f;
const int ballStartSpeed = 5;
const float ballAcceleration = 1.087f;

extern int particleLife;
extern int particleHalfLife;

extern int refreshRate;
extern int score[2];
extern Vector2 circleVelocity;

extern Rectangle player1;
extern Rectangle player2;
extern Rectangle circle;

extern bool quitGame;

enum Screen {
    MENU,
    SETTINGS,
    GAME1P,
    GAME2P
};

extern enum Screen currentScreen;

#endif