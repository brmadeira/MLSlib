#include "es_optimize_context.h"


float ESOptimizeContext::extremum()
{
 float e, ne, t = 0, dt = s->optimization_radius();
 
 e = s->energy( p );
 if( s->energy( p + v*dt ) > e )
    dt = -dt; 
 while( (ne = s->energy( p + v*t )) <= e ){
    e = ne;
    t += dt;
 }

 return t;
}


bool ESOptimizeContext::is_near_minimun()
{
 float local_energy = s->energy( p );
 float dt = s->optimization_radius();

 if( (s->energy( p + v*dt ) > local_energy)  &&
     (s->energy( p - v*dt ) > local_energy) )
   return true;
 else 
   return false; 
}


