#include <raylib.h>
#include <vector>
using namespace std;

extern int particleCountdown;

struct Particle {
    Vector2 pos;
    Vector2 vel;
    float hue;
};

extern vector<Particle> particles;

void InitParticles(bool circleRight);

void UpdateParticles();