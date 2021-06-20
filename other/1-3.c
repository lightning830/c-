#include<stdio.h>

#define _USE_MATH_DEFINES
#include<math.h>
#define NUM 13

//構造体の宣言
typedef struct position {
	int num;
	double x;
	double y;
	double z;


}position;



//関数の宣言
void input(int a, position* position, FILE* fp);
void output(int a, position position);
int judge(int i, position position, int* p1, int* p2);
void mdeg(int i, position position, int p1[], int p2[], double* p3);
void deg(int i, position position, int p1[], int p2[], double* p3, double* p4);
void Swap(int* x, int* y);
void Swap2(double* x, double* y);
void Sort(int* p1, int* p2, int* p3, int k, double* p4, double* p5, double* p6);
void LOG(int* p1, int* p2, int k, double* p3, double* p4, double* p5,FILE *fp2);


int main(void) {

	//構造体の宣言
	position position[NUM];


	FILE* fp1;
	FILE* fp2;

	fp1 = fopen("1sample.csv", "r");
	fp2 = fopen("1result.csv", "w");

	char tag[4][10];
	int i;
	int j;
	int k = 0;
	int l = 0;

	int ActX[NUM] = { 0 };//データ初期
	int ActY[NUM] = { 0 };//データ初期

	double Mdeg[NUM] = { 0 };
	double A1deg[NUM] = { 0 };
	double A2deg[NUM] = { 0 };
	double Mdeg2[NUM] = { 0 };
	double A1deg2[NUM] = { 0 };
	double A2deg2[NUM] = { 0 };
	int okng[NUM] = { 0 };

	int* p1 = ActX;
	int* p2 = ActY;
	double* p3 = Mdeg;
	double* p7 = Mdeg2;
	double* p8 = A1deg2;
	double* p9 = A2deg2;
	double* p10 = A1deg;


	//１行目よみこみ
	fscanf(fp1, "%[^,],%[^,],%[^,],%s\n", tag[0], tag[1], tag[2], tag[3]);



	printf("\n");

	//構造体に代入
	for (i = 0; i < NUM; i++) {
		input(i, &position[i], fp1);
	}

	printf("csvファイルの読み込みに成功しました\n\n");
	printf("%d個のポイントデータを検出しました\n\n", NUM);

	//確認用出力
	for (i = 0; i < 4; i++) {
		printf("%s ", tag[i]);
		if (i == 3) {
			printf("\n");
		}
	}
	for (i = 0; i < NUM; i++) {
		//座標
		output(i, position[i]);
		printf("\n");
	}

	printf("\n\n");


	printf("\n");
	for (i = 0; i < NUM; i++) {

		j = judge(i, position[i], ActX, ActY);
		if (j == 1) {

			okng[i] = 1;
			k++;

		}
		else {
			okng[i] = 0;
		}


	}

	printf("%d個の有効なポイントデータを検出しました。\n\n", k);


	int num_def[NUM] = { 0 };//リーチング可
	int ActX1[NUM] = { 0 };//リーチング可
	int ActY1[NUM] = { 0 };//リーチング可

	int* p4 = ActX1;
	int* p5 = ActY1;
	int* p6 = num_def;

	for (i = 0; i < 4; i++) {
		printf("%s ", tag[i]);
		if (i == 3) {
			printf("\n");
		}
	}

	for (i = 0; i < NUM; i++) {
		//座標
		output(i, position[i]);


		if (okng[i] == 1) {
			printf("OK");
			printf(" %d  %d ", ActX[i], ActY[i]);
			mdeg(i, position[i], ActX, ActY, Mdeg);
			printf(" %3.2f", Mdeg[i]);
			deg(i, position[i], ActX, ActY, A1deg, A2deg);

			//reachingに代入

			if (ActX[i] == 0) {
				num_def[l] = i + 1;
				ActX1[l] = i + 1;
				ActY1[l] = 1;
				l++;

			}
			else {
				num_def[l] = i + 1;
				ActX1[l] = ActX[i];
				ActY1[l] = ActY[i];
				Mdeg2[l] = Mdeg[i];
				A1deg2[l] = A1deg[i];
				A2deg2[l] = A2deg[i];
				l++;
			}
		}
		else {
			printf("NG");
			printf(" -   -  \n");
		}
	}

	printf("\n\n");




	//確認用出力
	for (i = 0; i < NUM; i++) {

		if (ActX1[i] != 0) {
			printf("%2d  %d  %d  %3.2f  %3.2f  %3.2f\n", num_def[i], ActX1[i], ActY1[i], Mdeg2[i], A1deg2[i], A2deg2[i]);
		}
	}

	printf("\n\n");


	Sort(p4, p5, p6, k, p7, p8, p9);
	printf("\n");

	printf("リーチングを行う順番を算出しました。\n\n");

	printf("\n\n");

	/*for (i = 0; i < NUM; i++) {
		printf("%d   %d   %d\n", num_def[i], ActX1[i], ActY1[i]);
	}

	printf("\n\n");
	*/

	for (i = 0; i < NUM; i++) {

		if (ActX1[i] != 0) {
			printf("%2d  %d  %d  %3.2f  %3.2f  %3.2f\n", num_def[i], ActX1[i], ActY1[i], Mdeg2[i], A1deg2[i], A2deg2[i]);
		}
	}

	printf("\n\nログを示します。\n\n");

	printf("AbsCoordinate  RelCoordinate    MachineDeg    ArmDeg1      ArmDeg2      ActState\n");
	fprintf(fp2, "ロボット座標Ｘ ,ロボット座標Ｙ, ΔＸ,ΔＹ,ロボット角度 ,   アーム１角度  , アーム２角度  ,    ActState\n");

	LOG(p4, p5, k, p7, p8, p9,fp2);

	printf("ファイルへの書きこみが完了しました\n");


	fclose(fp1);
	fclose(fp2);

	return 0;
}



