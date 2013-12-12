  void  save_ppm (char *Filename, unsigned char *Image, int Width, 
                    int Height, int Max_value)
    {
	register int X, Y;
	unsigned char   R, G, B;
        FILE  *Output;

/* open output file */
        if ((Output = fopen(Filename, "w")) == NULL)
          {
           fprintf(stderr, "Cannot open file\n");
          }

/* write header */
	fprintf(Output, "P6\n");
	fprintf(Output, "%d %d\n", Width, Height);
	fprintf(Output, "%d\n", Max_value);

/* save image */
	for ( Y = Height ; Y > 0 ; Y-- )
          {
	    for ( X = 0; X < Width; X++ )
	    {
		R = Image[(Y*3*Width)+(X*3)+0];  
		G = Image[(Y*3*Width)+(X*3)+1];    
		B = Image[(Y*3*Width)+(X*3)+2];

		fwrite(&R, 1, 1, Output);
		fwrite(&G, 1, 1, Output);
		fwrite(&B, 1, 1, Output);
	    }
	  }
       fclose (Output) ;
    }
