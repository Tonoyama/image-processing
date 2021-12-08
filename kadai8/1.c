#include "../inc/apelib.h"

int main(int argc, char *argv[])
{
	IMG	in, out;
	int	i, j;
  double Y;
	
	ReadImage(&in, argv[1]);
	out.row = in.row;
	out.col = in.col;
	out.bas = in.bas; // 出力画像が「3」の場合：出力画像の色チャンネル数は「3」でも「1」どちらでもOK
	out.type = in.type;
	MemImage(&out);
	/*このサンプルプログラムでは色チャンネルを添字で直接指定している*/
	/*出力画像への輝度値の格納は「out.bas」に指定した値に応じて修正する*/
	/*ここでは出力画像の色チャンネル(out.bas)は「3」として処理している*/
	for(i=0; i<in.row; i++){
		for(j=0; j<in.col; j++){
			//(1)式の場合：輝度値Y = 係数*入力画像Rチャンネル + 係数*入力画像Gチャンネル + 係数*入力画像Bチャンネル; 
			Y = 0.333*in.data[0][i][j] + 0.333*in.data[1][i][j] + 0.333*in.data[2][i][j];
			out.data[0][i][j] = Y;
			out.data[1][i][j] = Y;
			out.data[2][i][j] = Y;}}
	WriteImage(&out, argv[2]);
	
	return 0;
}