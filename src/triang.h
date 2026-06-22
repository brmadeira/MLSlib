#ifndef TRIANG_H
#define TRIANG_H

#include "Vector3.h"


struct Triang{
  int v0,v1,v2;

  Triang(){ v0 = 0; v1 = 1; v2 = 2; }
  Triang(int _v0, int _v1, int _v2){ v0 = _v0; v1 = _v1; v2 = _v2; }

  Vector3 normal();
  Vector3 proj( Vector3 p );
};

#endif
