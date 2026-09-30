#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <cstdlib>
#include "config.h"
#include "particles.h"
using namespace std;

vector<Particle> particles;

void InitParticles(Rectangle ball) {
    Vector2 pos = {ball.x, ball.y};
    for(int i = 0; i < particleCount; i++) {
        float xvel = rand() % 2000 - 1000;
        float yvel = rand() % 1000 - 500;
        Vector2 vel = {xvel / 100, yvel / 100};
        Particle particle = {
            pos,
            vel,
            360 / particleCount * i,
            3 * refreshRate
        };
        particles.push_back(particle);
    }
}

void UpdateParticles() {
    for( int i = 0; i < particles.size(); i++) {
        if(particles[i].countdown > 0) {
            particles[i].pos += particles[i].vel;
            particles[i].countdown--;
        }
        else {
            particles.pop_back();
        }
    }
}