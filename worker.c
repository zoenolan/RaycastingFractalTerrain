/*                                                                         */
/* Ray-casting terrain engine using perlin noise functions                 */
/*                                                                         */
/* Version Final 96                                                        */
/*                                                                         */
/* Zoe Nolan                                                              */
/*                                                                         */
/* 19/04/95                                                                */
/*                                                                         */

/*******************/
/*                 */
/* includes        */
/*                 */
/*******************/

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "pvm3.h"                       /* PVM include */

#include "fast_terrain.h"               /* 2d terrain function */
#include "types.h"                      /* types used by the engine */
#include "message_names.h"              /* message names used       */
#include "vector.h"                     /* 3d vector maths routines */

#include "global_world_variables.h"
#include "global_display_variables.h"

#define NORMAL_HEIGHT 0.0020		/* height of the normal vector */
#define MIN_OCTAVES   3			/* the min number of octaves in */
/* the terrain */

/*									*/
/* Global variables							*/
/*									*/

double *Height_buffer ; 		/* height buffer pointer */

int My_tid ; 				/* my task id */
int Parent ;          			/* Parent task ID */

/*									*/
/*									*/
/* draw a section							*/
/*									*/
/*									*/
/*									*/

work()
{
	viewer Camera ;	/* viewpoint */
	viewer Temp ;         /* viewpoint */

	int X_counter ;       /* X axis counter */
	int Y_counter ;       /* Y axis counter */
	int X_pixel_counter ; /* X axis counter for pixel loop */
	int Y_pixel_counter ; /* Y axis counter for pixel loop */
	int Sky_counter ;     /* sky data counter for the height buffer */
	int Colour_counter ;  /* counter for landscape colours */

	int Jumps ;           /* Number of jumps taken */

	double Add_vector[3] ;/* The Vector that is added to the ray each step*/

	float Point[2] ;      /* 2D noise coordinates */

	double Jump_size ;    /* Jump size */

	int Sky_flag ;	/* Flag to show that the sky has been reached */

	colour Pixel ;        /* colour of a pixel */

	int My_tid ; 		/* my task id */

	double Z_left ;	/* heights for the normal vector */
	double Z_right ;
	double Z_up ;
	double Z_down ;

	double Height ;       /* The hight of the terrain in texture coords*/

	float Diffuse ;	/* the diffuse lighting */
	float Light ;		/* total light in the scene */

	float Fog_factor ;    /* How much to fog the pixel by */
	double Distance ;     /* ray length */

	double Normal[3] ;       /* pixel normal */

	double Octaves_used ; /* the number of octaves used in the terrain */
	double Add_octaves ;  /* the number of octaves to add to the terrain */

	/*									*/
	/* Drawing code 							*/
	/*									*/

	/* get the message */
	pvm_recv (Parent,WORK) ;

	/* unpack the message */
	pvm_upkdouble(&Camera.X,1,1) ;
	pvm_upkdouble(&Camera.Y,1,1) ;
	pvm_upkdouble(&Camera.Z,1,1) ;
	pvm_upkdouble(&Camera.X_angle,1,1) ;
	pvm_upkdouble(&Camera.Y_angle,1,1) ;
	pvm_upkdouble(&Camera.Z_angle,1,1) ;

	/*						*/
	/* calculate all the heights for this section 	*/
	/*						*/

	/* set up the position */
	Temp.Y_angle=Camera.Y_angle ;
	Temp.Z_angle=Camera.Z_angle ;

	/* calculate all the ray intersects for this section */

	for (X_counter=0;X_counter<(Pixel_buffer_width+2);X_counter++)
	{
		/* set up x angle for this */
		Temp.X_angle=Camera.X_angle-(Y_view_angle/2) ;

		/* set distance */
		Distance=0.0 ;

		/* set octaves */
		Octaves_used=Octaves ;

		/* set the y counter to zero */
		Y_counter=0 ;

		/* y axis loop */

		while ( (Y_counter<(User_view.Y_size)) && (Distance<Fog_end))
		{
			/* do each ray */

			/* calculate the vector to add on each step */
			Add_vector[0]=Ray_step*((double)cos(Temp.Z_angle))  ;

			Add_vector[1]=Ray_step*((double)sin(Temp.Z_angle)*
				cos(Temp.X_angle)) ;
			Add_vector[2]=Ray_step*((double)sin(Temp.X_angle)) ;

			/* move to the right start position in the ray */
			Jumps=Distance/Ray_step ;

			/* set the ray starting position */
			Temp.X=Camera.X+(Jumps*Add_vector[0])  ;
			Temp.Y=Camera.Y+(Jumps*Add_vector[1])  ;
			Temp.Z=Camera.Z+(Jumps*Add_vector[2])  ;

			/* set up the noise data */
			Point[0]=(float)(Temp.X/MAP_SIZE) ;
			Point[1]=(float)(Temp.Y/MAP_SIZE) ;

			/* cast the ray */

			Height=Temp.Z/MAP_SIZE  ;

			while ( (Distance<Fog_end) &&
				(Height>(double)HeteroTerrain(Point,H,Lacunarity,Octaves_used,Offset)))
			{
				/* set jump size */
				Jump_size=1+Distance*(Fog_end/(Fog_end-Distance));

				/* move along each ray */
				Temp.X=Temp.X+Add_vector[0]*Jump_size ;
				Temp.Y=Temp.Y+Add_vector[1]*Jump_size ;
				Temp.Z=Temp.Z+Add_vector[2]*Jump_size ;

				/* increase distance travelled */
				Distance=Distance+(Ray_step*Jump_size) ;

				/* see if the number of octaves can be dicreased */
				Add_octaves=(int)
					(((Octaves-MIN_OCTAVES)/Fog_end)*Distance) ;
				Octaves_used=Octaves-Add_octaves ;

				Height=Temp.Z/MAP_SIZE ;

				/*				*/
				/* update point 		*/
				/*				*/

				Point[0]=(float)(Temp.X/MAP_SIZE) ;
				Point[1]=(float)(Temp.Y/MAP_SIZE) ;
			}  ;
			/*									*/
			/* the ray now has hit the landscape or travelled past the max distance */
			/*									*/

			/* check distance */
			if ( ( Distance>Fog_end) )
			{
				/* ray moved passed the drawing limit */

				for
					(Sky_counter=Y_counter;
				Sky_counter<(User_view.Y_size);
				Sky_counter++)
				{
					/* save the height in the buffer */
					Height_buffer
						[(Sky_counter*(Pixel_buffer_width+2)*2)+
						(X_counter*2)]=-1 ;
					Height_buffer
						[(Sky_counter*(Pixel_buffer_width+2)*2)+
						(X_counter*2)+1]=Distance ;
				}
			}
			else
			{
				/* save the height in the buffer */
				Height_buffer
					[(Y_counter*(Pixel_buffer_width+2)*2)+
					(X_counter*2)]=Temp.Z  ;
				Height_buffer
					[(Y_counter*(Pixel_buffer_width+2)*2)+
					(X_counter*2)+1]=Distance ;
			}

			/* update x view angle */
			Temp.X_angle=Temp.X_angle+Y_ray_angle ;

			/* update counter */
			Y_counter=Y_counter+1 ;

			/* end of y loop */
		}

		/* update z view angle */
		Temp.Z_angle=Temp.Z_angle+X_ray_angle ;
	}
	/*                                                                      */
	/* end of buffer loop                                                   */
	/*                                                                      */

	/*                                                                      */
	/* Pixel loop 								*/
	/*                                                                      */

	/* buffer x loop */
	for
		(X_pixel_counter=1;
	X_pixel_counter<(Pixel_buffer_width+1);
	X_pixel_counter++)
	{
		/* set sky flag */
		Sky_flag=0 ;	/* sky not reached */

		for (Y_pixel_counter=0;
			Y_pixel_counter<(User_view.Y_size);
			Y_pixel_counter++)
		{
			/* load variables from height buffer */
			Temp.Z=Height_buffer
				[(Y_pixel_counter*(Pixel_buffer_width+2)*2)+
				(X_pixel_counter*2)] ;
			Distance=Height_buffer
				[(Y_pixel_counter*(Pixel_buffer_width+2)*2)+
				(X_pixel_counter*2)+1];

			/*									*/
			/* calculate colour of pixel 						*/
			/*									*/

			/* check distance */
			if ( (Distance>Fog_end))
			{
				/* ray moved passed the drawing limit */

				/* draw sky colour */
				Pixel.Red=Sky.Red ;
				Pixel.Green=Sky.Green ;
				Pixel.Blue=Sky.Blue ;
			}
			else
			{
				/*									*/
				/* draw the landscape 							*/
				/*									*/

				/* do the lighting of the scene */

				/* work out the lighting for the point */

				/* find the normal */

				/* left and right points */
				Z_left=Height_buffer
					[(Y_pixel_counter*(Pixel_buffer_width+2)*2)+
					((X_pixel_counter+1)*2)] ;

				Z_right=Height_buffer
					[(Y_pixel_counter*(Pixel_buffer_width+2)*2)+
					((X_pixel_counter-1)*2)] ;

				/* up and down points */
				if (Y_pixel_counter==0)
				{
					/* do top of image */
					Z_up=Temp.Z ;

					Z_down=Height_buffer
						[((Y_pixel_counter+1)*(Pixel_buffer_width+2)*2)+
						(X_pixel_counter*2)] ;
				}
				else if (Y_pixel_counter==User_view.Y_size)
				{
					/* do bottom of image */
					Z_up=Height_buffer
						[((Y_pixel_counter-1)*(Pixel_buffer_width+2)*2)+
						(X_pixel_counter*2)] ;

					Z_down=Temp.Z ;
				}
				else
				{
					/* do the middle of the image */
					Z_up=Height_buffer
						[((Y_pixel_counter-1)*(Pixel_buffer_width+2)*2)+
						(X_pixel_counter*2)] ;

					Z_down=Height_buffer
						[((Y_pixel_counter+1)*(Pixel_buffer_width+2)*2)+
						(X_pixel_counter*2)] ;
				}

				/* set the normal */
				Normal[0]=Z_left+Z_right-(Temp.Z*2) ;
				Normal[1]=Z_up+Z_down-(Temp.Z*2) ;
				Normal[2]=NORMAL_HEIGHT  ;

				/* normalise the vector */
				normalize_3d(Normal) ;

				/* work out the angle between that normal and the light source */

				Diffuse=dot(Light_source,Normal) ;
				if (Diffuse<0)
				{
					/* if the value is less than 0 set that point to black */
					Diffuse=0.0 ;
				}
				/* add in ambient lighting */
				Light=Ambient_light+Diffuse*(1-Ambient_light) ;

				/* limit colour value */
				if (Light>1.0)
				{
					Light=1.0 ;
				}

				/* colour the landscape depending on height */
				Colour_counter=0 ;

				/* find the right colour */
				while ((Colour_boundaries[Colour_counter]>Temp.Z)
					&& (Colour_counter<NUMBER_OF_TERRAIN_COLOURS) )
				{
					Colour_counter++ ;
				}

				if (Colour_counter>(NUMBER_OF_TERRAIN_COLOURS-1))
				{
					Colour_counter=(NUMBER_OF_TERRAIN_COLOURS-1) ;
				}

				/* colour the pixel */
				Pixel.Red=Terrain_colours[Colour_counter].Red*Light ;
				Pixel.Green=Terrain_colours[Colour_counter].Green*Light ;
				Pixel.Blue=Terrain_colours[Colour_counter].Blue*Light ;

				/* fog the landscape */
				if (Distance > Fog_start)
				{
					Fog_factor=
						(Distance-Fog_start)/(Fog_end-Fog_start) ;
					Pixel.Red=
						Pixel.Red+(Fog.Red-Pixel.Red)*Fog_factor ;
					Pixel.Green=
						Pixel.Green+(Fog.Green-Pixel.Green)*Fog_factor ;
					Pixel.Blue=
						Pixel.Blue+(Fog.Blue-Pixel.Blue)*Fog_factor ;
				}
				/* end of fogging */
			}

			/*                                                                      */
			/* end of landscape shading and fogging code                            */
			/*                                                                      */

			/* save the colours in the pixel buffer*/
			Pixel_buffer
				[(Y_pixel_counter*Pixel_buffer_width*3)+
				((X_pixel_counter-1)*3)+0]=(unsigned char)(255.0*Pixel.Red) ;
			Pixel_buffer
				[(Y_pixel_counter*Pixel_buffer_width*3)+
				((X_pixel_counter-1)*3)+1]=(unsigned char)(255.0*Pixel.Green);
			Pixel_buffer
				[(Y_pixel_counter*Pixel_buffer_width*3)+
				((X_pixel_counter-1)*3)+2]=(unsigned char)(255.0*Pixel.Blue) ;

			/* end drawing section */
		}
		/* end y loop */
	}
	/* end x loop */

	/* send message to engine */
	pvm_initsend (PvmDataDefault) ;
	pvm_pkbyte (Pixel_buffer,Pixel_buffer_size,1) ;
	pvm_send (Parent,DATA) ;
}
/*									*/
/* end drawing section 							*/
/*									*/

