#include "../inc/apelib.h"

int main(int argc, char *argv[])
{
  IMG in1, in2, out;
  int i, j, k;
  
  ReadImage(&in1, argv[1]); //1枚目の画像を読み込む
  ReadImage(&in2, argv[2]); //2枚目の画像を読み込む
  
  out.row = in1.row; // 画像の縦サイズを指定
  out.col = in1.col; // 画像の横サイズを指定
  out.bas = in1.bas;
  out.type = in1.type;

  MemImage(&out);
  
  for(k = 0; k < out.bas; k++){
    for(i = 0; i < out.row; i++){
      for(j = 0; j < out.col; j++){
        // 2枚の画像を合成して出力画像用配列に値を格納する
        out.data[k][i][j] = in1.data[k][j][i] + in2.data[k][j][i];
        if(out.data[k][i][j] > 255) {
          out.data[k][i][j] = 255; // 合成した結果が255よりも大きければ255で打ち切る
        }
      }
    }
  }
  WriteImage(&out, argv[3]); //引数を正しく設定しよう
  
  return 0;
}