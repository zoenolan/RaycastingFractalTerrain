/* 									*/
/* Window functions fro the engine					*/
/*									*/


/*                                                                      */
/* Text Strings                                                         */
/*                                                                      */

#define  PROGRAM_NAME        "-= Terrain Engine =-" /* name of the window */


/*                                                                      */
/*                                                                      */
/* open and set up the window                                           */
/*                                                                      */
open_window()
{
	/* set the window */

	auxInitDisplayMode (AUX_SINGLE | AUX_RGB);
	auxInitPosition (User_view.X,User_view.Y,User_view.X_size,User_view.Y_size);
	auxInitWindow (PROGRAM_NAME);

	/* turn off the unneeded functions */

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_DITHER);
	glDisable(GL_FOG);
	glDisable(GL_LIGHTING);
	glDisable(GL_LOGIC_OP);
	glDisable(GL_STENCIL_TEST);
	glDisable(GL_TEXTURE_1D);
	glDisable(GL_TEXTURE_2D);

}
/*                                                                      */
/* end setup window                                                     */
/*                                                                      */

