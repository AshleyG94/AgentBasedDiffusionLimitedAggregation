#include <memory>
class Particle
{
    public: 
        Particle();
        Particle( double _x, double _y );
        void Move( double xShift, double yShift );
        bool IsOverlappedBy( std::shared_ptr<Particle> other );
        double GetX(){return x;}
        double GetY(){return y;}
        
    private:
        double x;
        double y;
};