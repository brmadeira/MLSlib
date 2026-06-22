#include "extremal_surface.h"

static double fnl( double t, void *params );
static inline void find_interval( ESOptimizeContext *oc, float &a, float &m, float &b ); 


Vector3 ExtremalSurface::proj( const Vector3 &p )
{
 int niter = 0;
 Vector3 old, current;

 current = p;
 do{
    old = current;
    current = minimize_energy( current );
    niter++;
 }
 while( ( niter < _max_niter ) &&
        (current - old).length() > _convergency_tol );
 
 return current;
}


Vector3 ExtremalSurface::minimize_energy( const Vector3 &p )
{
 int status, iter = 0;
 const gsl_min_fminimizer_type *T;
 gsl_min_fminimizer *s;

 Vector3 v = normal(p);

 ESOptimizeContext *optimize_context = new ESOptimizeContext( this, p, v );

 gsl_function F;
 F.function = &fnl;
 F.params = (void*)optimize_context;
 T = gsl_min_fminimizer_goldensection;
 s = gsl_min_fminimizer_alloc (T);

 float a , b, m;
 find_interval( optimize_context, a, m, b );
 gsl_min_fminimizer_set (s, &F, m, a, b);

 do{
     iter++;
     status = gsl_min_fminimizer_iterate (s);
     m = gsl_min_fminimizer_x_minimum (s);
     a = gsl_min_fminimizer_x_lower (s);
     b = gsl_min_fminimizer_x_upper (s);
     status = gsl_min_test_interval (a, b, _convergency_tol, 0);

     if(status == GSL_SUCCESS )
       break;
 }while ((status == GSL_CONTINUE) && (iter < _max_niter));


 gsl_min_fminimizer_free(s);
 delete optimize_context;
 return p + m*v;
}


static inline void find_interval( ESOptimizeContext *oc, float &a, float &m, float &b )
{
 float radius = oc->s->optimization_radius();

 if( oc->is_near_minimun() ){
   a = -radius;
   m = 0;
   b = radius;
 }
 else{
   b = oc->extremum();
   if( b > 0 ){
     m = b - radius;
     a = b - 2*radius;
   }
   else{
     a = b;
     m = a + radius;
     b = a + 2*radius;
   }
 }
}


static double fnl( double t, void *params )
{
 ESOptimizeContext *c = (ESOptimizeContext*) params;
 Vector3 p = c->p;
 Vector3 v = c->v;
 return c->s->energy( p + v*t );
}