/*									*/
/* main program								*/
/*									*/

main (int argc, char** argv)
{
	int End_flag=0 ;      /* flag for exiting the worker */
	int Message_counter ; /* Used for message unpacking */

	viewer Camera ;

	/* get task id */
	My_tid=pvm_mytid() ;

	/* get parent tasks tid */
	Parent=pvm_parent() ;

	/* get message containing start angles and x,y,z positions */
	pvm_recv (Parent,INFO) ;

	/* tell the worker what values to use for the terrain function */
	pvm_upkdouble(&H,1,1);
	pvm_upkdouble(&Lacunarity,1,1);
	pvm_upkdouble(&Octaves,1,1);
	pvm_upkdouble(&Offset,1,1) ;

	pvm_upkfloat(&Ambient_light,1,1) ;

	pvm_upkfloat(&Fog.Red,1,1);
	pvm_upkfloat(&Fog.Green,1,1) ;
	pvm_upkfloat(&Fog.Blue,1,1) ;

	pvm_upkfloat(&Sky.Red,1,1) ;
	pvm_upkfloat(&Sky.Green,1,1) ;
	pvm_upkfloat(&Sky.Blue,1,1) ;

	pvm_upkfloat(&Horizon.Red,1,1) ;
	pvm_upkfloat(&Horizon.Green,1,1) ;
	pvm_upkfloat(&Horizon.Blue,1,1) ;

	pvm_upkdouble(Colour_boundaries,NUMBER_OF_TERRAIN_COLOURS,1) ;

	for ( Message_counter = 0 ;
		Message_counter<NUMBER_OF_TERRAIN_COLOURS ;
		Message_counter++ )
	{
		pvm_upkfloat(&Terrain_colours[Message_counter].Red,1,1) ;
		pvm_upkfloat(&Terrain_colours[Message_counter].Green,1,1) ;
		pvm_upkfloat(&Terrain_colours[Message_counter].Blue,1,1) ;
	}

	pvm_upkdouble (&Fog_start,1,1) ;
	pvm_upkdouble (&Fog_end,1,1) ;

	/* tell the worker what values to use for the display */
	pvm_upkdouble(&Ray_step,1,1) ;
	pvm_upkdouble(&X_view_angle,1,1) ;
	pvm_upkdouble(&Y_view_angle,1,1) ;
	pvm_upkint(&Pixel_buffer_width,1,1) ;
	pvm_upkint(&User_view.Y_size,1,1) ;
	pvm_upkdouble(&X_ray_angle,1,1) ;
	pvm_upkdouble(&Y_ray_angle,1,1) ;

	/* set up the pixel buffer and it's variables */
	User_view.X_size=Pixel_buffer_width ;
	Pixel_buffer_size=Pixel_buffer_width*User_view.Y_size*3 ;
	Pixel_buffer=(unsigned char *) malloc
		(Pixel_buffer_size*sizeof(unsigned char)) ;

	/* set up the height buffer */
	Height_buffer=(double *) malloc
		((Pixel_buffer_width+2)*User_view.Y_size*2*sizeof(double)) ;

	/* tell the worker what values to use for the light source */
	pvm_recv (Parent,NEW_LIGHT_SOURCE) ;
	pvm_upkdouble(Light_source,3,1) ;

	/* wait for message */
	/* it will be work or the kill message */

	while (End_flag!=1)
	{
		if (pvm_probe (Parent,KILL))
		{
			/* get the kill message */
			pvm_recv(Parent,KILL) ;
			End_flag=1 ;
		}

		else if (pvm_probe (Parent,NEW_LIGHT_SOURCE))
		{
			/* new light source */
			pvm_recv(Parent,NEW_LIGHT_SOURCE) ;
			pvm_upkdouble(Light_source,3,1) ;
		}

		else if (pvm_probe (Parent,WORK))
		{
			/* do the work */
			work() ;
		}
	} /* end while */

	/* exit pvm */
	pvm_exit()  ;

	/* free the pixel buffer */
	free (Pixel_buffer) ;

	/* free the height buffer */
	free (Height_buffer) ;
}
/* end of worker */