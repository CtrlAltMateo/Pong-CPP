#include <raylib.h>
#include <vector>
using namespace std;

struct Particle {
    Vector2 pos;
    Vector2 vel;
    float hue;
    int countdown;
};

extern vector<Particle> particles;

void InitParticles(Rectangle ball);

void UpdateParticles();