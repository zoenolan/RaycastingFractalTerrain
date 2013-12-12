/* 									*/
/* config the engine							*/
/*									*/

#include <string.h>

#include "world_defaults.h"
#include "display_defaults.h"

#include "global_world_variables.h"
#include "global_display_variables.h"

/*                                                                      */
/* file names                                                           */
/*                                                                      */

#define DEFAULT_WORLD_FILE   ".worldrc"    /* default world file to use   */
#define DEFAULT_DISPLAY_FILE ".displayrc"  /* default display file to use */
#define DISPLAY_TOKEN "-visual"		   /* display command line option */
#define WORLD_TOKEN "-world"		   /* world command line option   */
#define NUMBER_OF_OPTIONS 2                /* number of command line      */
    					   /* options			  */


/*                                                                      */
/* getline: read a line ,return length                                  */
/*                                                                      */
int getline (char *Line,int Max,FILE *Config_file)
  {
   if (fgets(Line,Max,Config_file)==NULL)
     {
      return 0;
     }
   else
     {
      return strlen(Line);
     }
  }

/*                                                                      */   
/* read spaces: returns the distance to the end of spaces               */
/*                                                                      */
   
int read_spaces (char *Line)
  {
   int Count ;
/* read spaces */
   Count=0 ;
   while ( ((Line[Count] == ' ')|| (Line[Count] =='\t'))
          && (Count<79) )
     {
      Count++;
     }
   return Count ;
  }   

/*                                                                      */
/* read to comma : returns the distance to the comma                    */
/*                                                                      */

int read_to_comma (char *Line)
  {
   int Count ;
/* read to comma */
   Count=0 ;
   while ( (Line[Count] != ',') && (Count<79) )
     {
      Count++;
     }
   return Count ;
  }


/*									*/
/* set the default world values 					*/
/*									*/

