#ifndef ES_OPTIMIZE_CONTEXT_H
#define ES_OPTIMIZE_CONTEXT_H

#include "defs.h"
#include "Vector3.h"
#include "extremal_surface.h"

class ExtremalSurface;

/// Class designed to encapsulate all the information needed by the GSL optimization function.

struct ESOptimizeContext{
/// Position in the space.
  const Vector3 &p;

/// Direction in the space.
  const Vector3 &v;

/// Pointer that allows the GSL library to access member functions of surfaces. 
  ExtremalSurface *s;

/// Constructor.
  ESOptimizeContext( ExtremalSurface* _s, Vector3 _p,
                     Vector3 _v ): p(_p), v(_v), s(_s){}
  
/// Increments the value of a parameter t from 0, until the energy associated to p + v*t stops to decay, and return this value of t. 
  float extremum();

/// Returns true if the energy at the point p is smaller than the energy in the neighborhood. 
/** This function is important to detect the case where the function extremum() does not work well.
*/
  bool is_near_minimun();
};

#endif
