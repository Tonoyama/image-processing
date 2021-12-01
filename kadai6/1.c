#include"../inc/apelib.h"

int main(int argc, char *argv[])
{
  IMG in, out;
  int i, j, channel_num;
  char color;

  ReadImage(&in, argv[1]);

  printf("どの色に分解しますか？ [R or G or B]で指定 : ");
  scanf("%c", &color);
  
  switch(color) {
    case 'r':
    case 'R':
      channel_num = 0;
      break;
    case 'g':
    case 'G':
      channel_num = 1;
      break;
    case 'b':
    case 'B':
      channel_num = 2;
      break;
    default:
    printf("正しく指定してください");
  }
  
  out.row = in.row;
  out.col = in.col;
  out.bas = 1; //出力画像をモノクロ画像で表示するため色数の指定は「1」
  out.type = in.type;

  MemImage(&out);

  for(i = 0; i < out.row; i++){
    for(j = 0; j < out.col; j++){
      //キーボードで指定された色チャンネル画像を出力画像として複製を行う；
      out.data[0][i][j] = in.data[channel_num][i][j];
    }
  }

  WriteImage(&out, argv[2]);
  return 0;
}