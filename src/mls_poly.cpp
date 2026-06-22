#include "mls_poly.h"

static int get_num( FILE *f, char *s );


MLSPolySurface::MLSPolySurface()
{
 nvert = 0;
 nfaces = 0;
 vert = 0;
 proj_vert = 0;
 face = 0;
}


MLSPolySurface::MLSPolySurface( FILE *f )
{
 nvert = get_num( f, "vertex" );
 nfaces = get_num( f, "face" );
 get_num( f, "end_header" );
 vert = new Vector3[nvert];
 face = new Triang[nfaces];
 
 for( int i = 0; i < nvert; i++ ){
   float x, y, z;

   fscanf( f, "%lf %lf %lf", &x, &y, &z );
   vert[i].setX(x); 
   vert[i].setY(y); 
   vert[i].setZ(z); 
 }

 for( int i = 0; i < nfaces; i++ ){
   int d, v0, v1, v2;
 
   fscanf( f, "%d %d %d %d", &d, &v0, &v1, &v2 );
   face[i].v0 = v0;
   face[i].v1 = v1;
   face[i].v2 = v2;
 }
}


int get_num( FILE *f, char *s )
{
 int r = 0;
 char c[50], aux[50];

 do
   fgets( c, 50, f );
 while( !strstr( c, s ) );
 sscanf( c,"%s %s %d", aux, aux, &r );
 return r;
}


Vector3 MLSPolySurface::normal( const Vector3 &p )
{
 Vector3 n(0,0,0);

 vert[current_vert] = p;

 for( int i = 0; i < nfaces; i++ )
   if( face[i].is_vertice(current_vert) )
     n += face[i].normal();

 n.makeUnitVector();
 
 return n;
}



Vector3 MLSPolySurface::proj( int vertex_index )
{
 Vector3 v;

 current_vertex = vertex_index;
 v = vert[vertex_index];
 ExtremalSurface::proj(v);
 

}




