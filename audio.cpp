#include <raylib.h>

Sound fxHitPlayer;
Sound fxHitWall;
Sound fxScore;
Music mxMain;

void InitAudio() {
    InitAudioDevice();

    fxHitPlayer = LoadSound("Assets/Audio/fxHitPlayer.wav");
    fxHitWall = LoadSound("Assets/Audio/fxHitWall.wav");
    fxScore = LoadSound("Assets/Audio/GOOOOOOOOAL.wav");
    
    mxMain = LoadMusicStream("Assets/Audio/mxMain.wav");
    mxMain.looping = true;
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

void PlayMainMusic() {
    PlayMusicStream(mxMain);
}

void UpdateAudio() {
    UpdateMusicStream(mxMain);
}