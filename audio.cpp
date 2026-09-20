#include <raylib.h>

Sound fxHitPlayer;
Sound fxHitWall;
Sound fxScore;

void InitAudio() {
    InitAudioDevice();

    fxHitPlayer = LoadSound("Assets/Audio/fxHitPlayer.wav");
    fxHitWall = LoadSound("Assets/Audio/fxHitWall.wav");
    fxScore = LoadSound("Assets/Audio/GOOOOOOOOAL.wav");
}

void PlayHitPlayerSound() {
    PlaySound(fxHitPlayer);
}

void PlayHitWallSound() {
    PlaySound(fxHitWall);
}
void PlayScoreSound() {
    PlaySound(fxScore);
}