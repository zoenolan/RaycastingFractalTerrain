/* 									*/
/* Fractal terrain real-time ray casting engine			  	*/
/*									*/
/* Version Final 96							*/
/*									*/
/* Zoe Nolan 								*/
/*									*/
/* 19/04/96								*/
/* 									*/


/*									*/
/* includes        							*/
/*									*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#include "pvm3.h"			/* PVM include              */
#include "GL/gl.h"			/* OpenGL includes          */
#include "glaux.h"			/* aux library includes     */

#include "types.h"			/* types used by the engine */
#include "message_names.h"              /* message names used       */
#include "vector.h"                     /* 3d vector maths routines */
#include "config.h"                     /* config file reading code */
#include "window.h"			/* window functions         */
#include "save_ppm.h"                  /* jpeg saving code	    */
#include "fast_terrain.h"               /* 2d terrain function      */
#include "keys.h"			/* help key info	    */ 

#define WORKER_NAME "worker"            /* name of worker program   */

#define ROTATION_STEP ((M_PI/180.0)*8)  /* step size for rotations  */
#define MOVE_STEP     1.3		/* step size for movements  */

#define IMAGE_NAME "landscape.ppm"     /* jpeg file name           */

#define MIN_HEIGHT 4.0			/* lowest height from terrain */

int            *Worker_tids;            /* worker tids 		    */
viewer         User ;			/* user view point	    */
double         Light_source[3] ;        /* light source vector      */

unsigned char  *Image_buffer ;          /* image buffer		    */
double         Height ;                 /* height from terrain      */

/*									*/
/* movement routines							*/
/*									*/

void left ()
  {
   User.Z_angle=(User.Z_angle-ROTATION_STEP) ;
   if (User.Z_angle<0)
     {
      User.Z_angle=User.Z_angle+(2*M_PI) ;
     }
  }

void right ()
  {
   User.Z_angle=(User.Z_angle+ROTATION_STEP) ;
   if (User.Z_angle>(2*M_PI))
     {
      User.Z_angle=User.Z_angle-(2*M_PI) ;
     }
  }

void forwards ()
  {
   User.X=User.X+(MOVE_STEP*cos(User.Z_angle)) ;
   User.Y=User.Y+(MOVE_STEP*sin(User.Z_angle)) ;
  }

void backwards ()
  {
   User.X=User.X-(MOVE_STEP*cos(User.Z_angle)) ;
   User.Y=User.Y-(MOVE_STEP*sin(User.Z_angle)) ;
  }

void up ()
  {
   Height=Height+MOVE_STEP ;
  }

void down ()
  {
   Height=Height-MOVE_STEP ;
   if (Height<0)
     {
      Height=0 ;
     }
  }

void save_image ()
  {
/* compress and write the jpeg file */
     		save_ppm(IMAGE_NAME,Image_buffer,User_view.X_size,
            		User_view.Y_size,255) ;
/*   save_jpeg 
(IMAGE_NAME,Image_buffer,75,User_view.X_size,User_view.Y_size) ;
*/   printf ("INFO: Saved JPEG file\n") ;
  }


/* 									*/
/* exit system								*/
/*									*/

void kill_workers ()
  {
   printf ("INFO: Killing the workers\n") ;
/* kill all the worker */
   pvm_initsend(PvmDataDefault) ;
   pvm_mcast (Worker_tids,NUMBER_OF_WORKERS,KILL) ;

/* close the window */
   auxCloseWindow() ;

/* exit pvm */
   pvm_exit() ;
   
/* free the pixel buffer */
   free (Pixel_buffer) ;
   
/* free the pixel buffer */
   free (Image_buffer) ;

/* free the worker tids */
   free (Worker_tids) ;

/* exit the program */
   auxQuit() ;

  }


