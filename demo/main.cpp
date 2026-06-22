#include "mls_surface.h"

#define PI 3.1416

int main( int argc, char ** argv )
{
 double u, v, r = 10, R = 12;
 int npoints = 0;
 Vector3 p[1000]; 
 
 for( u = 0; u <= 2*PI; u+= PI/10 )
   for( v = -PI/2.; v <= PI/2.; v+= PI/10 )
     p[npoints++] = Vector3( r*cos(v)*cos(u), r*cos(v)*sin(u), r*sin(v) );

 MLSSurface m(npoints, p);
 m.h(1);
 m.optimization_radius(.5);
 m.convergency_tol(.01);
 m.max_niter(50);

 Vector3 prj,source;
 for( u = -10; u < 10; u+= 1 )
  for( v = 0; v < PI; v += .1 ){
    source = Vector3( R*cos(v), R*sin(v), u  );
    std::cout << "Source: " << source << "\n"; 
    prj = m.proj( source );
    std::cout << "Projection: " << prj << " length: " << prj.length() << "\n";
  }
}

