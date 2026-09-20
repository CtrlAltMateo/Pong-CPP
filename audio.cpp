#include <raylib.h>

Sound fxHitPlayer;
Sound fxHitWall;
Sound fxScore;
Music mxDrums;

void InitAudio() {
    InitAudioDevice();

    fxHitPlayer = LoadSound("Assets/Audio/fxHitPlayer.wav");
    fxHitWall = LoadSound("Assets/Audio/fxHitWall.wav");
    fxScore = LoadSound("Assets/Audio/GOOOOOOOOAL.wav");
    
    mxDrums = LoadMusicStream("Assets/Audio/mxDrums.wav");
    mxDrums.looping = true;
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

void PlayDrums() {
    PlayMusicStream(mxDrums);
}

void UpdateAudio() {
    UpdateMusicStream(mxDrums);
}