default_world_config()
 {
/* set default terrain function variables */
	H=DEFAULT_H ;
	Lacunarity=DEFAULT_LACUNARITY ;
	Octaves=DEFAULT_OCTAVES ;
	Offset=DEFAULT_OFFSET ;

/* set default colour boundaries */
	Colour_boundaries[0]=DEFAULT_COLOUR_BOUNDARIES_01 ;
	Colour_boundaries[1]=DEFAULT_COLOUR_BOUNDARIES_02 ;
	Colour_boundaries[2]=DEFAULT_COLOUR_BOUNDARIES_03 ;
	Colour_boundaries[3]=DEFAULT_COLOUR_BOUNDARIES_04 ;
	Colour_boundaries[4]=DEFAULT_COLOUR_BOUNDARIES_05 ;
	Colour_boundaries[5]=DEFAULT_COLOUR_BOUNDARIES_06 ;
	Colour_boundaries[6]=DEFAULT_COLOUR_BOUNDARIES_07 ;
	Colour_boundaries[7]=DEFAULT_COLOUR_BOUNDARIES_08 ;
	Colour_boundaries[8]=DEFAULT_COLOUR_BOUNDARIES_09 ;
	Colour_boundaries[9]=DEFAULT_COLOUR_BOUNDARIES_10 ;
	Colour_boundaries[10]=DEFAULT_COLOUR_BOUNDARIES_11 ;
	Colour_boundaries[11]=DEFAULT_COLOUR_BOUNDARIES_12 ;
	Colour_boundaries[12]=DEFAULT_COLOUR_BOUNDARIES_13 ;
	Colour_boundaries[13]=DEFAULT_COLOUR_BOUNDARIES_14 ;
	Colour_boundaries[14]=DEFAULT_COLOUR_BOUNDARIES_15 ;
	Colour_boundaries[15]=DEFAULT_COLOUR_BOUNDARIES_16 ;
	Colour_boundaries[16]=DEFAULT_COLOUR_BOUNDARIES_17 ;
	Colour_boundaries[17]=DEFAULT_COLOUR_BOUNDARIES_18 ;
	Colour_boundaries[18]=DEFAULT_COLOUR_BOUNDARIES_19 ;
	Colour_boundaries[19]=DEFAULT_COLOUR_BOUNDARIES_20 ;
	Colour_boundaries[20]=DEFAULT_COLOUR_BOUNDARIES_21 ;
	Colour_boundaries[21]=DEFAULT_COLOUR_BOUNDARIES_22 ;
	Colour_boundaries[22]=DEFAULT_COLOUR_BOUNDARIES_23 ;
	Colour_boundaries[23]=DEFAULT_COLOUR_BOUNDARIES_24 ;
	Colour_boundaries[24]=DEFAULT_COLOUR_BOUNDARIES_25 ;

/* set default landscape colours */
        Terrain_colours[0].Red=DEFAULT_COLOUR_00_RED ;
        Terrain_colours[0].Green=DEFAULT_COLOUR_00_GREEN ;
        Terrain_colours[0].Blue=DEFAULT_COLOUR_00_BLUE ;

        Terrain_colours[1].Red=DEFAULT_COLOUR_01_RED ;
        Terrain_colours[1].Green=DEFAULT_COLOUR_01_GREEN ;
        Terrain_colours[1].Blue=DEFAULT_COLOUR_01_BLUE ;

        Terrain_colours[2].Red=DEFAULT_COLOUR_02_RED ;
        Terrain_colours[2].Green=DEFAULT_COLOUR_02_GREEN ;
        Terrain_colours[2].Blue=DEFAULT_COLOUR_02_BLUE ;

        Terrain_colours[3].Red=DEFAULT_COLOUR_03_RED ;
        Terrain_colours[3].Green=DEFAULT_COLOUR_03_GREEN ;
        Terrain_colours[3].Blue=DEFAULT_COLOUR_03_BLUE ;

        Terrain_colours[4].Red=DEFAULT_COLOUR_04_RED ;
        Terrain_colours[4].Green=DEFAULT_COLOUR_04_GREEN ;
        Terrain_colours[4].Blue=DEFAULT_COLOUR_04_BLUE ;

        Terrain_colours[5].Red=DEFAULT_COLOUR_05_RED ;
        Terrain_colours[5].Green=DEFAULT_COLOUR_05_GREEN ;
        Terrain_colours[5].Blue=DEFAULT_COLOUR_05_BLUE ;

        Terrain_colours[6].Red=DEFAULT_COLOUR_06_RED ;
        Terrain_colours[6].Green=DEFAULT_COLOUR_06_GREEN ;
        Terrain_colours[6].Blue=DEFAULT_COLOUR_06_BLUE ;

        Terrain_colours[7].Red=DEFAULT_COLOUR_07_RED ;
        Terrain_colours[7].Green=DEFAULT_COLOUR_07_GREEN ;
        Terrain_colours[7].Blue=DEFAULT_COLOUR_07_BLUE ;

        Terrain_colours[8].Red=DEFAULT_COLOUR_08_RED ;
        Terrain_colours[8].Green=DEFAULT_COLOUR_08_GREEN ;
        Terrain_colours[8].Blue=DEFAULT_COLOUR_08_BLUE ;

        Terrain_colours[9].Red=DEFAULT_COLOUR_09_RED ;
        Terrain_colours[9].Green=DEFAULT_COLOUR_09_GREEN ;
        Terrain_colours[9].Blue=DEFAULT_COLOUR_09_BLUE ;

        Terrain_colours[10].Red=DEFAULT_COLOUR_10_RED ;
        Terrain_colours[10].Green=DEFAULT_COLOUR_10_GREEN ;
        Terrain_colours[10].Blue=DEFAULT_COLOUR_10_BLUE ;

        Terrain_colours[11].Red=DEFAULT_COLOUR_11_RED ;
        Terrain_colours[11].Green=DEFAULT_COLOUR_11_GREEN ;
        Terrain_colours[11].Blue=DEFAULT_COLOUR_11_BLUE ;

        Terrain_colours[12].Red=DEFAULT_COLOUR_12_RED ;
        Terrain_colours[12].Green=DEFAULT_COLOUR_12_GREEN ;
        Terrain_colours[12].Blue=DEFAULT_COLOUR_12_BLUE ;

        Terrain_colours[13].Red=DEFAULT_COLOUR_13_RED ;
        Terrain_colours[13].Green=DEFAULT_COLOUR_13_GREEN ;
        Terrain_colours[13].Blue=DEFAULT_COLOUR_13_BLUE ;

        Terrain_colours[14].Red=DEFAULT_COLOUR_14_RED ;
        Terrain_colours[14].Green=DEFAULT_COLOUR_14_GREEN ;
        Terrain_colours[14].Blue=DEFAULT_COLOUR_14_BLUE ;

        Terrain_colours[15].Red=DEFAULT_COLOUR_15_RED ;
        Terrain_colours[15].Green=DEFAULT_COLOUR_15_GREEN ;
        Terrain_colours[15].Blue=DEFAULT_COLOUR_15_BLUE ;

        Terrain_colours[16].Red=DEFAULT_COLOUR_16_RED ;
        Terrain_colours[16].Green=DEFAULT_COLOUR_16_GREEN ;
        Terrain_colours[16].Blue=DEFAULT_COLOUR_16_BLUE ;

        Terrain_colours[17].Red=DEFAULT_COLOUR_17_RED ;
        Terrain_colours[17].Green=DEFAULT_COLOUR_17_GREEN ;
        Terrain_colours[17].Blue=DEFAULT_COLOUR_17_BLUE ;

        Terrain_colours[18].Red=DEFAULT_COLOUR_18_RED ;
        Terrain_colours[18].Green=DEFAULT_COLOUR_18_GREEN ;
        Terrain_colours[18].Blue=DEFAULT_COLOUR_18_BLUE ;

        Terrain_colours[19].Red=DEFAULT_COLOUR_19_RED ;
        Terrain_colours[19].Green=DEFAULT_COLOUR_19_GREEN ;
        Terrain_colours[19].Blue=DEFAULT_COLOUR_19_BLUE ;

        Terrain_colours[20].Red=DEFAULT_COLOUR_20_RED ;
        Terrain_colours[20].Green=DEFAULT_COLOUR_20_GREEN ;
        Terrain_colours[20].Blue=DEFAULT_COLOUR_20_BLUE ;

        Terrain_colours[21].Red=DEFAULT_COLOUR_21_RED ;
        Terrain_colours[21].Green=DEFAULT_COLOUR_21_GREEN ;
        Terrain_colours[21].Blue=DEFAULT_COLOUR_21_BLUE ;

        Terrain_colours[22].Red=DEFAULT_COLOUR_22_RED ;
        Terrain_colours[22].Green=DEFAULT_COLOUR_22_GREEN ;
        Terrain_colours[22].Blue=DEFAULT_COLOUR_22_BLUE ;

        Terrain_colours[23].Red=DEFAULT_COLOUR_23_RED ;
        Terrain_colours[23].Green=DEFAULT_COLOUR_23_GREEN ;
        Terrain_colours[23].Blue=DEFAULT_COLOUR_23_BLUE ;

        Terrain_colours[24].Red=DEFAULT_COLOUR_24_RED ;
        Terrain_colours[24].Green=DEFAULT_COLOUR_24_GREEN ;
        Terrain_colours[24].Blue=DEFAULT_COLOUR_24_BLUE ;

/* set fog colour */
	Fog.Red=DEFAULT_FOG_COLOUR_RED ;
	Fog.Green=DEFAULT_FOG_COLOUR_GREEN ;
	Fog.Blue=DEFAULT_FOG_COLOUR_BLUE ;

/* set sky colour */
	Sky.Red=DEFAULT_SKY_COLOUR_RED ;
	Sky.Green=DEFAULT_SKY_COLOUR_GREEN ;
	Sky.Blue=DEFAULT_SKY_COLOUR_BLUE ;

/* set horizon colour */
	Horizon.Red=DEFAULT_HORIZON_COLOUR_RED ;
	Horizon.Green=DEFAULT_HORIZON_COLOUR_GREEN ;
	Horizon.Blue=DEFAULT_HORIZON_COLOUR_BLUE ;

/* set Ambient lighting */
	Ambient_light=DEFAULT_AMBIENT_LIGHT ;

/* set fog start and end distances */
        Fog_start=DEFAULT_FOG_START ;
        Fog_end=DEFAULT_FOG_END ;
  
 }

/*									*/
/* set the default display values 					*/
/*									*/

default_display_config()
 {

/* set ray step size */
	Ray_step=RAY_STEP ;

/* set window postions */
        User_view.X=WINDOW_X_POSITION ;
        User_view.Y=WINDOW_Y_POSITION ;

/* set window sizes */
        User_view.X_size=SCREEN_X_SIZE ;
        User_view.Y_size=SCREEN_Y_SIZE ;

/* set view angles */
        X_view_angle=(double)X_VIEW_ANGLE ;
        Y_view_angle=(double)Y_VIEW_ANGLE  ;

/* set number of workers */
        Number_of_workers=NUMBER_OF_WORKERS ;

 }
