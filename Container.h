#include "Particle.h"
#include <vector>
#include <memory>

class Container
{
    public:
        Container();
        Container( int width, int height );
        void FillWithParticles( const int count );
        void IncrementTime();
        bool IsFullyDiffused() const;
        void PrintResults() const;
        
    private: 
        int FWidth;
        int FHeight;
        std::vector< std::shared_ptr<Particle> > FMobile;
        std::vector< std::shared_ptr<Particle> > FImmobile;
        
        void CheckWallCollisions( std::shared_ptr<Particle> particle );
        void ShiftParticles();
        void HandleParticleCollisions();
        
    
};