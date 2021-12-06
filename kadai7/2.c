#include "../inc/apelib.h"

int main(int argc, char *argv[])
{
	IMG	in, out;
	int	i, j, k;
  double fmin[3] = {0.0,0.0,0.0},
  fmax[3] = {0.0,0.0,0.0};
	ReadImage(&in, argv[1]);
	out.row = in.row;
	out.col = in.col;
	out.bas = in.bas;
	out.type = in.type;
	MemImage(&out);
  for(k=0; k<out.bas; k++){
		for(i=0; i<out.row; i++){
			for(j=0; j<out.col; j++){
        if(fmax[k] < in.data[k][i][j]) fmax[k] = in.data[k][i][j];
        if(fmin[k] > in.data[k][i][j]) fmin[k] = in.data[k][i][j];
			}
		}
	}

  for(k=0; k<out.bas; k++){
		for(i=0; i<out.row; i++){
			for(j=0; j<out.col; j++){
        out.data[k][i][j] = ((in.data[k][i][j] - fmin[k])/(fmax[k] - fmin[k]))*255;
			}
		}
	}
	WriteImage(&out, argv[2]);

	return 0;
}