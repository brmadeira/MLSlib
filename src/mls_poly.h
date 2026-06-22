#ifndef MLS_POLY_SURFACE_H
#define MLS_POLY_SURFACE_H


class MLSPolySurface: public MLSSurface{
  private
    int current_vert;

  public:
    int nvert;
    int nfaces;
    Vector3 *vert;
    Vector3 *proj_vert;
    Traing *face;

    MLSPolySurface();
    MLSPolySurface( FILE *f );
    Vector3 normal( const Vector3 &p );
};

#endif