/*									*/
/* read the world values	 					*/
/*									*/

read_world_config(FILE *Info)
 {
  char Line[81] ;
  int  Counter ;

/* start to process the config file */
      while ((getline (Line,81,Info))!=0)
        {
/* remove comments */
         if ((Line[0] != '#'))
           {
/* convert to lower case */
            Counter=0 ;
            while( (Line[Counter]!='\n') && (Counter < 80))
              {
               if ((Line[Counter]>='A') && (Line[Counter]<='Z'))
/* do the conversion */
                 {
                  Line[Counter]=Line[Counter]-'A'+'a' ;
                 }
               Counter++ ;
              }
            Counter=0 ;
/* move pass spaces and tabs */
            Counter=read_spaces(Line) ;
  
            if (Line[Counter]!='\n')
              { 
/* deal with values */

/*                                                              */
/* read H                                                       */
/*                                                              */
               
               if
                 (strncmp(&Line[Counter],H_TOKEN,
                  strlen(H_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(H_TOKEN) ;
               
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                  
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                  
/* set the variable */
                     H=atof(&Line[Counter]) ;
                     printf ("INFO:\tH                        =%f\n",
                             H) ;
                    }
                  else
                    {
                     H=DEFAULT_H ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }

/*                                                              */
/* read lacunarity                                              */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],LACUNARITY_TOKEN,
                  strlen(LACUNARITY_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(LACUNARITY_TOKEN) ;

/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {  
                     Counter ++ ;
               
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                  
/* set the variable */
                     Lacunarity=atof(&Line[Counter]) ;
                     printf ("INFO:\tLacunarity               =%f\n",
                             Lacunarity) ;
                    }  
                  else
                    {
                     Lacunarity=DEFAULT_LACUNARITY ;    
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }
/*                                                              */
/* read Octaves                                                 */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],OCTAVES_TOKEN,
                  strlen(OCTAVES_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(OCTAVES_TOKEN) ;

/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {  
                     Counter ++ ;
               
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                  
/* set the variable */
                     Octaves=atof(&Line[Counter]) ;
                     printf ("INFO:\tOctaves                  =%f\n",
                             Octaves) ;
                    }  
                  else
                    {
                     Octaves=DEFAULT_OCTAVES ;    
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }

/*                                                              */
/* read Offset                                                  */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],OFFSET_TOKEN,
                  strlen(OFFSET_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(OFFSET_TOKEN) ;

/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {  
                     Counter ++ ;
               
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                  
/* set the variable */
                     Offset=atof(&Line[Counter]) ;
                     printf ("INFO:\tOffset                   =%f\n",
                             Offset) ;
                    }  
                  else
                    {
                     Offset=DEFAULT_OFFSET ;    
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }

/*                                                              */
/* read colour boundary 1                                       */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY01_TOKEN,
                  strlen(COLOUR_BOUNDARY01_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY01_TOKEN) ;

/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {  
                     Counter ++ ;
               
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                  
/* set the variable */
                     Colour_boundaries[0]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 1        =%f\n",
                             Colour_boundaries[0]) ;
                    }  
                  else
                    {
                     Colour_boundaries[0]=DEFAULT_COLOUR_BOUNDARIES_01 ;    
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }

/*                                                              */
/* read colour boundary 2                                       */
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY02_TOKEN,
                  strlen(COLOUR_BOUNDARY02_TOKEN))==0)
                 {   
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY02_TOKEN) ;

/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */    
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                  
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                  
/* set the variable */
                     Colour_boundaries[1]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 2        =%f\n",
                             Colour_boundaries[1]) ;
                    }
                  else
                    {
                     Colour_boundaries[1]=DEFAULT_COLOUR_BOUNDARIES_02 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }

/*                                                              */
/* read colour boundary 3                                       */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY03_TOKEN,
                  strlen(COLOUR_BOUNDARY03_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY03_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[2]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 3        =%f\n",
                             Colour_boundaries[2]) ;
                    }
                  else
                    {
                     Colour_boundaries[2]=DEFAULT_COLOUR_BOUNDARIES_03 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   
/*                                                              */
/* read colour boundary 4                                       */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY04_TOKEN,
                  strlen(COLOUR_BOUNDARY04_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY04_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[3]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 4        =%f\n",
                             Colour_boundaries[3]) ;
                    }
                  else
                    {
                     Colour_boundaries[3]=DEFAULT_COLOUR_BOUNDARIES_04 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 5                                       */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY05_TOKEN,
                  strlen(COLOUR_BOUNDARY05_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY05_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[4]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 5        =%f\n",
                             Colour_boundaries[4]) ;
                    }
                  else
                    {
                     Colour_boundaries[4]=DEFAULT_COLOUR_BOUNDARIES_05 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 6                                       */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY06_TOKEN,
                  strlen(COLOUR_BOUNDARY06_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY06_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[5]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 6        =%f\n",
                             Colour_boundaries[5]) ;
                    }
                  else
                    {
                     Colour_boundaries[5]=DEFAULT_COLOUR_BOUNDARIES_06 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 7                                       */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY07_TOKEN,
                  strlen(COLOUR_BOUNDARY07_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY07_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[6]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 7        =%f\n",
                             Colour_boundaries[6]) ;
                    }
                  else
                    {
                     Colour_boundaries[6]=DEFAULT_COLOUR_BOUNDARIES_07 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 8                                       */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY08_TOKEN,
                  strlen(COLOUR_BOUNDARY08_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY08_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[7]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 8        =%f\n",
                             Colour_boundaries[7]) ;
                    }
                  else
                    {
                     Colour_boundaries[7]=DEFAULT_COLOUR_BOUNDARIES_08 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 9                                       */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY09_TOKEN,
                  strlen(COLOUR_BOUNDARY09_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY09_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[8]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 9        =%f\n",
                             Colour_boundaries[8]) ;
                    }
                  else
                    {
                     Colour_boundaries[8]=DEFAULT_COLOUR_BOUNDARIES_09 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 10                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY10_TOKEN,
                  strlen(COLOUR_BOUNDARY10_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY10_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[9]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 10       =%f\n",
                             Colour_boundaries[9]) ;
                    }
                  else
                    {
                     Colour_boundaries[9]=DEFAULT_COLOUR_BOUNDARIES_10 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 11                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY11_TOKEN,
                  strlen(COLOUR_BOUNDARY11_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY11_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[10]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 11       =%f\n",
                             Colour_boundaries[10]) ;
                    }
                  else
                    {
                     Colour_boundaries[10]=DEFAULT_COLOUR_BOUNDARIES_11 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 12                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY12_TOKEN,
                  strlen(COLOUR_BOUNDARY12_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY12_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[11]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 12       =%f\n",
                             Colour_boundaries[11]) ;
                    }
                  else
                    {
                     Colour_boundaries[11]=DEFAULT_COLOUR_BOUNDARIES_12 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   
/*                                                              */
/* read colour boundary 13                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY13_TOKEN,
                  strlen(COLOUR_BOUNDARY13_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY13_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[12]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 13       =%f\n",
                             Colour_boundaries[12]) ;
                    }
                  else
                    {
                     Colour_boundaries[12]=DEFAULT_COLOUR_BOUNDARIES_13 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 14                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY14_TOKEN,
                  strlen(COLOUR_BOUNDARY14_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY14_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[13]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 14       =%f\n",
                             Colour_boundaries[13]) ;
                    }
                  else
                    {
                     Colour_boundaries[13]=DEFAULT_COLOUR_BOUNDARIES_14 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 15                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY15_TOKEN,
                  strlen(COLOUR_BOUNDARY15_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY15_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[14]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 15       =%f\n",
                             Colour_boundaries[14]) ;
                    }
                  else
                    {
                     Colour_boundaries[14]=DEFAULT_COLOUR_BOUNDARIES_15 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 16                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY16_TOKEN,
                  strlen(COLOUR_BOUNDARY16_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY16_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[15]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 16       =%f\n",
                             Colour_boundaries[15]) ;
                    }
                  else
                    {
                     Colour_boundaries[15]=DEFAULT_COLOUR_BOUNDARIES_16 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 17                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY17_TOKEN,
                  strlen(COLOUR_BOUNDARY17_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY17_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[16]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 17       =%f\n",
                             Colour_boundaries[16]) ;
                    }
                  else
                    {
                     Colour_boundaries[16]=DEFAULT_COLOUR_BOUNDARIES_17 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 18                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY18_TOKEN,
                  strlen(COLOUR_BOUNDARY18_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY18_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[17]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 18       =%f\n",
                             Colour_boundaries[17]) ;
                    }
                  else
                    {
                     Colour_boundaries[17]=DEFAULT_COLOUR_BOUNDARIES_18 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 19                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY19_TOKEN,
                  strlen(COLOUR_BOUNDARY19_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY19_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[18]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 19       =%f\n",
                             Colour_boundaries[18]) ;
                    }
                  else
                    {
                     Colour_boundaries[18]=DEFAULT_COLOUR_BOUNDARIES_19 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 20                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY20_TOKEN,
                  strlen(COLOUR_BOUNDARY20_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY20_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[19]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 20       =%f\n",
                             Colour_boundaries[19]) ;
                    }
                  else
                    {
                     Colour_boundaries[19]=DEFAULT_COLOUR_BOUNDARIES_20 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 21                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY21_TOKEN,
                  strlen(COLOUR_BOUNDARY21_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY21_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[20]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 21       =%f\n",
                             Colour_boundaries[20]) ;
                    }
                  else
                    {
                     Colour_boundaries[20]=DEFAULT_COLOUR_BOUNDARIES_21 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 22                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY22_TOKEN,
                  strlen(COLOUR_BOUNDARY22_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY22_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[21]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 22       =%f\n",
                             Colour_boundaries[21]) ;
                    }
                  else
                    {
                     Colour_boundaries[21]=DEFAULT_COLOUR_BOUNDARIES_22 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 23                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY23_TOKEN,
                  strlen(COLOUR_BOUNDARY23_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY23_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[22]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 23       =%f\n",
                             Colour_boundaries[22]) ;
                    }
                  else
                    {
                     Colour_boundaries[22]=DEFAULT_COLOUR_BOUNDARIES_23 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 24                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY24_TOKEN,
                  strlen(COLOUR_BOUNDARY24_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY24_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[23]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 24       =%f\n",
                             Colour_boundaries[23]) ;
                    }
                  else
                    {
                     Colour_boundaries[23]=DEFAULT_COLOUR_BOUNDARIES_24 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour boundary 25                                      */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR_BOUNDARY25_TOKEN,
                  strlen(COLOUR_BOUNDARY25_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR_BOUNDARY25_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Colour_boundaries[24]=atof(&Line[Counter]) ;
                     printf ("INFO:\tColour boundary 25       =%f\n",
                             Colour_boundaries[24]) ;
                    }
                  else
                    {
                     Colour_boundaries[24]=DEFAULT_COLOUR_BOUNDARIES_25 ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read Ambient lighting                                        */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],AMBIENT_LIGHTING_TOKEN,
                  strlen(AMBIENT_LIGHTING_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(AMBIENT_LIGHTING_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Ambient_light=atof(&Line[Counter]) ;
                     printf ("INFO:\tAmbient lighting         =%f\n",
                             Ambient_light) ;
                    }
                  else
                    {
                     Ambient_light=DEFAULT_AMBIENT_LIGHT ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read fog Start	                                        */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],FOG_START_TOKEN,
                  strlen(FOG_START_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(FOG_START_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Fog_start=atof(&Line[Counter]) ;
                     printf ("INFO:\tFog start value          =%f\n",
                             Fog_start) ;
                    }
                  else
                    {
                     Fog_start=DEFAULT_FOG_START ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read fog end		                                        */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],FOG_END_TOKEN,
                  strlen(FOG_END_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(FOG_END_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Fog_end=atof(&Line[Counter]) ;
                     printf ("INFO:\tFog end value            =%f\n",
                             Fog_end) ;
                    }
                  else
                    {
                     Fog_end=DEFAULT_FOG_END ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   
/*                                                              */
/* read colour 1	                                        */ 
/*                                                              */

               if
                 (strncmp(&Line[Counter],COLOUR01_TOKEN,
                  strlen(COLOUR01_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR01_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;   
                     
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Terrain_colours[0].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
		     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[0].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
		     Terrain_colours[0].Blue=atof(&Line[Counter]) ;

                     printf ("INFO:\tColour 1                 =%f,%f,%f\n",
			      Terrain_colours[0].Red,
			      Terrain_colours[0].Green,
			      Terrain_colours[0].Blue) ;
                    }
                  else
                    {
                     Terrain_colours[0].Red=DEFAULT_COLOUR_00_RED ;
                     Terrain_colours[0].Green=DEFAULT_COLOUR_00_GREEN ;
                     Terrain_colours[0].Blue=DEFAULT_COLOUR_00_BLUE ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 2                                                */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR02_TOKEN,
                  strlen(COLOUR02_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR02_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[1].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[1].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[1].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 2                 =%f,%f,%f\n",
                              Terrain_colours[1].Red,
                              Terrain_colours[1].Green, 
                              Terrain_colours[1].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[1].Red=DEFAULT_COLOUR_01_RED ;
                     Terrain_colours[1].Green=DEFAULT_COLOUR_01_GREEN ;
                     Terrain_colours[1].Blue=DEFAULT_COLOUR_01_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 3                                                */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR03_TOKEN,
                  strlen(COLOUR03_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR03_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[2].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[2].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[2].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 3                 =%f,%f,%f\n",
                              Terrain_colours[2].Red,
                              Terrain_colours[2].Green, 
                              Terrain_colours[2].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[2].Red=DEFAULT_COLOUR_02_RED ;
                     Terrain_colours[2].Green=DEFAULT_COLOUR_02_GREEN ;
                     Terrain_colours[2].Blue=DEFAULT_COLOUR_02_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 4                                                */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR04_TOKEN,
                  strlen(COLOUR04_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR04_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[3].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[3].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[3].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 4                 =%f,%f,%f\n",
                              Terrain_colours[3].Red,
                              Terrain_colours[3].Green, 
                              Terrain_colours[3].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[3].Red=DEFAULT_COLOUR_03_RED ;
                     Terrain_colours[3].Green=DEFAULT_COLOUR_03_GREEN ;
                     Terrain_colours[3].Blue=DEFAULT_COLOUR_03_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 5                                                */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR05_TOKEN,
                  strlen(COLOUR05_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR05_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[4].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[4].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[4].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 5                 =%f,%f,%f\n",
                              Terrain_colours[4].Red,
                              Terrain_colours[4].Green, 
                              Terrain_colours[4].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[4].Red=DEFAULT_COLOUR_04_RED ;
                     Terrain_colours[4].Green=DEFAULT_COLOUR_04_GREEN ;
                     Terrain_colours[4].Blue=DEFAULT_COLOUR_04_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 6                                                */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR06_TOKEN,
                  strlen(COLOUR06_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR06_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[5].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[5].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[5].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 6                 =%f,%f,%f\n",
                              Terrain_colours[5].Red,
                              Terrain_colours[5].Green, 
                              Terrain_colours[5].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[5].Red=DEFAULT_COLOUR_05_RED ;
                     Terrain_colours[5].Green=DEFAULT_COLOUR_05_GREEN ;
                     Terrain_colours[5].Blue=DEFAULT_COLOUR_05_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 7                                                */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR07_TOKEN,
                  strlen(COLOUR07_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR07_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[6].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[6].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[6].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 7                 =%f,%f,%f\n",
                              Terrain_colours[6].Red,
                              Terrain_colours[6].Green, 
                              Terrain_colours[6].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[6].Red=DEFAULT_COLOUR_06_RED ;
                     Terrain_colours[6].Green=DEFAULT_COLOUR_06_GREEN ;
                     Terrain_colours[6].Blue=DEFAULT_COLOUR_06_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 8                                                */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR08_TOKEN,
                  strlen(COLOUR08_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR08_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[7].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[7].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[7].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 8                 =%f,%f,%f\n",
                              Terrain_colours[7].Red,
                              Terrain_colours[7].Green, 
                              Terrain_colours[7].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[7].Red=DEFAULT_COLOUR_07_RED ;
                     Terrain_colours[7].Green=DEFAULT_COLOUR_07_GREEN ;
                     Terrain_colours[7].Blue=DEFAULT_COLOUR_07_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 9                                                */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR09_TOKEN,
                  strlen(COLOUR09_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR09_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[8].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[8].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[8].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 9                 =%f,%f,%f\n",
                              Terrain_colours[8].Red,
                              Terrain_colours[8].Green, 
                              Terrain_colours[8].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[8].Red=DEFAULT_COLOUR_08_RED ;
                     Terrain_colours[8].Green=DEFAULT_COLOUR_08_GREEN ;
                     Terrain_colours[8].Blue=DEFAULT_COLOUR_08_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 10                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR10_TOKEN,
                  strlen(COLOUR10_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR10_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[9].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[9].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[9].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 10                =%f,%f,%f\n",
                              Terrain_colours[9].Red,
                              Terrain_colours[9].Green, 
                              Terrain_colours[9].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[9].Red=DEFAULT_COLOUR_09_RED ;
                     Terrain_colours[9].Green=DEFAULT_COLOUR_09_GREEN ;
                     Terrain_colours[9].Blue=DEFAULT_COLOUR_09_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 11                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR11_TOKEN,
                  strlen(COLOUR11_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR11_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[10].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[10].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[10].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 11                =%f,%f,%f\n",
                              Terrain_colours[10].Red,
                              Terrain_colours[10].Green, 
                              Terrain_colours[10].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[10].Red=DEFAULT_COLOUR_10_RED ;
                     Terrain_colours[10].Green=DEFAULT_COLOUR_10_GREEN ;
                     Terrain_colours[10].Blue=DEFAULT_COLOUR_10_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 12                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR12_TOKEN,
                  strlen(COLOUR12_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR12_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[11].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[11].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[11].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 12                =%f,%f,%f\n",
                              Terrain_colours[11].Red,
                              Terrain_colours[11].Green, 
                              Terrain_colours[11].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[11].Red=DEFAULT_COLOUR_11_RED ;
                     Terrain_colours[11].Green=DEFAULT_COLOUR_11_GREEN ;
                     Terrain_colours[11].Blue=DEFAULT_COLOUR_11_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 13                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR13_TOKEN,
                  strlen(COLOUR13_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR13_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[12].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[12].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[12].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 13                =%f,%f,%f\n",
                              Terrain_colours[12].Red,
                              Terrain_colours[12].Green, 
                              Terrain_colours[12].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[12].Red=DEFAULT_COLOUR_12_RED ;
                     Terrain_colours[12].Green=DEFAULT_COLOUR_12_GREEN ;
                     Terrain_colours[12].Blue=DEFAULT_COLOUR_12_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 14                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR14_TOKEN,
                  strlen(COLOUR14_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR14_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[13].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[13].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[13].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 14                =%f,%f,%f\n",
                              Terrain_colours[13].Red,
                              Terrain_colours[13].Green, 
                              Terrain_colours[13].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[13].Red=DEFAULT_COLOUR_13_RED ;
                     Terrain_colours[13].Green=DEFAULT_COLOUR_13_GREEN ;
                     Terrain_colours[13].Blue=DEFAULT_COLOUR_13_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 15                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR15_TOKEN,
                  strlen(COLOUR15_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR15_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[14].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[14].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[14].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 15                =%f,%f,%f\n",
                              Terrain_colours[14].Red,
                              Terrain_colours[14].Green, 
                              Terrain_colours[14].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[14].Red=DEFAULT_COLOUR_14_RED ;
                     Terrain_colours[14].Green=DEFAULT_COLOUR_14_GREEN ;
                     Terrain_colours[14].Blue=DEFAULT_COLOUR_14_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 16                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR16_TOKEN,
                  strlen(COLOUR16_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR16_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[15].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[15].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[15].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 16                =%f,%f,%f\n",
                              Terrain_colours[15].Red,
                              Terrain_colours[15].Green, 
                              Terrain_colours[15].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[15].Red=DEFAULT_COLOUR_15_RED ;
                     Terrain_colours[15].Green=DEFAULT_COLOUR_15_GREEN ;
                     Terrain_colours[15].Blue=DEFAULT_COLOUR_15_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 17                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR17_TOKEN,
                  strlen(COLOUR17_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR17_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[16].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[16].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[16].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 17                =%f,%f,%f\n",
                              Terrain_colours[16].Red,
                              Terrain_colours[16].Green, 
                              Terrain_colours[16].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[16].Red=DEFAULT_COLOUR_16_RED ;
                     Terrain_colours[16].Green=DEFAULT_COLOUR_16_GREEN ;
                     Terrain_colours[16].Blue=DEFAULT_COLOUR_16_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 18                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR18_TOKEN,
                  strlen(COLOUR18_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR18_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[17].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[17].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[17].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 18                =%f,%f,%f\n",
                              Terrain_colours[17].Red,
                              Terrain_colours[17].Green, 
                              Terrain_colours[17].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[17].Red=DEFAULT_COLOUR_17_RED ;
                     Terrain_colours[17].Green=DEFAULT_COLOUR_17_GREEN ;
                     Terrain_colours[17].Blue=DEFAULT_COLOUR_17_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 19                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR19_TOKEN,
                  strlen(COLOUR19_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR19_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[18].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[18].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[18].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 19                =%f,%f,%f\n",
                              Terrain_colours[18].Red,
                              Terrain_colours[18].Green, 
                              Terrain_colours[18].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[18].Red=DEFAULT_COLOUR_18_RED ;
                     Terrain_colours[18].Green=DEFAULT_COLOUR_18_GREEN ;
                     Terrain_colours[18].Blue=DEFAULT_COLOUR_18_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 20                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR20_TOKEN,
                  strlen(COLOUR20_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR20_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[19].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[19].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[19].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 20                =%f,%f,%f\n",
                              Terrain_colours[19].Red,
                              Terrain_colours[19].Green, 
                              Terrain_colours[19].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[19].Red=DEFAULT_COLOUR_19_RED ;
                     Terrain_colours[19].Green=DEFAULT_COLOUR_19_GREEN ;
                     Terrain_colours[19].Blue=DEFAULT_COLOUR_19_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 21                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR21_TOKEN,
                  strlen(COLOUR21_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR21_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[20].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[20].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[20].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 21                =%f,%f,%f\n",
                              Terrain_colours[20].Red,
                              Terrain_colours[20].Green, 
                              Terrain_colours[20].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[20].Red=DEFAULT_COLOUR_20_RED ;
                     Terrain_colours[20].Green=DEFAULT_COLOUR_20_GREEN ;
                     Terrain_colours[20].Blue=DEFAULT_COLOUR_20_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 22                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR22_TOKEN,
                  strlen(COLOUR22_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR22_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[21].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[21].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[21].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 22                =%f,%f,%f\n",
                              Terrain_colours[21].Red,
                              Terrain_colours[21].Green, 
                              Terrain_colours[21].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[21].Red=DEFAULT_COLOUR_21_RED ;
                     Terrain_colours[21].Green=DEFAULT_COLOUR_21_GREEN ;
                     Terrain_colours[21].Blue=DEFAULT_COLOUR_21_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 23                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR23_TOKEN,
                  strlen(COLOUR23_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR23_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[22].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[22].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[22].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 23                =%f,%f,%f\n",
                              Terrain_colours[22].Red,
                              Terrain_colours[22].Green, 
                              Terrain_colours[22].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[22].Red=DEFAULT_COLOUR_22_RED ;
                     Terrain_colours[22].Green=DEFAULT_COLOUR_22_GREEN ;
                     Terrain_colours[22].Blue=DEFAULT_COLOUR_22_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 24                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR24_TOKEN,
                  strlen(COLOUR24_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR24_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[23].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[23].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[23].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 24                =%f,%f,%f\n",
                              Terrain_colours[23].Red,
                              Terrain_colours[23].Green, 
                              Terrain_colours[23].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[23].Red=DEFAULT_COLOUR_23_RED ;
                     Terrain_colours[23].Green=DEFAULT_COLOUR_23_GREEN ;
                     Terrain_colours[23].Blue=DEFAULT_COLOUR_23_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read colour 25                                               */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],COLOUR25_TOKEN,
                  strlen(COLOUR25_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(COLOUR25_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Terrain_colours[24].Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[24].Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Terrain_colours[24].Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tColour 25                =%f,%f,%f\n",
                              Terrain_colours[24].Red,
                              Terrain_colours[24].Green, 
                              Terrain_colours[24].Blue) ;
                    }
                  else
                    { 
                     Terrain_colours[24].Red=DEFAULT_COLOUR_24_RED ;
                     Terrain_colours[24].Green=DEFAULT_COLOUR_24_GREEN ;
                     Terrain_colours[24].Blue=DEFAULT_COLOUR_24_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read sky colour                                              */
/*                                                              */
                     
               if
                 (strncmp(&Line[Counter],SKY_TOKEN,
                  strlen(SKY_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(SKY_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* read = sign */ 
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                     
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Sky.Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Sky.Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;  
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Sky.Blue=atof(&Line[Counter]) ;
                     
                     printf ("INFO:\tSky colour               =%f,%f,%f\n",
                              Sky.Red,
                              Sky.Green, 
                              Sky.Blue) ;
                    }
                  else
                    { 
                     Sky.Red=DEFAULT_SKY_COLOUR_RED ;
                     Sky.Green=DEFAULT_SKY_COLOUR_GREEN ;
                     Sky.Blue=DEFAULT_SKY_COLOUR_BLUE ;  
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read fog colour                                              */   
/*                                                              */ 
                     
               if
                 (strncmp(&Line[Counter],FOG_TOKEN,
                  strlen(FOG_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(FOG_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                              
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                              
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Fog.Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Fog.Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Fog.Blue=atof(&Line[Counter]) ;

                     printf ("INFO:\tFog colour               =%f,%f,%f\n",
                              Fog.Red,
                              Fog.Green,
                              Fog.Blue) ;
                    }
                  else
                    {
                     Fog.Red=DEFAULT_FOG_COLOUR_RED ;
                     Fog.Green=DEFAULT_FOG_COLOUR_GREEN ;
                     Fog.Blue=DEFAULT_FOG_COLOUR_BLUE ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/*                                                              */
/* read horizon colour                                          */   
/*                                                              */ 
                     
               if
                 (strncmp(&Line[Counter],HORIZON_TOKEN,
                  strlen(HORIZON_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(HORIZON_TOKEN) ;
                     
/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;
                              
/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;
                              
/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     
/* set the variable */
                     Horizon.Red=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Horizon.Green=atof(&Line[Counter]) ;
                     Counter=Counter+read_spaces(&Line[Counter]) ;
                     Counter=Counter+read_to_comma(&Line[Counter]) ;
                     Counter ++ ;
                     Horizon.Blue=atof(&Line[Counter]) ;

                     printf ("INFO:\tHorizon colour           =%f,%f,%f\n",
                              Horizon.Red,
                              Horizon.Green,
                              Horizon.Blue) ;
                    }
                  else
                    {
                     Horizon.Red=DEFAULT_HORIZON_COLOUR_RED ;
                     Horizon.Green=DEFAULT_HORIZON_COLOUR_GREEN ;
                     Horizon.Blue=DEFAULT_HORIZON_COLOUR_BLUE ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                 }   

/* end of newline if */
               }
                     
/* end of comment if */
          }
                     
/* end of while */
        }

 }

/*									*/
/* read the display values	 					*/
/*									*/

read_display_config(FILE *Info)
 {
  char Line[81] ;
  int  Counter ;

/* start to process the config file */
      while ((getline (Line,81,Info))!=0)
        {
/* remove comments */
         if ((Line[0] != '#'))   
           {
/* convert to lower case */
            Counter=0 ;
            while( (Line[Counter]!='\n') && (Counter < 80))
              {
               if ((Line[Counter]>='A') && (Line[Counter]<='Z'))
/* do the conversion */
                 {
                  Line[Counter]=Line[Counter]-'A'+'a' ;
                 }
               Counter++ ;
              }
            Counter=0 ;
/* move pass spaces and tabs */
            Counter=read_spaces(Line) ;

            if (Line[Counter]!='\n')
              {
/* deal with values */

/*								*/
/* read the X_view_angle 					*/
/*								*/
               if 
		 (strncmp(&Line[Counter],X_VIEW_ANGLE_TOKEN,
                  strlen(X_VIEW_ANGLE_TOKEN))==0)
                 {
/* step past the variable name */
		  Counter=Counter+strlen(X_VIEW_ANGLE_TOKEN) ;

/* read leading spaces */
		  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {
		     Counter ++ ;

/* read spaces after = sign */
  		     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
		     X_view_angle=atof(&Line[Counter]) ;
		     printf ("INFO:\tView angle for the X axis=%f\n",
			      X_view_angle) ;
                    }
                  else
                    {
                     X_view_angle=X_VIEW_ANGLE ;
                     printf ("ERROR:\tline malformed. Default value used\n") ; 
                    }
                  }

/*								*/
/* read the Y_view_angle 					*/
/*								*/

               if 
		 (strncmp(&Line[Counter],Y_VIEW_ANGLE_TOKEN,
                  strlen(Y_VIEW_ANGLE_TOKEN))==0)
                 {
/* step past the variable name */
		  Counter=Counter+strlen(Y_VIEW_ANGLE_TOKEN) ;

/* read leading spaces */
		  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {
		     Counter ++ ;

/* read spaces after = sign */
  		     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
		     Y_view_angle=atof(&Line[Counter]) ;
		     printf ("INFO:\tView angle for the Y axis=%f\n",
			      Y_view_angle) ;
                    }
                  else
                    {
                     Y_view_angle=Y_VIEW_ANGLE ;
                     printf ("ERROR:\tline malformed. Default value used\n") ; 
                    }
                  }

/*								*/
/* read the Ray_step 						*/
/*								*/
               if 
		 (strncmp(&Line[Counter],RAY_STEP_TOKEN,
                  strlen(RAY_STEP_TOKEN))==0)
                 {
/* step past the variable name */
		  Counter=Counter+strlen(RAY_STEP_TOKEN) ;

/* read leading spaces */
		  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {
		     Counter ++ ;

/* read spaces after = sign */
  		     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
		     Ray_step=atof(&Line[Counter]) ;
		     printf ("INFO:\tRay step size            =%f\n",Ray_step) ;
                    }
                  else
                    {
                     Ray_step=RAY_STEP ;
                     printf ("ERROR:\tline malformed. Default value used\n") ; 
                    }
                  }

/*								*/
/* read the X_screen_size 					*/
/*								*/
               if 
		 (strncmp(&Line[Counter],X_SCREEN_SIZE_TOKEN,
                  strlen(X_SCREEN_SIZE_TOKEN))==0)
                 {
/* step past the variable name */
		  Counter=Counter+strlen(X_SCREEN_SIZE_TOKEN) ;

/* read leading spaces */
		  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {
		     Counter ++ ;

/* read spaces after = sign */
  		     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
		     User_view.X_size=atoi(&Line[Counter]) ;
		     printf ("INFO:\tWindow X size            =%i\n",
                              User_view.X_size) ;
                    }
                  else
                    {
                     User_view.X_size=SCREEN_X_SIZE ;
                     printf ("ERROR:\tline malformed. Default value used\n") ; 
                    }
                  }

/*								*/
/* read the Y_screen_size				        */
/*								*/
               if 
		 (strncmp(&Line[Counter],Y_SCREEN_SIZE_TOKEN,
                  strlen(Y_SCREEN_SIZE_TOKEN))==0)
                 {
/* step past the variable name */
		  Counter=Counter+strlen(Y_SCREEN_SIZE_TOKEN) ;

/* read leading spaces */
		  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {
		     Counter ++ ;

/* read spaces after = sign */
  		     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
		     User_view.Y_size=atoi(&Line[Counter]) ;
		     printf ("INFO:\tWindow Y size            =%i\n",
                             User_view.Y_size) ;
                    }
                  else
                    {
                     User_view.Y_size=SCREEN_Y_SIZE ;
                     printf ("ERROR:\tline malformed. Default value used\n") ; 
                    }
                  }

/*								*/
/* read the Window X position 					*/
/*								*/
               if 
		 (strncmp(&Line[Counter],X_POSITION_TOKEN,
                  strlen(X_POSITION_TOKEN))==0)
                 {
/* step past the variable name */
		  Counter=Counter+strlen(X_POSITION_TOKEN) ;

/* read leading spaces */
		  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {
		     Counter ++ ;

/* read spaces after = sign */
  		     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
		     User_view.X=atoi(&Line[Counter]) ;
		     printf ("INFO:\tWindow X position        =%i\n",
                              User_view.X) ;
                    }
                  else
                    {
                     User_view.X=WINDOW_X_POSITION ;
                     printf ("ERROR:\tline malformed. Default value used\n") ; 
                    }
                  }
/*								*/
/* read the Y window position 					*/
/*								*/
               if 
		 (strncmp(&Line[Counter],Y_POSITION_TOKEN,
                  strlen(Y_POSITION_TOKEN))==0)
                 {
/* step past the variable name */
		  Counter=Counter+strlen(Y_POSITION_TOKEN) ;

/* read leading spaces */
		  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {
		     Counter ++ ;

/* read spaces after = sign */
  		     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
		     User_view.Y=atoi(&Line[Counter]) ;
		     printf ("INFO:\tWindow Y position        =%i\n",
                              User_view.Y) ;
                    }
                  else
                    {
                     User_view.Y=WINDOW_Y_POSITION ;
                     printf ("ERROR:\tline malformed. Default value used\n") ; 
                    }
                  }

/*                                                              */
/* read the Number of workers                                   */
/*                                                              */
               if
                 (strncmp(&Line[Counter],WORKERS_TOKEN,
                  strlen(WORKERS_TOKEN))==0)
                 {
/* step past the variable name */
                  Counter=Counter+strlen(WORKERS_TOKEN) ;

/* read leading spaces */
                  Counter=Counter+read_spaces(&Line[Counter]) ;

/* read = sign */
                  if (Line[Counter]=='=')
                    {
                     Counter ++ ;

/* read spaces after = sign */
                     Counter=Counter+read_spaces(&Line[Counter]) ;

/* set the variable */
                     Number_of_workers=atoi(&Line[Counter])  ;
                     printf ("INFO:\tNumber of Workers        =%i\n",
                              Number_of_workers) ;
                    }
                  else
                    {
                     Number_of_workers=NUMBER_OF_WORKERS ;
                     printf ("ERROR:\tline malformed. Default value used\n") ;
                    }
                  }

  
/* end of newline if */
               }

/* end of comment if */
          }

/* end of while */
        }
 }
/* end of read display config */

/*								*/
/* read config and command line arguments			*/
/*								*/

read_config (int argc, char** argv)
 {
  FILE *Info ;				/* file pointer		 */
  char *Display_file_name ;		/* file name for display */
  char *World_file_name ;		/* file name for world	 */
  int  Arg_counter ;			/* counter for the number*/
					/* of Arguments          */
  int  Options[NUMBER_OF_OPTIONS] ;     /* check arrays for	 */
					/* command line options  */
  int  Valid_counter ;			/* Counter for options   */


/* read the command line arguments */
   if (argc < 3 )
     {
/* set default config files */
  Display_file_name=DEFAULT_DISPLAY_FILE ;
  World_file_name=DEFAULT_WORLD_FILE ;

     }

/* process the arguments */
   else
     {

/* move to the first argument */
      argv++ ;
      Arg_counter=1 ;

/* process the files */
      while (Arg_counter<argc)
        {

/* process display file */
         if ((strcmp(*argv,DISPLAY_TOKEN))==0)
           {
            Display_file_name=*(++argv) ;
            Arg_counter=Arg_counter+1 ;
            Options[0]=1 ;
           }

/* process world file */
         if ((strcmp(*(argv),WORLD_TOKEN))==0)
           {
            World_file_name=*(++argv) ;
            Arg_counter=Arg_counter+1 ;
            Options[1]=1 ;
           }
/* increase the place */
         argv++ ;
         Arg_counter=Arg_counter+1 ;
        }
     }

/* check that all options are valid */
   for (Valid_counter=0;Valid_counter<NUMBER_OF_OPTIONS;Valid_counter++)
     {
      if (Options[Valid_counter]!=1)
        {
         switch (Valid_counter)
           {
            case 0:
              Display_file_name=DEFAULT_DISPLAY_FILE ;
              break ;
            case 1:
              World_file_name=DEFAULT_WORLD_FILE ;
              break ;
 
           }
        }
     }



/* open world config file */
   if ((Info=fopen(World_file_name,"r"))==NULL)
     {
/* file open failed */
      printf ("ERROR:could not open world config file:\n") ;
      printf ("Using default values.\n") ;
      default_world_config() ;
     } 
   else
     {
      printf ("INFO:Opened world config file\n") ;

/* read the file */
      read_world_config(Info) ;

/* close the file */
      fclose(Info) ;
      printf ("INFO:Closed world config file\n") ;

     }

/* open display config file */
   if ((Info=fopen(Display_file_name,"r"))==NULL)
     {
/* file open failed */
      printf ("ERROR:could not open display config file:\n") ;
      printf ("Using default values.\n") ;
      default_display_config() ;
     }
   else
     {
      printf ("INFO:Opened display config file\n") ;

/* read the file */
      read_display_config(Info) ;

/* close the file */
      fclose(Info) ;
      printf ("INFO:Closed display config file\n") ;
     }
    
/* 						*/

/* set view angles to radians */
        X_view_angle=(X_view_angle/360.0)*2.0*M_PI ;
        Y_view_angle=(Y_view_angle/360.0)*2.0*M_PI ;

/* set the ray angles */
        X_ray_angle=X_view_angle/User_view.X_size ;
        Y_ray_angle=Y_view_angle/User_view.Y_size ;

 }
