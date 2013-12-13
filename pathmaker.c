#include <math.h>

#define END_VALUE 600

int main ()
{
	int Counter=0 ;
	double X;
	double Y;
	double Angle ;
	FILE  *Output;

	/* open output file */
	if ((Output = fopen("flyby.path", "w")) == NULL)
	{
		fprintf(stderr, "Cannot open file\n");
	}


	while (Counter <END_VALUE)
	{
		X=0 ;
		Y=(Counter*0.4) ;
		Angle=0 ;
		fprintf(Output, "position = %f,%f,%f\n",X,Y,Angle);
		Counter++ ;
	} 

	fclose (Output) ;

}
