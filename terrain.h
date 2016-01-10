/*
 * Heterogeneous procedural terrain function: stats by altitude method.
 * Evaluated at "point"; returns value stored in "value".
 *
 * Copyright 1994 F. Kenton Musgrave 
 * 
 * Parameters:
 *       ``H''  determines the fractal dimension of the roughest areas
 *       ``lacunarity''  is the gap between successive frequencies
 *       ``octaves''  is the number of frequencies in the fBm
 *       ``offset''  raises the terrain from `sea level'
 *
 * From 'Texturing & Modeling A Procedural Approach
 * https://engineering.purdue.edu/~ebertd/texture/1stEdition/musgrave/musgrave.c
 * 
 */

#include "noise.h"      /* Perlin's  noise functions */

double HeteroTerrain(float point[3],double H,double lacunarity,double
					 octaves,double offset)
{
	double value,increment,frequency,remainder;

	int i;

	static int first=1;

	static double *exponentArray;

	/* precompute and store spectral weights for efficiency */

	if (first)
	{
		/* seize required amount of memory for the exponentArray */
		exponentArray = (double *) malloc( (int)((octaves+1) * sizeof(double)) );

		/* if the memory can not be allocated exit and display an error message */
		if (exponentArray==NULL)
		{
			fprintf(stderr,"Couldn't get enougn memory!\n");
			exit(1);
		}

		frequency =1.0;

		for (i=0;i<=octaves;i++)
		{
			/* compute weight for each frequency */
			exponentArray[i]=pow(frequency,-H);
			frequency*=lacunarity;
		}
		first=0;
	}

	/* first unscaled octave of function;later octaves are scaled */
	printf ("%f\n",point[2]) ;
	value=noise3(point) +offset;
	point[0]*=lacunarity;
	point[1]*=lacunarity;
	point[2]*=lacunarity;

	/* spectral constuction inner loop, where the fractal is built */
	for (i=1;i<octaves;i++)
	{
		/* obtain displaced noise value */
		/* scale amplitude appropriately for this frequency */
		increment =(noise3(point)+offset)*exponentArray[i] ;

		/* scale increment by the current 'altitude' of function */
		increment *= value;
		value +=increment;

		/* raise spacial frequency */
		point[0]*=lacunarity;
		point[1]*=lacunarity;
		point[2]*=lacunarity;
	}

	/* take care of remainder in octaves */
	remainder=octaves-(int)octaves;
	if (remainder)
	{
		/* i and spatial frequency are preset in loop above*/
		/* note that the main loop code is made shorter here */
		printf ("%f\n",point[2]) ;

		increment=(noise3(point)+offset)*exponentArray[i];
		value+=remainder*increment*value;
	}
	return value;
}
/* end */
