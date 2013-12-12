/*									*/
/* world tokens								*/
/*									*/
#define H_TOKEN	"h_value"
#define LACUNARITY_TOKEN "lacunarity"
#define OCTAVES_TOKEN "octaves"
#define OFFSET_TOKEN "offset"
#define COLOUR_BOUNDARY01_TOKEN "colour_boundary01"
#define COLOUR_BOUNDARY02_TOKEN "colour_boundary02"
#define COLOUR_BOUNDARY03_TOKEN "colour_boundary03"
#define COLOUR_BOUNDARY04_TOKEN "colour_boundary04"
#define COLOUR_BOUNDARY05_TOKEN "colour_boundary05"
#define COLOUR_BOUNDARY06_TOKEN "colour_boundary06"
#define COLOUR_BOUNDARY07_TOKEN "colour_boundary07"
#define COLOUR_BOUNDARY08_TOKEN "colour_boundary08"
#define COLOUR_BOUNDARY09_TOKEN "colour_boundary09"
#define COLOUR_BOUNDARY10_TOKEN "colour_boundary10"
#define COLOUR_BOUNDARY11_TOKEN "colour_boundary11"
#define COLOUR_BOUNDARY12_TOKEN "colour_boundary12"
#define COLOUR_BOUNDARY13_TOKEN "colour_boundary13"
#define COLOUR_BOUNDARY14_TOKEN "colour_boundary14"
#define COLOUR_BOUNDARY15_TOKEN "colour_boundary15"
#define COLOUR_BOUNDARY16_TOKEN "colour_boundary16"
#define COLOUR_BOUNDARY17_TOKEN "colour_boundary17"
#define COLOUR_BOUNDARY18_TOKEN "colour_boundary18"
#define COLOUR_BOUNDARY19_TOKEN "colour_boundary19"
#define COLOUR_BOUNDARY20_TOKEN "colour_boundary20"
#define COLOUR_BOUNDARY21_TOKEN "colour_boundary21"
#define COLOUR_BOUNDARY22_TOKEN "colour_boundary22"
#define COLOUR_BOUNDARY23_TOKEN "colour_boundary23"
#define COLOUR_BOUNDARY24_TOKEN "colour_boundary24"
#define COLOUR_BOUNDARY25_TOKEN "colour_boundary25"

#define COLOUR01_TOKEN "colour01"
#define COLOUR02_TOKEN "colour02"
#define COLOUR03_TOKEN "colour03"
#define COLOUR04_TOKEN "colour04"
#define COLOUR05_TOKEN "colour05"
#define COLOUR06_TOKEN "colour06"
#define COLOUR07_TOKEN "colour07"
#define COLOUR08_TOKEN "colour08"
#define COLOUR09_TOKEN "colour09"
#define COLOUR10_TOKEN "colour10"
#define COLOUR11_TOKEN "colour11"
#define COLOUR12_TOKEN "colour12"
#define COLOUR13_TOKEN "colour13"
#define COLOUR14_TOKEN "colour14"
#define COLOUR15_TOKEN "colour15"
#define COLOUR16_TOKEN "colour16"
#define COLOUR17_TOKEN "colour17"
#define COLOUR18_TOKEN "colour18"
#define COLOUR19_TOKEN "colour19"
#define COLOUR20_TOKEN "colour20"
#define COLOUR21_TOKEN "colour21"
#define COLOUR22_TOKEN "colour22"
#define COLOUR23_TOKEN "colour23"
#define COLOUR24_TOKEN "colour24"
#define COLOUR25_TOKEN "colour25"

#define FOG_TOKEN "fog"

#define SKY_TOKEN "sky"

#define HORIZON_TOKEN "horizon"

#define AMBIENT_LIGHTING_TOKEN "ambient_lighting"

#define FOG_START_TOKEN "fog_start"

#define FOG_END_TOKEN "fog_end"


/*									*/
/* default values for the world		 				*/
/*									*/

#define  DEFAULT_H          0.5		/* H 				*/
#define  DEFAULT_LACUNARITY 2.0         /* Lacunarity 			*/
#define  DEFAULT_OCTAVES    7.0         /* Octaves 			*/
#define  DEFAULT_OFFSET     0.0         /* Offset from sea level 	*/

