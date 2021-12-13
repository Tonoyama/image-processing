#include "../inc/apelib.h"

int main(int argc, char *argv[])
{
  IMG	in, out;
  int	i, j, k;
  double y;

  ReadImage(&in, argv[1]);
	
  out.row = in.row;
  out.col = in.col;
  out.bas = in.bas;
  out.type = in.type;
  MemImage(&out);
	
  for(k = 0; k < out.bas; k++){
    for(i = 0; i < out.row; i++){
      for(j = 0; j < out.col; j++){
        if(j < out.col / 2){
          y = (double)(j * 2) / (double) out.col;
        }else{
          y = (double)((out.col - j) * 2) / (double) out.col;
        }
        out.data[k][i][j] = in.data[k][i][j] * y;
      }
    }
  }
  

  WriteImage(&out, argv[2]);

  return 0;
}