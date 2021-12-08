#include "../inc/apelib.h"

int main(int argc, char *argv[])
{
	IMG	in, out;
	int	i, j, n, y;
  double Y, X;
	
	ReadImage(&in, argv[1]);
	out.row = in.row;
	out.col = in.col;
	out.bas = in.bas;
	out.type = in.type;
	MemImage(&out);
  printf("2 以上 256 以下の階:");
  scanf("%d", &n);

  if(n <= 2 || 256 <= n){
    printf("2 以上 256 以下の範囲の値:");
    return 0;
  }
  X = 256.0 / (double)n;
	for(i=0; i<in.row; i++){
		for(j=0; j<in.col; j++){
			y = 0.333*in.data[0][i][j] + 0.333*in.data[1][i][j] + 0.333*in.data[2][i][j];
      y = (double)(y / X);
      Y = (double)y * X;

			out.data[0][i][j] = Y;
			out.data[1][i][j] = Y;
			out.data[2][i][j] = Y;
    }
  }
	WriteImage(&out, argv[2]);
	return 0;
}