void input(int a, position* position, FILE* fp) {
	fscanf(fp, "%d,%lf,%lf,%lf\n", &position->num, &position->x, &position->y, &position->z);
}

//出力関数
void output(int a, position position) {
	printf("%2d %8.2f %7.2f %7.2f  ", position.num, position.x, position.y, position.z);
}




//届くかどうか判断する。
int judge(int i, position position, int* p1, int* p2) {

	double a = position.x;
	double b = position.y;
	double c = position.z;
	double x;//一番近い黒点のｘ
	double y = 0;//一番近い黒点のy
	int dx = 0;
	int dy = 0;
	double ex = 0;
	double ey = 0;
	double f;//一番近い黒点からの距離
	int g;//出力
	//確認用
	//printf("  %lf %lf  ", a,b);

	//一番近い黒点を判断する。(x)
	if (a <= 1000) {
		///printf("a=%lf",a);
		x = 1000;
		//printf("  x=%lf  ", x);
	}
	else if (a >= 9000.0) {
		x = 9000;
		//printf("  x=%lf  ", x);
	}
	else {
		dx = a / 1000;
		//printf(" dx=%d ", dx);
		ex = a - (double)dx * 1000;
		//printf(" ex=%lf ", ex);
		if (ex <= 500) {
			x = (double)dx * 1000;
			//printf("  x=%lf  ", x);
		}
		else {
			x = ((double)dx + 1) * 1000;
			//printf("  x=%lf  ", x);
		}
	}

	//一番近い黒点を判断する。(y)
	if (b <= 1000) {
		//printf("b=%lf", b);
		y = 1000;
		//printf("  y=%lf  ", y);
	}
	else if (b >= 9000.0) {
		y = 9000;
		//printf("  y=%lf  ", y);
	}
	else {
		dy = b / 1000;
		//printf(" dy=%d ", dy);
		ey = b - (double)dy * 1000;
		//printf(" ey=%lf ", ey);
		if (ey <= 500) {
			y = (double)dy * 1000;
			//printf("  y=%lf  ", y);
		}
		else {
			y = ((double)dy + 1) * 1000;
			//printf("  y=%lf  ", y);
		}
	}

	//printf(" x=%4.f y=%4.f  ", x,y);
	//届くかどうか判断する。
	f = (a - x) * (a - x) + (b - y) * (b - y) + (c - 100) * (c - 100);

	if (ex == 0 && ey == 0 && c == 0) {
		g = 0;
	}
	else if (f <= 810000) {
		g = 1;//届いた
	}
	else {
		g = 0;//届かない
	}

	p1[i] = x;
	p2[i] = y;
	//printf("%d %d", p1[i], p2[i]);

	return g;

}

