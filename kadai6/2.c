#include"../inc/apelib.h"

int main(int argc, char *argv[])
{
  IMG in1, in2, in3, out;
  int i, j,k, channel_num;
  char color;

  ReadImage(&in1, argv[1]);
  ReadImage(&in2, argv[2]);
  ReadImage(&in3, argv[3]);
  
  out.row = in1.row;
  out.col = in1.col;
  out.bas = 3; //出力画像をモノクロ画像で表示するため色数の指定は「1」
  out.type = in1.type;

  MemImage(&out);
  for(i = 0; i < out.row; i++){
    for(j = 0; j < out.col; j++){
      //キーボードで指定された色チャンネル画像を出力画像として複製を行う；
      out.data[0][i][j] = in1.data[0][i][j];
      out.data[1][i][j] = in2.data[0][i][j];
      out.data[2][i][j] = in3.data[0][i][j];
    }
  }

  WriteImage(&out, argv[4]);
  return 0;
}