/*									*/
/* main rendering loop							*/
/*									*/
render_frame()
  {
   pixel Pixel_colour ;	/* pixel colour values */

   int X_counter ;		/* X axis counter */
   int Y_counter ;		/* Y axis counter */
   int Block_counter ;          /* block section counter */
   int Worker_counter ;		/* counter for the number of workers done */

   double Block_angle ;		/* angle between blocks */

   viewer Viewpoint ;		/* the viewpoint of the user */

/* copy the users viewpoint into the working variable */
   Viewpoint.X=User.X ;
   Viewpoint.Y=User.Y ;
   Viewpoint.Z=User.Z ;
   Viewpoint.X_angle=User.X_angle ;
   Viewpoint.Y_angle=User.Y_angle ;
   Viewpoint.Z_angle=User.Z_angle ;
  
/* set up the ray angles */
   Block_angle=(X_view_angle/User_view.X_size)*Pixel_buffer_width ;
   Viewpoint.Z_angle=Viewpoint.Z_angle-(X_view_angle/2)-((1/360)*2*M_PI) ;

   for (Block_counter=0;Block_counter<Number_of_workers;Block_counter++)
     {
/* send out work to worker */
      pvm_initsend (PvmDataDefault) ;

      pvm_pkdouble(&Viewpoint.X,1,1);
      pvm_pkdouble(&Viewpoint.Y,1,1) ;
      pvm_pkdouble(&Viewpoint.Z,1,1) ;
      pvm_pkdouble(&Viewpoint.X_angle,1,1) ;
      pvm_pkdouble(&Viewpoint.Y_angle,1,1) ;
      pvm_pkdouble(&Viewpoint.Z_angle,1,1) ;

      pvm_send (Worker_tids[Block_counter],WORK) ;

/* set the viewpoint for the next one */
      Viewpoint.Z_angle=Viewpoint.Z_angle+Block_angle ;

     }
/* end of for loop */
/* finished sending the data */

/* set the number of workers finished to zero */
   Worker_counter=0 ;

/* get the data back */
   while ( Worker_counter < Number_of_workers)
     {
      for (Block_counter=0;Block_counter<Number_of_workers;Block_counter++)
        {
         if (pvm_probe (Worker_tids[Block_counter],DATA))
/* wait for reply */
           {
            pvm_recv (Worker_tids[Block_counter],DATA) ;
            pvm_upkbyte (Pixel_buffer,Pixel_buffer_size,1) ;

/* increment the counter for the number of workers that have finished */
	    Worker_counter=Worker_counter+1 ;

/* copy the pixel to the image buffer */
            for (X_counter=0 ;
		 X_counter<Pixel_buffer_width ;
                 X_counter++ )
              {
               for (Y_counter=0;
                    Y_counter<User_view.Y_size ;
                    Y_counter++ )
                 {
/* copy pixel data */
		  Image_buffer [(Y_counter*User_view.X_size*3)+
                               (X_counter*3)+
                               (Block_counter*Pixel_buffer_width*3)+
                               0]
		    =
                  Pixel_buffer[(Y_counter*Pixel_buffer_width*3)+
			      (X_counter*3)+
                               0] ;

                  Image_buffer[(Y_counter*User_view.X_size*3)+
                               (X_counter*3)+
                               (Block_counter*Pixel_buffer_width*3)+
                               1]
                     =
                  Pixel_buffer[(Y_counter*Pixel_buffer_width*3)+
                              (X_counter*3)+
                               1] ;

                  Image_buffer[(Y_counter*User_view.X_size*3)+
                               (X_counter*3)+
                               (Block_counter*Pixel_buffer_width*3)+
                               2]
                     =
                  Pixel_buffer[(Y_counter*Pixel_buffer_width*3)+
                              (X_counter*3)+
                               2] ;

/* end Y loop */
                 }

/* end X loop */
               }
         }
/* end the if */

      }
/* end the while loop */

/* end drawing code */
   }

/* copy the data to the window */
     glDrawPixels(User_view.X_size,User_view.Y_size,GL_RGB,
			 GL_UNSIGNED_BYTE,Image_buffer) ;
          
/* flush the graphics pipeline */
   glFlush();

  }
/*                                                                      */
/* Main loop                                                            */
/*                                                                      */
static void display_loop ()
  {
   struct timeval tv1, tv2;        /* for timing */
   int Time_taken ;
   float Point1[2] ;
   float Point2[2] ;
   float Point3[2] ;
   double Terrain_height ;

/* do terrain following */
   Point1[0]=(float)User.X ;
   Point1[1]=(float)User.Y ;

   Point2[0]=(float)User.X+(MOVE_STEP*5*cos(User.Z_angle)) ;
   Point2[1]=(float)User.Y+(MOVE_STEP*5*sin(User.Z_angle)) ;

   Point3[0]=(float)User.X-(MOVE_STEP*5*cos(User.Z_angle)) ;
   Point3[1]=(float)User.Y-(MOVE_STEP*5*sin(User.Z_angle)) ;

   if 
	(HeteroTerrain(Point1,H,Lacunarity,Octaves,Offset)>
	 HeteroTerrain(Point2,H,Lacunarity,Octaves,Offset) )
     {
      Terrain_height=HeteroTerrain(Point1,H,Lacunarity,Octaves,Offset) ;
     }
   else
     {
      Terrain_height=HeteroTerrain(Point2,H,Lacunarity,Octaves,Offset) ;
     }

   if
     (HeteroTerrain(Point3,H,Lacunarity,Octaves,Offset) > Terrain_height)
     {
      Terrain_height=HeteroTerrain(Point3,H,Lacunarity,Octaves,Offset) ;
     }

   User.Z=Terrain_height ;

/* get the start time */
   gettimeofday(&tv1, (struct timezone*)0);

/* render the image */
   render_frame() ;

/* get the end time */
   gettimeofday(&tv2, (struct timezone*)0);

   Time_taken = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec;
   printf ("INFO: Time taken=%i usecs\n",Time_taken) ;
  }


/*									*/
/* main program 							*/
/*									*/

