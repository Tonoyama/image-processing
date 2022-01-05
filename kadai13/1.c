#include "../inc/apelib.h"
#include <math.h>
#define PI 3.14159265
#define MAX(x,y,z) x > (y>z? y:z)? x: (y>z? y:z)
#define MIN(x,y,z) x < (y<z? y:z)? x: (y<z? y:z)

double hue(double r, double g, double b)
{
	return atan2(sqrt(3) * (g-b), (r-g) + (r-b)) * 180.0 / PI;
}

int main(int argc, char *argv[])
{
	IMG	in, out;
	int	k, i, j;
	double max, min;
	double r, g, b, H, S, V, Y, H_min = 0.0, H_max = 0.0, S_min = 0.0,S_max=0.0, V_min = 0.0,V_max=0.0;
	
	
	/* 色相の範囲指定 */
  printf("色相 H 開始角度 [0 deg. - 360 deg.] >> ");
  scanf("%lf", &H_min);
  printf("色相 H 終了角度 [0 deg. - 360 deg.] >> ");
  scanf("%lf", &H_max);
	/* 彩度の範囲指定 */
  printf("彩度 H 開始 [0%% - 100%%] >> ");
  scanf("%lf", &S_min);
  printf("彩度 S 終了 [0%% - 100%%] >> ");
  scanf("%lf", &S_max);
	/* 明度の範囲指定 */
  printf("明度 V 開始 [0%% - 100%%] >> ");
  scanf("%lf", &V_min);
  printf("明度 V 終了 [0%% - 100%%] >> ");
  scanf("%lf", &V_max);
	
	ReadImage(&in, argv[1]);
	
	out.row = in.row;
	out.col = in.col;
	out.bas = in.bas;
	out.type = in.type;
	MemImage(&out);
	
	for(i = 0; i < in.row; i++){
		for(j = 0; j < in.col; j++){
			r = in.data[0][i][j] / 255.0;
			g = in.data[1][i][j] / 255.0;
			b = in.data[2][i][j] / 255.0;
			
			max = MAX(r, g, b);
			min = MIN(r, g, b);
			
			H = hue(r, g, b);
			S = ((max - min) / max) * 100;
			V = max * 100;
			Y = 0.2126 * r + 0.6152 * g + 0.072 * b;
			if(H_min <= H && H <= H_max &&
        S_min <= S && S <= S_max &&
        V_min <= V && V <= V_max
      ){
        for(k=0;k<out.bas; k++){
          out.data[k][i][j] = in.data[k][i][j];
        }
			}
			else{
        for(k=0;k<out.bas; k++){
          out.data[k][i][j] = Y * 255;
        }
			}
		}
	}
	
	WriteImage(&out, argv[2]);
	
	return 0;
}