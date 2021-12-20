#include "../inc/apelib.h"

int main(int argc, char *argv[])
{
	IMG	in, out;
	int	i, j;
  double Y,u,v, R,G,B;
	
	ReadImage(&in, argv[1]);
	out.row = in.row;
	out.col = in.col;
	out.bas = in.bas;
	out.type = in.type;
	MemImage(&out);
  u = -0.08;
  v = 0.071;
	for(i=0; i<in.row; i++){
		for(j=0; j<in.col; j++){
			Y = 0.299*in.data[0][i][j] + 0.587*in.data[1][i][j] + 0.114*in.data[2][i][j];
      R = 1.0 * Y + 0.0 * u + 1.402 * v;
      G = Y - 0.344*u - 0.714*v;
      B = Y + 1.772*u;
			out.data[0][i][j] = R;
			out.data[1][i][j] = G*0.7;
			out.data[2][i][j] = B*0.4;
    }
  }
	WriteImage(&out, argv[2]);
	
	return 0;
}