void main (int argc, char** argv)
 {
  int Message_counter ; /* counter for message packing */
  int My_tid ; /* my task id */

/* show start up message */
   printf ("\n-=> Fractal Terrain Engine version 2.1 release 2 <=-\n\n") ;

/* read the config files */
   read_config (argc,argv) ;

/* set up the pixel buffer and it's variables */ 
   Pixel_buffer_width=User_view.X_size/Number_of_workers;
   Pixel_buffer_size=
          Pixel_buffer_width*User_view.Y_size*3*sizeof(unsigned char) ;
   Pixel_buffer=(unsigned char *) malloc(Pixel_buffer_size) ;

/* set up worker tids array */
   Worker_tids=(int *)malloc(Number_of_workers*sizeof(int)) ;

/* set up the image buffer */
   Image_buffer=(unsigned char *) malloc 
      ((User_view.X_size*User_view.Y_size*3*sizeof(unsigned char))) ;

/* start up pvm */
   if ((My_tid = pvm_mytid()) < 0) 
     {
      exit(1);
     }
/* start up the workers */
   
   pvm_spawn(WORKER_NAME,(char**)0,PvmTaskDefault,"",
             Number_of_workers,Worker_tids) ;

   printf ("INFO:Spawned %i Workers\n",Number_of_workers) ;

/* tell the worker what values to use for the terrain function */
   pvm_initsend(PvmDataDefault) ;

   pvm_pkdouble(&H,1,1) ;
   pvm_pkdouble(&Lacunarity,1,1);
   pvm_pkdouble(&Octaves,1,1);
   pvm_pkdouble(&Offset,1,1) ;

   pvm_pkfloat(&Ambient_light,1,1) ;

   pvm_pkfloat(&Fog.Red,1,1) ;
   pvm_pkfloat(&Fog.Green,1,1);
   pvm_pkfloat(&Fog.Blue,1,1) ;

   pvm_pkfloat(&Sky.Red,1,1) ;
   pvm_pkfloat(&Sky.Green,1,1) ;
   pvm_pkfloat(&Sky.Blue,1,1) ;

   pvm_pkfloat(&Horizon.Red,1,1) ;
   pvm_pkfloat(&Horizon.Green,1,1) ;
   pvm_pkfloat(&Horizon.Blue,1,1) ;

   pvm_pkdouble(Colour_boundaries,NUMBER_OF_TERRAIN_COLOURS,1) ;

   for ( Message_counter = 0 ;
         Message_counter<NUMBER_OF_TERRAIN_COLOURS ;
         Message_counter++ )
     {
      pvm_pkfloat(&Terrain_colours[Message_counter].Red,1,1) ;
      pvm_pkfloat(&Terrain_colours[Message_counter].Green,1,1) ;
      pvm_pkfloat(&Terrain_colours[Message_counter].Blue,1,1) ;
     }

   pvm_pkdouble(&Fog_start,1,1) ;
   pvm_pkdouble(&Fog_end,1,1) ;

/* tell the worker what values to use for the display */
   pvm_pkdouble(&Ray_step,1,1) ;
   pvm_pkdouble(&X_view_angle,1,1) ; 
   pvm_pkdouble(&Y_view_angle,1,1) ;
   pvm_pkint(&Pixel_buffer_width,1,1) ;
   pvm_pkint(&User_view.Y_size,1,1) ;
   pvm_pkdouble(&X_ray_angle,1,1) ;
   pvm_pkdouble(&Y_ray_angle,1,1) ;

/* send the message to all the workers */
   pvm_mcast (Worker_tids,Number_of_workers,INFO) ;

/* set up light source */
   normalize_3d(Light_source) ;

/* set the light source */
   Light_source[0]=0.1 ;
   Light_source[1]=0.4 ;
   Light_source[2]=0.3 ;

/* tell the worker what values to use for the light source */
   pvm_initsend(PvmDataDefault) ;
   pvm_pkdouble(Light_source,3,1) ;
   pvm_mcast (Worker_tids,Number_of_workers,NEW_LIGHT_SOURCE) ;

/* set up the users view point */
   Height=1.0 ;
   User.X=0 ;
   User.Y=0 ;
   User.Z=Height ;
   User.X_angle=0.0 ;
   User.Y_angle=0.0 ;
   User.Z_angle=0.0 ;
  
/* set up window */
   open_window() ;
   print_keys() ;

/*									*/
/* set up the keyboard,Reshape and display routines			*/
/*									*/
   auxKeyFunc(AUX_Q,kill_workers) ;
   auxKeyFunc(AUX_q,kill_workers) ;
   auxKeyFunc(AUX_ESCAPE,kill_workers) ;   

   auxKeyFunc(AUX_LEFT,left) ;
   auxKeyFunc(AUX_RIGHT,right) ;
   auxKeyFunc(AUX_UP,forwards) ;
   auxKeyFunc(AUX_DOWN,backwards) ;
   auxKeyFunc(AUX_a,up) ;
   auxKeyFunc(AUX_A,up) ;
   auxKeyFunc(AUX_Z,down) ;
   auxKeyFunc(AUX_z,down) ;

   auxKeyFunc(AUX_J,save_image) ;
   auxKeyFunc(AUX_j,save_image) ;

   auxMainLoop(display_loop) ;

  }
/*									*/
/* end of main								*/
/*									*/