//MDegの計算
void mdeg(int i, position position, int p1[], int p2[], double* p3) {
	double a = position.x;
	double b = position.y;
	double c = position.z;
	//printf("a=%lf b=%lf C=%lf", a, b, c);
	int x = p1[i];
	int y = p2[i];
	//printf("  x=%d,y=%d  ", x, y);
	double mdeg;//結果

	//printf("1");
	if ((b - y) == 0 && (a - x) == 0) {//黒点上
		mdeg = 0.00;
	}
	else if ((b - y) > 0 && (a - x) < 0) {//第２象限
		mdeg = 180 + atan((b - y) / (a - x)) / (M_PI) * 180;
	}
	else if ((b - y) < 0 && (a - x) < 0) {//第３象限
		mdeg = atan((b - y) / (a - x)) / (M_PI) * 180 - 180;

	}
	else {
		mdeg = atan((b - y) / (a - x)) / (M_PI) * 180;
	}

	//printf("%3.2f\n", mdeg);

	p3[i] = mdeg;
	//printf("%3.2f\n", p3[i]);
	return;
}

//A1deg,A2degの計算
void deg(int i, position position, int p1[], int p2[], double* p3, double* p4) {
	double a = position.x;
	double b = position.y;
	double c = position.z;
	//printf("a=%lf b=%lf C=%lf", a, b, c);
	int x = p1[i];
	int y = p2[i];
	//printf("  x=%d,y=%d  ", x, y);
	double l1 = 500;
	double l2 = 400;
	double ld;

	double t1;
	double t2;
	double ar;
	double be;
	double phi;

	ld = sqrt((a - x) * (a - x) + (b - y) * (b - y) + (c - 100) * (c - 100));
	//printf(" %.2f ", ld);


	ar = acos((l1 * l1 + ld * ld - l2 * l2) / (2 * l1 * ld)) * 180 / M_PI;
	be = acos((l1 * l1 + l2 * l2 - ld * ld) / (2 * l1 * l2)) * 180 / M_PI;
	phi = atan((c - 100) / sqrt((a - x) * (a - x) + (b - y) * (b - y))) * 180 / M_PI;
	//printf(" %.2f %.2f %.2f\n", ar, be, phi);

	t1 = -ar + phi;
	t2 = 180 - be;
	printf("  %.2f %.2f \n", t1, t2);

	p3[i] = t1;
	p4[i] = t2;

	return;
}



//リーチング順番選定

void Swap(int* x, int* y) {//入れ替え

	int c;
	c = *x;
	*x = *y;
	*y = c;
}

void Swap2(double* x, double* y) {//入れ替え

	double c;
	c = *x;
	*x = *y;
	*y = c;
}

