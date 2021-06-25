#include "Container.h"
#include <iostream>
#include <cmath>
#include <assert.h>

const double speed = 0.1;

Container::Container ()
{
  FWidth = 0;
  FHeight = 0;
}

Container::Container (int _height, int _width):
FHeight (_height),
FWidth (_width)
{
}

void Container::FillWithParticles (const int count)
{
    FMobile.clear ();
    FImmobile.clear ();
    for (int i = 0; i < count - 1; i++)
    {
        double thisX = FWidth * ((float) rand ()) / RAND_MAX;	
        double thisY = FHeight * ((float) rand ()) / RAND_MAX;
        
        std::shared_ptr < Particle > thisPtr (new Particle (thisX, thisY));
        FMobile.push_back (thisPtr);
    }
    std::shared_ptr < Particle > immobilePtr (new Particle (FHeight / 2, FWidth / 2));
    FImmobile.push_back (immobilePtr);
}

void Container::IncrementTime()
{
  ShiftParticles();
  HandleParticleCollisions();
}

void Container::ShiftParticles()
{
    for (int i = 0; i < FMobile.size (); i++)
    {
      double xShift = -speed + ((2 * speed) * ((float) rand ()) / RAND_MAX);
      double yShift = -speed + ((2 * speed) * ((float) rand ()) / RAND_MAX);

      FMobile.at (i)->Move(xShift, yShift);
      CheckWallCollisions(FMobile.at(i));
    }
}

void Container::CheckWallCollisions(std::shared_ptr < Particle > particle)
{
    if (particle->GetX() < 0)
    {
        particle->Move((-2 * particle->GetX ()), 0);
    }
    else if (particle->GetX () > FWidth)
    {
        particle->Move(2 * (FWidth - particle->GetX ()), 0);
    }
    if (particle->GetY() < 0)
    {
        particle->Move(0, -2 * (particle->GetY ()));
    }
    else if (particle->GetY() > FHeight)
    {
        particle->Move(0, 2 * (FHeight - particle->GetY ()));
    }
}

void Container::HandleParticleCollisions()
{
    std::vector < std::shared_ptr < Particle > >toBeImmobilised;
    for (int i = FMobile.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < FImmobile.size (); j++)
	    {
            if (FImmobile.at(j)->IsOverlappedBy (FMobile.at (i)))
	        {
	            toBeImmobilised.push_back(FMobile.at(i));
	            FMobile.erase(FMobile.begin() + i);
	            break;
	        }
	    }
    }

    for (auto it = toBeImmobilised.begin (); it != toBeImmobilised.end (); it++)
    {
        FImmobile.push_back(*it);
    }

    std::cout << FImmobile.size () << " " << FMobile.size () << std::endl;
}

bool Container::IsFullyDiffused () const
{
    return FMobile.size () == 0;
}

void Container::PrintResults () const 
{
    for (int i = 0; i < FImmobile.size (); i++)
    {
        std::cout << "(" << FImmobile[i]->GetX () << "," << FImmobile[i]->GetY () << ")";
    }
}
