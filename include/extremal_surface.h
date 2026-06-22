#ifndef EXTREMAL_SURFACE_H
#define EXTREMAL_SURFACE_H

#include "es_optimize_context.h"
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_min.h>

/// This class represents Extremal Surfaces. 

class ExtremalSurface{
  public:

/// Extremal Surface normal function.
    virtual Vector3 normal( const Vector3 &p ) = 0;

/// Extremal Surface energy function. x represents the position and a the unoriented direction.
    virtual float energy( const Vector3 &x, Vector3 a ) = 0;

/// Projection operation.
    virtual Vector3 proj( const Vector3 &p );

/// Energy function calculated in the point x considering the local normal value.
    inline float energy( const Vector3 &x ){  return energy( x, normal(x) ); }

/// Sets the size of the intervals used in the beginig of the optimization process.
    inline void optimization_radius( float r ){  _optimization_radius = r; } 

/// Gets the size of the intervals used in the beginig of the optimization process.
    inline const float optimization_radius() const { return _optimization_radius; }

/// Sets the size of the optimized interval, calculated by successives subdivisions.
    inline void convergency_tol( float c ){  _convergency_tol = c; } 

/// Gets the size of the optimized interval, calculated by successives subdivisions.
    inline const float convergency_tol() const { return _convergency_tol; }

/// Sets the maximun number of iterations performed by the optimization algorithm. 
    inline void max_niter( int m ){  _max_niter = m; } 

/// Gets the maximun number of iterations performed by the optimization algorithm.
    inline const int max_niter() const { return _max_niter; }

  private:

/// Size of the intervals used in the begining of the optimization process.
    float _optimization_radius;

/// Size of the optimized interval, calculated by succesives subdivisions.
    float _convergency_tol;

/// Maximun number of iterations performed by the optimization process.
    int _max_niter;
 
  protected:

/// Method that miminizes the energy constrained to the segment that pass throw p whith direction specified by the unoriented normal direction at p.
    virtual Vector3 minimize_energy( const Vector3 &p ); 
};


#endif
