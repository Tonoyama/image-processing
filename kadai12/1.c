#include "../inc/apelib.h"

int main(int argc, char *argv[])
{
	IMG	in, out;
	int	i, j, k;
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
      Y = (0.299*in.data[0][i][j]/255) + (0.587*in.data[1][i][j]/255) + (0.114*in.data[2][i][j]/255);

      out.data[0][i][j] = (Y + 1.402 * v) * 255.0;
      out.data[1][i][j] = (Y - 0.344 * u - 0.714 * v) * 255.0;
      out.data[2][i][j] = (Y + 1.772 * u) * 255.0;

      for(k=0; k<out.bas; k++){
        if(out.data[k][i][j] < 0.0){
            out.data[k][i][j] = 0;
        }
        if(out.data[k][i][j] > 255.0){
          out.data[k][i][j] = 255.0;
        }
      }
    }
  }
	WriteImage(&out, argv[2]);
	
	return 0;
}