void Sort(int* p1, int* p2, int* p3, int k, double* p4, double* p5, double* p6) {

	int* t1[NUM];//アドレスをそれぞれｔに格納
	int* t2[NUM];
	int* t3[NUM];
	double* t4[NUM];
	double* t5[NUM];
	double* t6[NUM];
	int i;


	for (i = 0; i < NUM; i++) {
		//printf("  %d  %d", p1[i], p2[i]);
		//printf("  %d  %d", &p1[i], &p2[i]);
		t1[i] = &p1[i];
		t2[i] = &p2[i];
		t3[i] = &p3[i];
		t4[i] = &p4[i];
		t5[i] = &p5[i];
		t6[i] = &p6[i];
		//printf("  %d  %d", t1[i], t2[i]);
		//printf("  %d  %d\n", *t1[i], *t2[i]);
		//printf("  %3.2f  %3.2f\n", *t4[i], *t5[i]);
		//printf("\n");
	}

	//printf("1");

	while (1) {//x並び替え

		int flag = 1;//そろっているという態で始める
		for (i = 0; i < k - 1; i++) {
			//printf("\n%d ", i);

			if (*t1[i] > * t1[i + 1]) {
				flag = 0;
				//printf("1");

				Swap(t1[i], t1[i + 1]);
				Swap(t2[i], t2[i + 1]);
				Swap(t3[i], t3[i + 1]);
				Swap2(t4[i], t4[i + 1]);
				Swap2(t5[i], t5[i + 1]);
				Swap2(t6[i], t6[i + 1]);

			}

		}

		if (flag == 1) {
			//printf("4");
			break;
		}
	}




	while (1) {//ｙ並び替え

		int flag = 1;
		for (i = 0; i < k - 1; i++) {
			//printf("\n%d ", i);


			if (*t1[i] == *t1[i + 1]) {//xが同じ

				int a;
				a = (*t1[i] / 1000) % 2;
				//printf("%d", a);
				if (a != 0) {//1000,3000,5000,7000,9000
					if (*t2[i] > * t2[i + 1]) {

						flag = 0; 
							Swap(t1[i], t1[i + 1]);
						Swap(t2[i], t2[i + 1]);
						Swap(t3[i], t3[i + 1]);
						Swap2(t4[i], t4[i + 1]);
						Swap2(t5[i], t5[i + 1]);
						Swap2(t6[i], t6[i + 1]);
					}
				}
				else {//2000,4000,6000,8000

					if (*t2[i] < *t2[i + 1]) {
						flag = 0; 
							Swap(t1[i], t1[i + 1]);
						Swap(t2[i], t2[i + 1]);
						Swap(t3[i], t3[i + 1]);
						Swap2(t4[i], t4[i + 1]);
						Swap2(t5[i], t5[i + 1]);
						Swap2(t6[i], t6[i + 1]);
					}
				}
			}


		}

		if (flag == 1) {
			//printf("4");
			break;
		}
	}

}