/* colour boundaries from 1 to 0 */
					/* top */
#define  DEFAULT_COLOUR_BOUNDARIES_01   0.65 
#define  DEFAULT_COLOUR_BOUNDARIES_02   0.60 
#define  DEFAULT_COLOUR_BOUNDARIES_03   0.52 
#define  DEFAULT_COLOUR_BOUNDARIES_04   0.51 
#define  DEFAULT_COLOUR_BOUNDARIES_05   0.50
#define  DEFAULT_COLOUR_BOUNDARIES_06   0.45 
#define  DEFAULT_COLOUR_BOUNDARIES_07   0.44 
#define  DEFAULT_COLOUR_BOUNDARIES_08   0.43 
#define  DEFAULT_COLOUR_BOUNDARIES_09   0.42 
#define  DEFAULT_COLOUR_BOUNDARIES_10   0.41 
#define  DEFAULT_COLOUR_BOUNDARIES_11   0.40 
#define  DEFAULT_COLOUR_BOUNDARIES_12   0.39
#define  DEFAULT_COLOUR_BOUNDARIES_13   0.38
#define  DEFAULT_COLOUR_BOUNDARIES_14   0.37
#define  DEFAULT_COLOUR_BOUNDARIES_15   0.36
#define  DEFAULT_COLOUR_BOUNDARIES_16   0.34
#define  DEFAULT_COLOUR_BOUNDARIES_17   0.32
#define  DEFAULT_COLOUR_BOUNDARIES_18   0.30
#define  DEFAULT_COLOUR_BOUNDARIES_19   0.25
#define  DEFAULT_COLOUR_BOUNDARIES_20   0.20
#define  DEFAULT_COLOUR_BOUNDARIES_21   0.15
#define  DEFAULT_COLOUR_BOUNDARIES_22   0.10
#define  DEFAULT_COLOUR_BOUNDARIES_23   0.05 
#define  DEFAULT_COLOUR_BOUNDARIES_24   0.03
#define  DEFAULT_COLOUR_BOUNDARIES_25   0.01
					/* bottom */
/* default landscape colours */
					/* top */
#define  DEFAULT_COLOUR_00_RED		1.0		
#define  DEFAULT_COLOUR_00_GREEN	1.0		
#define  DEFAULT_COLOUR_00_BLUE		1.0

#define  DEFAULT_COLOUR_01_RED		0.4	
#define  DEFAULT_COLOUR_01_GREEN	0.4		
#define  DEFAULT_COLOUR_01_BLUE		0.4

#define  DEFAULT_COLOUR_02_RED		0.45	
#define  DEFAULT_COLOUR_02_GREEN	0.45		
#define  DEFAULT_COLOUR_02_BLUE		0.45

#define  DEFAULT_COLOUR_03_RED		0.5	
#define  DEFAULT_COLOUR_03_GREEN	0.5		
#define  DEFAULT_COLOUR_03_BLUE		0.5

#define  DEFAULT_COLOUR_04_RED		0.6	
#define  DEFAULT_COLOUR_04_GREEN	0.6		
#define  DEFAULT_COLOUR_04_BLUE		0.6

#define  DEFAULT_COLOUR_05_RED		0.6	
#define  DEFAULT_COLOUR_05_GREEN	0.5		
#define  DEFAULT_COLOUR_05_BLUE		0.5

#define  DEFAULT_COLOUR_06_RED		0.6	
#define  DEFAULT_COLOUR_06_GREEN	0.4		
#define  DEFAULT_COLOUR_06_BLUE		0.4

#define  DEFAULT_COLOUR_07_RED		0.6	
#define  DEFAULT_COLOUR_07_GREEN	0.4		
#define  DEFAULT_COLOUR_07_BLUE		0.4

#define  DEFAULT_COLOUR_08_RED		0.6	
#define  DEFAULT_COLOUR_08_GREEN	0.3		
#define  DEFAULT_COLOUR_08_BLUE		0.3

