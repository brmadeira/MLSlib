#ifndef DEFS_H
#define DEFS_H

#include <gsl/gsl_vector.h>
#include "Vector3.h"


#define SQR(X) ((X)*(X)) 

/// Converts GSL Vector representation to Vector3.

inline Vector3 gsl_to_vector3( gsl_vector *v )
{
 return Vector3( gsl_vector_get( v, 0 ),
                 gsl_vector_get( v, 1 ),
		 gsl_vector_get( v, 2 ) );
}


#endif
