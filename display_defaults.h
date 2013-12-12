/* 									*/
/* display values							*/
/*									*/

/*									*/
/* config file tokens ( ALL must be in lower case )			*/
/*									*/

#define X_VIEW_ANGLE_TOKEN "x_view_angle"
#define Y_VIEW_ANGLE_TOKEN "y_view_angle"

#define RAY_STEP_TOKEN "ray_step"

#define X_SCREEN_SIZE_TOKEN "x_screen_size"
#define Y_SCREEN_SIZE_TOKEN "y_screen_size"

#define X_POSITION_TOKEN "x_position"
#define Y_POSITION_TOKEN "y_position"
#define WORKERS_TOKEN "number_of_workers"

/*									*/
/* default values							*/
/*									*/

#define SCREEN_X_SIZE 256                    /* screen size */
#define X_VIEW_ANGLE 120
#define X_Y_RATIO    1
 
#define SCREEN_Y_SIZE     (SCREEN_X_SIZE/X_Y_RATIO)
#define Y_VIEW_ANGLE (X_VIEW_ANGLE/X_Y_RATIO)
#define RAY_STEP     0.0019             /* ray step size */
#define WINDOW_X_POSITION 0
#define WINDOW_Y_POSITION 0

#define NUMBER_OF_WORKERS 8  		/* default number of workers */