//ログ用関数
void LOG(int* p1, int* p2, int k, double* p3, double* p4, double* p5,FILE* fp2) {
	int i;
	int j1 = 0;
	int j2 = 0;
	int x1;
	int y1;
	int x2;
	int y2;
	int a;
	int a1;
	int b;
	int b1;

	/*for (i = 0; i < k; i++) {
		printf("  %3.2f deg  ", p3[i]);
		printf("  %3.2f deg  ", p4[i]);
		printf("  %3.2f deg  \n", p5[i]);
	}*/


	while (1) {

		for (j1 = 0; j1 < k; j1++) {

			if (j1 == 0) {//最初

				x1 = 1000;
				y1 = 1000;
				x2 = p1[j1];
				y2 = p2[j1];


				//printf("  %d   %d  \n", x2, y2);

				if (x1 != x2) {//x繰り上がりあり
					//printf("  1  ");

					b = (x2 - x1) / 1000;

					for (j2 = 0; j2 < b; j2++) {

						printf("( %4d, %4d)  ", x2, y1);
						printf("( %4d, %4d)", j2 * 1000, 0);
						printf("     0.00 deg      90.00 deg       -90.00 deg");
						printf("   N/A\n");
						fprintf(fp2, "%4d,%4d,%4d,0.00,0.00deg,90.00deg,-90.00deg,N/A\n ", x2, y1, j2 * 1000);
					}

					a = (y2 - y1) / 1000;

					for (j2 = 0; j2 < a; j2++) {

						printf("( %d, %d)  ", x2, y1 + j2 * 1000);
						printf("( %5d, %4d)", x2 - x1, j2 * 1000);
						fprintf(fp2, "%4d,%4d,%4d,%4d, ", x2, y1 + j2 * 1000, x2 - x1, j2 * 1000);
						if (j2 != a - 1) {
							printf("    0.00 deg      90.00 deg      -90.00 deg");
							printf("   N/A\n");
							fprintf(fp2,"0.00deg,90.0deg,-90.00deg,N/A\n");
						}
						else {
							printf("  %3.2f deg     %3.2f deg    %3.2f deg", p3[0], p4[0], p5[0]);
							printf(" Leaching\n");
							fprintf(fp2, "%3.2f deg,%3.2f deg,%3.2f deg,Leaching\n", p3[0], p4[0], p5[0]);
						}
					}


				}
				else {//x繰り上がりなし
				   //printf("  2  ");

					a = (y2 - y1) / 1000 + 1;

					for (j2 = 0; j2 < a; j2++) {

						printf("( %d, %d)  ", x2, y1 + j2 * 1000);
						printf("( %5d, %4d)", x2 - x1, j2 * 1000);
						fprintf(fp2, "%4d,%4d,%4d,%4d, ", x2, y1 + j2 * 1000, x2 - x1, j2 * 1000);
						if (j2 != a - 1) {
							printf("    0.00 deg     90.00 deg    -90.00 deg");
							printf("   N/A\n");
							fprintf(fp2, "0.00deg,90.0deg,-90.00deg,N/A\n");
						}
						else {
							printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[0], p4[0], p5[0]);
							printf(" Leaching\n"); 
							fprintf(fp2, "%3.2f deg,%3.2f deg,%3.2f deg,Leaching\n", p3[0], p4[0], p5[0]);

						}
					}

				}
			}
			else {//最初以外


				x1 = p1[j1 - 1];
				y1 = p2[j1 - 1];


				x2 = p1[j1];
				y2 = p2[j1];


				//printf("  %d  %d  %d  %d \n", x1, y1, x2, y2);

				if (x1 != x2) {//x繰り上がりあり

					//printf("  3  ");

					b = (x2 - x1) / 1000;

					for (j2 = 0; j2 < b; j2++) {

						printf("( %d, %4d)  ", x1 + (j2 + 1) * 1000, y1);
						printf("( %5d,    0)", (j2 + 1) * 1000);
						printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[j1-1], p4[j1-1], p5[j1-1]);
						printf("   N/A\n");
						fprintf(fp2,"%d,%4d,%5d, 0,%3.2f deg,%3.2f deg,%3.2f deg,N/A\n", x1 + (j2 + 1) * 1000, y1, (j2 + 1) * 1000, p3[j1 - 1], p4[j1 - 1], p5[j1 - 1]);

					}


					a = (y2 - y1) / 1000;
					//printf("  %d  ", a);

					if (a > 0) {

						for (j2 = 0; j2 < a; j2++) {

							printf("( %d, %d)  ", x2, y1 + (j2 + 1) * 1000);
							printf("(     0,%5d)", (j2 + 1) * 1000);
							fprintf(fp2, "%d,%d,0,%5d,", x2, y1 + (j2 + 1) * 1000, (j2 + 1) * 1000);
							if (j2 != a - 1) {
								printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[j1-1], p4[j1-1], p5[j1-1]);
								printf("   N/A\n");
								fprintf(fp2,"%3.2f deg,%3.2f deg,%3.2f deg,N/A\n",  p3[j1 - 1], p4[j1 - 1], p5[j1 - 1]);
							}
							else {
								printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[j1], p4[j1], p5[j1]);
								printf(" Leaching\n");
								fprintf(fp2,"%.2f deg,%3.2f deg,%3.2f deg,Leaching\n", p3[j1], p4[j1], p5[j1]);
							}

						}
					}
					else {
						a = -1 * a;

						for (j2 = 0; j2 < a; j2++) {

							printf("( %d, %d)  ", x2, y1 - (j2 + 1) * 1000);
							printf("(     0,%5d)", -1 * (j2 + 1) * 1000);
							fprintf(fp2, "%d,%d,0,%d,", x2, y1 - (j2 + 1) * 1000, -1 * (j2 + 1) * 1000);

							if (j2 != a - 1) {
								printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[j1-1], p4[j1-1], p5[j1-1]);
								printf("   N/A\n");
								fprintf(fp2, "%3.2f deg,%3.2f deg,%3.2f deg,N/A\n", p3[j1 - 1], p4[j1 - 1], p5[j1 - 1]);
							}
							else {
								printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[j1], p4[j1], p5[j1]);
								printf(" Leaching\n");
								fprintf(fp2, "%3.2f deg,%3.2f deg,%3.2f deg,Leaching\n", p3[j1], p4[j1], p5[j1]);
							}

						}

					}


				}
				else {//x繰り上がりなし
					//printf("  4  ");

					a = (y2 - y1) / 1000;
					//printf("  %d  ", a);

					if (a > 0) {

						for (j2 = 0; j2 < a; j2++) {

							printf("( %d, %d)  ", x2, y1 + j2 * 1000);
							printf("(     0,%5d)", j2 * 1000);
							fprintf(fp2, "%d,%d,0,%5d,", x2, y1 + j2 * 1000, j2 * 1000);

							if (j2 != a - 1) {
								printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[j1-1], p4[j1-1], p5[j1-1]);
								printf("   N/A\n");
								fprintf(fp2,"%3.2f deg,%3.2f deg,%3.2f deg,N/A\n", p3[j1 - 1], p4[j1 - 1], p5[j1 - 1]);
							}
							else {
								printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[j1], p4[j1], p5[j1]);
								printf(" Leaching\n");
								fprintf(fp2, "%3.2f deg,%3.2f deg,%3.2f deg,Leaching\n", p3[j1], p4[j1], p5[j1]);
							}

						}
					}
					else {//here
						a = -1 * a;

						for (j2 = 0; j2 < a; j2++) {

							printf("( %d, %d)  ", x2, y1 - (j2 + 1) * 1000);
							printf("(     0,%5d)", -1 * (j2 + 1) * 1000);
							fprintf(fp2,"%d,%d,0,%5d,", x2, y1 - (j2 + 1) * 1000, -1 * (j2 + 1) * 1000);
							if (j2 != a - 1) {
								printf("  %3.2f deg     %3.2f deg     %3.2f deg, %d", p3[j1-1], p4[j1-1], p5[j1-1], j1-1);
								printf("   N/A\n");
								fprintf(fp2, "%3.2f deg,%3.2f deg,%3.2f deg,N/AA\n", p3[j1 - 1], p4[j1 - 1], p5[j1 - 1]);
							}
							else {
								printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[j1], p4[j1], p5[j1]);
								printf(" Leaching\n");
								fprintf(fp2,"%3.2f deg,%3.2f deg,%3.2f deg,LeachingA\n", p3[j1], p4[j1], p5[j1]);
							}
						}

					}

				}

			}

		}

		break;

	}

	//初期位置に戻る

	x2 = p1[k - 1];
	y2 = p2[k - 1];
	//printf("%d %d\n", x2, y2);

	//ｙが1000になるまで移動
	a1 = (y2 - 1000) / 1000;

	if (a1 != 0) {
		for (i = 1; i < a1 + 1; i++) {
			printf("( %d, %d)  ", x2, y2 - 1000 * i);
			printf("(    0, %d)", -1000 * i);
			printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[k-1], p4[k-1], p5[k-1]);
			printf("   N/A\n");
			fprintf(fp2, "%d,%d,0,%d,%3.2f deg,%3.2f deg,%3.2f deg,N/A\n", x2, y2 - 1000 * i, -1000 * i, p3[k - 1], p4[k - 1], p5[k - 1]);
		}
	}

	//xが1000になるまで移動
	b1 = (x2 - 1000) / 1000;

	if (b1 != 0) {
		for (i = 1; i < b1 + 1; i++) {
			printf("( %d, 1000)  ", x2 - i * 1000);
			printf("( %d,    0)", -1000 * i);
			printf("  %3.2f deg     %3.2f deg     %3.2f deg", p3[k - 1], p4[k - 1], p5[k - 1]);
			printf("   N/A\n");
			fprintf(fp2, "%d,1000,%d,0, %3.2f deg , %3.2f deg , %3.2f deg ,N/A\n", x2 - i * 1000, -1000 * i, p3[k - 1], p4[k - 1], p5[k - 1]);
		}
	}

	return;
}