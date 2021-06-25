#include "Particle.h"
#include <math.h> 
const double OVERLAP_RADIUS = 0.1;

Particle::Particle()
{
    x = 0.0;
    y = 0.0;
}

Particle::Particle(double _x, double _y):
x(_x), y(_y)
{
}

void Particle::Move(double xShift, double yShift)
{
    x += xShift;
    y += yShift;
}

bool Particle::IsOverlappedBy(std::shared_ptr<Particle> other)
{
    double xDiff = x - other->GetX();
    double yDiff = y - other->GetY();
    if ( fabs(xDiff) < OVERLAP_RADIUS && fabs(yDiff) < OVERLAP_RADIUS )
        return true;
    return false;
}