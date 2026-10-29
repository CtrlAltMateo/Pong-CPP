#include <raylib.h>

Sound fxHitPlayer;
Sound fxHitWall;
Sound fxScore;
Sound fxHighlight;
Sound fxSelect;
Sound fxParticleAccelerator;
Music mxMain;

void InitAudio() {
    InitAudioDevice();

    fxHitPlayer = LoadSound("Assets/Audio/fxHitPlayer.wav");
    fxHitWall = LoadSound("Assets/Audio/fxHitWall.wav");
    fxScore = LoadSound("Assets/Audio/GOOOOOOOOAL.wav");
    fxHighlight = LoadSound("Assets/Audio/fxHighlight.wav");
    fxSelect = LoadSound("Assets/Audio/fxSelect.wav");
    fxParticleAccelerator = LoadSound("Assets/Audio/fxFIREINTHEHOLE.wav");
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

void PlayHightlightSound() {
    PlaySound(fxHighlight);
}

void PlaySelectSound() {
    PlaySound(fxSelect);
}

void KABOOM() {
    PlaySound(fxParticleAccelerator);
}

void PlayMainMusic() {
    PlayMusicStream(mxMain);
}

void UpdateAudio() {
    UpdateMusicStream(mxMain);
}