#define  DEFAULT_COLOUR_09_RED		0.6	
#define  DEFAULT_COLOUR_09_GREEN	0.2		
#define  DEFAULT_COLOUR_09_BLUE		0.2

#define  DEFAULT_COLOUR_10_RED		0.0	
#define  DEFAULT_COLOUR_10_GREEN	0.4		
#define  DEFAULT_COLOUR_10_BLUE		0.0

#define  DEFAULT_COLOUR_11_RED		0.0	
#define  DEFAULT_COLOUR_11_GREEN	0.5		
#define  DEFAULT_COLOUR_11_BLUE		0.0

#define  DEFAULT_COLOUR_12_RED		0.0	
#define  DEFAULT_COLOUR_12_GREEN	0.6		
#define  DEFAULT_COLOUR_12_BLUE		0.0

#define  DEFAULT_COLOUR_13_RED		0.0	
#define  DEFAULT_COLOUR_13_GREEN	0.7		
#define  DEFAULT_COLOUR_13_BLUE		0.0

#define  DEFAULT_COLOUR_14_RED		0.0	
#define  DEFAULT_COLOUR_14_GREEN	0.8		
#define  DEFAULT_COLOUR_14_BLUE		0.0

#define  DEFAULT_COLOUR_15_RED		0.0	
#define  DEFAULT_COLOUR_15_GREEN	0.9		
#define  DEFAULT_COLOUR_15_BLUE		0.3

#define  DEFAULT_COLOUR_16_RED		0.0	
#define  DEFAULT_COLOUR_16_GREEN	0.9		
#define  DEFAULT_COLOUR_16_BLUE		0.4

#define  DEFAULT_COLOUR_17_RED		0.1	
#define  DEFAULT_COLOUR_17_GREEN	0.9		
#define  DEFAULT_COLOUR_17_BLUE		0.4

#define  DEFAULT_COLOUR_18_RED		0.2	
#define  DEFAULT_COLOUR_18_GREEN	0.9		
#define  DEFAULT_COLOUR_18_BLUE		0.4

#define  DEFAULT_COLOUR_19_RED		0.3	
#define  DEFAULT_COLOUR_19_GREEN	0.9		
#define  DEFAULT_COLOUR_19_BLUE		0.4

#define  DEFAULT_COLOUR_20_RED		0.5	
#define  DEFAULT_COLOUR_20_GREEN	0.9		
#define  DEFAULT_COLOUR_20_BLUE		0.4

#define  DEFAULT_COLOUR_21_RED		0.6	
#define  DEFAULT_COLOUR_21_GREEN	0.9		
#define  DEFAULT_COLOUR_21_BLUE		0.4

#define  DEFAULT_COLOUR_22_RED		0.7	
#define  DEFAULT_COLOUR_22_GREEN	0.9		
#define  DEFAULT_COLOUR_22_BLUE		0.4

#define  DEFAULT_COLOUR_23_RED		0.8	
#define  DEFAULT_COLOUR_23_GREEN	0.9		
#define  DEFAULT_COLOUR_23_BLUE		0.4

#define  DEFAULT_COLOUR_24_RED		0.9			
#define  DEFAULT_COLOUR_24_GREEN	0.9		
#define  DEFAULT_COLOUR_24_BLUE		0.4
					/* bottom */

#define  DEFAULT_SKY_COLOUR_RED		0.3
#define  DEFAULT_SKY_COLOUR_GREEN	0.3
#define  DEFAULT_SKY_COLOUR_BLUE	0.9

#define  DEFAULT_FOG_COLOUR_RED		0.3
#define  DEFAULT_FOG_COLOUR_GREEN	0.3
#define  DEFAULT_FOG_COLOUR_BLUE	0.9

#define  DEFAULT_HORIZON_COLOUR_RED	0.3
#define  DEFAULT_HORIZON_COLOUR_GREEN	0.3
#define  DEFAULT_HORIZON_COLOUR_BLUE	0.9

#define  DEFAULT_AMBIENT_LIGHT		0.2

#define  DEFAULT_FOG_START		0.4
#define  DEFAULT_FOG_END		1.0
