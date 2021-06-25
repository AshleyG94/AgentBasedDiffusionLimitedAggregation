/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include "Container.h"
#include <time.h>
using namespace std;



int main()
{
    srand (time(NULL));
    Container world(10,10);
    world.FillWithParticles(1000);
    while( !world.IsFullyDiffused() )
    {
        world.IncrementTime();
    }
    world.PrintResults();
}
