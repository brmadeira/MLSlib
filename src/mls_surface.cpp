#include "mls_surface.h"

MLSSurface::MLSSurface(){}

MLSSurface::MLSSurface( int npoints, Vector3 *points ): _npoints(npoints)
{
 _p = new Vector3[npoints];
 
 for( int i = 0; i < npoints; i++ )
   _p[i] = points[i];
}

MLSSurface::~MLSSurface()
{
 delete[] _p;
}


/** Explanation in "Approximating and Intersecting Surfaces from Points" Eurographics Symposiun on Geometry Processing 2003." Anderson Adamson and Marc Alexa. pg 232.*/ 

Vector3 MLSSurface::normal( const Vector3 &point )
{
 double sigma[3];
 gsl_vector *n = gsl_vector_alloc( 3 );
 gsl_matrix *m = gsl_matrix_alloc( 3, 3 );
 gsl_matrix *evec = gsl_matrix_alloc ( 3, 3 );
 gsl_vector *eval = gsl_vector_alloc ( 3 );
 gsl_eigen_symmv_workspace *w = gsl_eigen_symmv_alloc(3);

 sigma[0] = covariance( point, Vector3(1,0,0) );
 sigma[1] = covariance( point, Vector3(0,1,0) );
 sigma[2] = covariance( point, Vector3(0,0,1) );

 for( int i = 0; i < 3 ; i++ )
   for( int j = 0; j < 3; j++ )
     gsl_matrix_set( m, i, j, sigma[i]*sigma[j] );
 
 gsl_eigen_symmv( m , eval, evec, w);
 gsl_eigen_symmv_sort(eval, evec, GSL_EIGEN_SORT_ABS_ASC);

// try gsl_matrix_get_col( n, evec, 0 ) if GSLlib change 
 gsl_matrix_get_col( n, evec, 2 ); 
 Vector3 v = gsl_to_vector3( n );

 gsl_eigen_symmv_free(w);
 gsl_vector_free( n );
 gsl_matrix_free( m );
 gsl_matrix_free( evec );
 gsl_vector_free( eval ); 

 return v;
}


/** Function that increase with the distancy of the point cloud. It avoids errors during the optimization process. Reference: ALEXA M. BEHR J., COHEN-OR D.FLEISHMAN S. LEVIN D. SILVA C. T: Computing and rendering point set surfaces. IEEE Transaction on Visualization and Computer Graphics 9, 1 (2003). 
*/ 

float MLSSurface::energy( const Vector3 &x, Vector3 a )
{
 double e = 0, s = 0;

 for( int i = 0; i < _npoints; i++ )
   s += exp( -SQR( (x - _p[i]).length()/_h ) );

 a.makeUnitVector();
 for( int i = 0; i < _npoints; i++ )
   e += ( SQR( dot(a,_p[i]) - dot(a,x) )*weight(x,_p[i])/s );

 return e;
}


inline float MLSSurface::weight( const Vector3 &x, const Vector3 &point )
{
 return exp( -SQR( (x - point).length()/_h ) );
}


/** Explanation in "Approximating and Intersecting Surfaces from Points" Eurographics Symposiun on Geometry Processing 2003." Anderson Adamson and Marc Alexa. pg 232.*/ 

inline float MLSSurface::covariance( const Vector3& s, const Vector3&n )
{
 float a = 0, b = 0;

 for( int i = 0; i < _npoints; i++ )
   a += weight( s, _p[i] )*( dot( n, s - _p[i] ) );

 return a;
}

