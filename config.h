#ifndef CONFIG_H
#define CONFIG_H

extern int screenWidth;
extern int screenHeight;
extern int refreshRate;

const int centerLineSegments = 108;
const int particleCount = 100;

extern float playerSpeed;
extern int circleStartSpeed;
const float circleAcceleration = 1.087f;

extern int particleLife;
extern int particleHalfLife;

extern int score[2];
extern Vector2 circleVelocity;

extern Rectangle player1;
extern Rectangle player2;
extern Rectangle circle;

extern bool quitGame;

enum Screen {
    MENU,
    SETTINGS,
    PLAYERSELECT,
    GAME1P,
    GAME2P
};

extern enum Screen currentScreen;

#endif