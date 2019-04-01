#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {

  //find magnitude of vector
  double magnitude = sqrt((vector[0] * vector[0]) + (vector[1] * vector[1]) + (vector[2] * vector[2]));
  
  //adjust x y z
  vector[0] = vector[0] / magnitude;
  vector[1] = vector[1] / magnitude;
  vector[2] = vector[2] / magnitude;

}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {

  //AxBx + AyBy + AzBz
  return ((a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]));
}



//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {

  //vector initialization
  double *normal = malloc(sizeof(double) * 3);
  double A[3];
  double B[3];
  
  //define vectors
  A[0] = polygons->m[0][i + 1] - polygons->m[0][i];
  A[1] = polygons->m[1][i + 1] - polygons->m[1][i];
  A[2] = polygons->m[2][i + 1] - polygons->m[2][i];
  B[0] = polygons->m[0][i + 2] - polygons->m[0][i];
  B[1] = polygons->m[1][i + 2] - polygons->m[1][i];
  B[2] = polygons->m[2][i + 2] - polygons->m[2][i];

  //cross product
  normal[0] = (A[1] * B[2]) - (A[2] * B[1]);
  normal[1] = (A[2] * B[0]) - (A[0] * B[2]);
  normal[2] = (A[0] * B[1]) - (A[1] * B[0]);

  //return normalized vector
  return normal;
}
