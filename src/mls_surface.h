#ifndef MLS_SURFACE_H
#define MLS_SURFACE_H

#include "defs.h"
#include "extremal_surface.h"
#include <gsl/gsl_eigen.h>

/// This class represents Moving Least Squares Surfaces.

class MLSSurface: public ExtremalSurface{
  public: 

/// Default constructor.
    MLSSurface();

/// A construtor that creates an MLS surface instance defined by the array of vectors points, wich has npoints.
/** The constructor creates a new copy of the array points, and assigns it to the member _p. */ 
    MLSSurface( int npoints, Vector3 *points );

/// Destructor.
    ~MLSSurface();

/// Normal estimation in the point specified.
    Vector3 normal( const Vector3 &p );

/// Energy function associated to an MLS Surface. x represents the position and a represents the unoriented direction. 
    float energy( const Vector3 &p, Vector3 n );

/// Gets the number of points wich define the surface.	
    inline const int npoints() const { return _npoints; } 

/// Sets the number of points wich define the surface.	
    inline void npoints( int n ) {  _npoints = n ; } 

/// Gets the set of points wich define the surface.
    inline const Vector3* p() const { return _p ; }

/// Sets the set of points wich define the surface.
    inline void p( Vector3 * points ) { _p = points; }

/// Gets the smoothness parameter of the MLS surface.
    inline const float h() const { return _h; }

/// Sets the smothness parameter of the MLS surface. h low indicates a more local interpolation, h high indicates a global interpolation, creating a smooth surface.
    inline void h( float hh ) { _h = hh; }

  private:

/// Number of point wich define the surface.
    int _npoints;

/// Smoothness parameter of the MLS surface.
    float _h;

/// Set of points wich define the surface.
    Vector3* _p;

/// Influence of the point at the position x.
    inline float weight( const Vector3& x, const Vector3 &point );

/// Weighted co-variance at s along the direction n.
    inline float covariance( const Vector3& s, const Vector3&n );  
}; 


#endif
