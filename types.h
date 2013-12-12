/*									*/
/* types used in the engine						*/
/*									*/

#define MAP_SIZE 1		/* size of the map */

typedef struct			/* viewer/object definition */ 
  {
   double X ;
   double Y ;
   double Z ;
   double X_angle ; 
   double Y_angle ; 
   double Z_angle ;
  } viewer   ;

typedef struct                  /* colour definations */
  {
   float Red ;
   float Green ;
   float Blue ;
   float Alpha ;
  } colour ;

typedef struct                  /* colour definations */
  {
   float Red ;
   float Green ;
   float Blue ;
   float Alpha ;
  } pixel ;

typedef struct                  /* display window defination */
  {
   int X ;
   int Y ;
   int X_size ;
   int Y_size ;
  } viewport ;












