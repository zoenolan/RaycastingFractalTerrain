/*									*/
/* display variables for engine 					*/
/*									*/

double X_view_angle ;			/* the x axis view angle */
double Y_view_angle ;			/* the y axis view angle */

double X_ray_angle ;			/* the angle between ray in X */
double Y_ray_angle ;                    /* the angle between ray in Y */

double Ray_step ;                       /* the ray step size */

viewport User_view ;			/* the users viewpoint */

unsigned char *Pixel_buffer ;		/* the pixel buffer */
int            Pixel_buffer_width ;     /* it's width */
int            Pixel_buffer_size  ;     /* it's size in bytes */

int Number_of_workers	;		/* number of worker processor */
