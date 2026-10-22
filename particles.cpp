#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <cstdlib>
#include "config.h"
#include "game.h"
#include "particles.h"
using namespace std;

vector<Particle> particles;
int particleCountdown = -1;

bool isBallRight = false;

void InitParticles(bool circleRight) {
    Vector2 pos = {circle.x, circle.y};
    particleCountdown = particleLife;
    isBallRight = circleRight;

    for(int i = 0; i < particleCount; i++) {
        float xVel = rand() % 4000 / 1000.0f;
        if(circleRight) {
            xVel *= -1;
        }
        float yVel = (rand() % 8000 - 4000) / 1000.0f;
        Vector2 vel = {xVel, yVel};

        Particle particle = {
            pos,
            vel,
            i % 40
        };

        particles.push_back(particle);
    }
}

void UpdateParticles() {
    if(particleCountdown > 0) {
        particleCountdown--;

        for( int i = 0; i < particles.size(); i++) {
            if(particleCountdown < particleHalfLife) {
                float xVel = (screenWidth / 2 - particles[i].pos.x) / particleCountdown;
                float yVel = (screenHeight / 2 - particles[i].pos.y) / particleCountdown;
                particles[i].vel = {xVel, yVel};
            }
            particles[i].pos += particles[i].vel;
            particles[i].hue++;
        }
    }
    else if(particleCountdown == 0) {
        particleCountdown =  -1;
        particles.clear();
        ResetBall(isBallRight);
    }
}