/* 									*/
/* the world variables for the engine 					*/
/*									*/


#define NUMBER_OF_TERRAIN_COLOURS 25 	/* this is the number of colours */
/* for the terrain */

double H ; 				/* determines the fractal */
/* dimension of the roughest areas */
double Lacunarity ; 			/* the gap between frequencies */ 
double Octaves ; 			/* the number of octaves in the */ 
/* terrain */
double Offset ; 			/* the offset from 0 of the */
/* terrain */

double Colour_boundaries[NUMBER_OF_TERRAIN_COLOURS] ;
/* boundaries between the colours */
colour Terrain_colours[NUMBER_OF_TERRAIN_COLOURS] ;
/* terain colours */
colour Sky ;				/* the sky colour */
colour Horizon ;			/* the Horizon colour */
colour Fog ;				/* the fog colour */
float  Ambient_light ;			/* the amount of ambient light */
double Light_source[3] ;		/* the light source vector */
double Fog_start ;			/* the fog start distance */
double Fog_end ;			/* the fog end  distance */
