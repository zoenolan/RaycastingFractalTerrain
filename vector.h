/* 									*/
/* 3D vector maths routines for the engine				*/
/*									*/


/*                                                                      */
/* dot product for 2 3-D vector                                         */
/*                                                                      */

double dot (double a[3],double b[3])
 {
  double output; 

  output=(a[0]*b[0])+(a[1]*b[1])+(a[2]*b[2]) ;
  return (output) ;  
 }
/*                                                                      */
/* end dot                                                              */
/*                                                                      */

/*                                                                      */
/* normalize a 3-D vector                                               */
/*                                                                      */
void normalize_3d(double vector[3])
  {
/*           */
/* variables */
/*           */
   double length ;
   
/*            */
/* statements */
/*            */
   
   length=sqrt(vector[0]*vector[0]+vector[1]*vector[1]+vector[2]*vector[2]) ;
   vector[0]=vector[0]/length ;
   vector[1]=vector[1]/length ;
   vector[2]=vector[2]/length ;
  }
/*                                                                      */
/* end normalise 3d                                                     */
/*                                                                      */

