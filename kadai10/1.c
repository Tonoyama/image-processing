#include "../inc/apelib.h"

int main(int argc, char *argv[])
{
  IMG in1, in2, out;
  int i, j, k;
  double trans;

	ReadImage(&in1, argv[1]);
  ReadImage(&in2, argv[2]);

  out.row = in1.row; /* 2枚の入力画像のサイズが異なる場合は出力画像の */
  out.col = in1.col; /* サイズを小さい方に揃えると問題なく動作する    */
  out.bas = in1.bas;
	out.type = in1.type;

  MemImage(&out);
	
  for(k=0; k<out.bas; k++){
		for(i=0; i<out.row; i++){
			for(j=0; j<out.col; j++){
        out.data[k][i][j] = in1.data[k][i][j] * 0.8 + in2.data[k][i][j] * 0.2;
        if(out.data[k][i][j] > 255) {
          out.data[k][i][j] = 255;
        }
      }
    }
  }

	WriteImage(&out, argv[3]); //引数を正しく指定しよう。

  return 0;
}