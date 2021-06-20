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
void deg(int i, position position, int p1[], int p2[]);
void Swap(int** x, int** y);
void Sort(int* p1, int* p2,int*p3,int k);
void LOG(int* p1, int* p2, int k);


int main(void) {

	//構造体の宣言
	position position[NUM];


	FILE* fp1;

	fp1 = fopen("1sample.csv", "r");

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
	int okng[NUM] = { 0 };

	int* p1 = ActX;
	int* p2 = ActY;
	double* p3 = Mdeg;
	

	//１行目よみこみ
	fscanf(fp1, "%[^,],%[^,],%[^,],%s\n", tag[0], tag[1], tag[2], tag[3]);

	

	printf("\n");

	//構造体に代入
	for (i = 0; i < NUM; i++) {
		input(i, &position[i], fp1);
	}

	printf("csvファイルの読み込みに成功しました\n\n");
	printf("%d個のpoint dataを検出しました\n\n", NUM);

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
		
		j=judge(i, position[i],ActX,ActY);
		if (j == 1) {
			
			okng[i] = 1;
			k++;
			
		}
		else {
			okng[i] = 0;
		}


	}

	printf("%d個の有効なポイントデータを検出しました。\n\n", k);

	int num_def[k];//リーチング可
	int ActX1[k];//リーチング可
	int ActY1[k];//リーチング可
	for(int i = 0; i < k; i++){num_def[i] = ActX1[i] = ActY1[i] = 0;}
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
			deg(i, position[i], ActX, ActY);

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
	/*for (i = 0; i < NUM; i++) {

		if (ActX1[i] != 0) {
			printf("%2d  %d  %d \n",num_def[i], ActX1[i], ActY1[i]);
		}
	}

	printf("\n\n");
	*/


	Sort(p4, p5,p6,k);
	printf("\n");

	printf("リーチングを行う順番を算出しました。\n\n");

	printf("\n\n");

	for (i = 0; i < k; i++) {
		printf("%d   %d   %d\n", num_def[i], ActX1[i], ActY1[i]);
	}

	printf("\n\n");

	for (i = 0; i < k; i++) {

		if (ActX1[i] != 0) {
			printf("%2d  %2d  %d  %d \n",i+1, num_def[i], ActX1[i], ActY1[i]);
		}
	}

	printf("\n\nログを示します。\n\n");

	printf("AbsCoordinate  RelCoordinate  MashineDeg  ArmDeg1    ArmDeg2   ActState\n");

	LOG(p4, p5, k);

	return 0;
}

void input(int a, position* position, FILE* fp) {
	fscanf(fp, "%d,%lf,%lf,%lf\n", &position->num, &position->x, &position->y,&position->z);
}

//出力関数
void output(int a, position position) {
	printf("%2d %8.2f %7.2f %7.2f  ", position.num, position.x, position.y,position.z);
}




//届くかどうか判断する。
int judge(int i, position position, int* p1, int* p2) {
	
	double a = position.x;
	double b = position.y;
	double c = position.z;
	double x ;//一番近い黒点のｘ
	double y=0;//一番近い黒点のy
	int dx=0;
	int dy=0;
	double ex=0;
	double ey=0;
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
	else if(a>=9000.0){
		x = 9000;
		//printf("  x=%lf  ", x);
	}else {
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
	f = (a - x)* (a - x) + (b - y)* (b - y) + (c-100)*(c-100);
	
	if (ex == 0 && ey == 0 && c == 0) {
		g = 0;
	}else if(f <= 810000) {
		g = 1;//届いた
	}else {
		g = 0;//届かない
	}

	p1[i] = x;
	p2[i] = y;
	//printf("%d %d", p1[i], p2[i]);
	
	return g;

}

//MDegの計算
void mdeg(int i, position position, int p1[], int p2[],double* p3) {
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
		mdeg =0.00;
	}
	else if ((b - y) > 0 && (a - x) < 0) {//第２象限
		mdeg=180+ atan((b - y) / (a - x)) / (M_PI) * 180;
	}
	else if ((b - y) < 0 && (a - x) < 0) {//第３象限
		mdeg = atan((b - y) / (a - x)) / (M_PI) * 180 - 180;

	}else{
		mdeg = atan((b - y) / (a - x)) / (M_PI) * 180;
	}
	
	//printf("%3.2f\n", mdeg);

	p3[i] = mdeg;
	//printf("%3.2f\n", p3[i]);
	return;
}

//A1deg,A2degの計算
void deg(int i, position position, int p1[], int p2[]) {
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
	
	ld = sqrt((a - x) * (a - x) + (b - y) * (b - y) + (c-100) * (c-100));
	//printf(" %.2f ", ld);
	
	
	ar = acos((l1 * l1 + ld*ld - l2 * l2) / (2 * l1 * ld))*180/M_PI;
	be = acos((l1 * l1 + l2 * l2 - ld*ld) / (2 * l1 * l2)) * 180 / M_PI;
	phi = atan((c - 100) / sqrt((a - x) * (a - x) + (b - y) * (b - y))) * 180 / M_PI;
	//printf(" %.2f %.2f %.2f\n", ar, be, phi);

	t1 =  - ar + phi;
	t2 = 180 - be;
	printf("  %.2f %.2f \n", t1, t2);

	return;
}



//リーチング順番選定
//リーチングは、各ポイントデータから最も近い黒点のx座標が小さい順で行う。x座標が等しい場合は、各ポイントデータから最も近い黒点のｙ座標を1000で割ったとき、その商が奇数のときはｙが小さい順、偶数の時は大きい順で行う。つまり商が奇数の時はy軸正の方向、偶数の時はy軸負の方向に進む。

void Swap(int** x, int** y) {//入れ替え

	int *c;
	c =*x;
	*x = *y;
	*y = c;
}

void Sort(int* p1,int* p2,int *p3,int k) {

	int* t1[k];//アドレスをそれぞれｔに格納
	int* t2[k];
	int* t3[k];
	int i;

	for (i = 0; i < k; i++) {
		//printf("  %d  %d", p1[i], p2[i]);
		//printf("  %d  %d", &p1[i], &p2[i]);
		t1[i] = &p1[i];
		t2[i] = &p2[i];
		t3[i] = &p3[i];
		//printf("  %d  %d", t1[i], t2[i]);
		printf("  %d  %d\n", *t1[i], *t2[i]);
		//printf("\n");
	}
	
	//printf("1");
	
	while (1) {

		int flag = 0;
		for (i = 0; i < k-1; i++) {//sort x
			if (*t1[i] > * t1[i + 1]) {
				flag = 0;
				Swap(t1[i], t1[i + 1]);
				Swap(t2[i], t2[i + 1]);
				Swap(t3[i], t3[i + 1]);
			}
		}
		for(int i = 0; i < k; i++){
			if(*t1[i] > *t1[i+1]) break;
			flag = 1;
		}
		if (flag) break;
	}

	while (1)
	{
		/* code */
		int flag = 0;//flag いらないせつ k*k回す妥当説
		for(int i = 0; i < k-1; i++){
			if ((*t1[i] - *t1[i + 1]) == 0 ) {
				//printf("2");
				flag = 0;
				int a;
				a = (*t1[i] / 1000) % 2;
				//printf("%d", a);
				if (a != 0) {//1000,3000,5000,7000,9000
					if (*t2[i] > * t2[i + 1]) {
						Swap(t1[i], t1[i + 1]);
						Swap(t2[i], t2[i + 1]);
						Swap(t3[i], t3[i + 1]);
					}
				}
				else {//2000,4000,6000,8000
					if (*t2[i] < * t2[i + 1]) {
						Swap(t1[i], t1[i + 1]);
						Swap(t2[i], t2[i + 1]);
						Swap(t3[i], t3[i + 1]);
					}
				}
			}
			else {
				//printf("3");
				flag = 1;
			}
		}

	}

}

//ログ用関数
void LOG(int* p1,int* p2,int k) {
	int j1=0;
	int j2 = 0;
	int x1;
	int y1;
	int x2;
	int y2;
	int a;
	int b;

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

						printf("( %4d, %4d )", x2, y1);
						printf("( %4d, %4d )\n", j2*1000,0);

					}
				
				    a = (y2 - y1) / 1000;

			        for (j2 = 0; j2 < a; j2++) {
					
					printf("( %d, %d )", x2, y1 + j2 * 1000);
					printf("( %d, %d )\n", x2 - x1, j2*1000);

				    }

					
				}else {//x繰り上がりなし
					//printf("  2  ");

					a = (y2 - y1) / 1000+1;

					for (j2 = 0; j2 < a; j2++) {

						printf("( %d, %d )", x2, y1 + j2 * 1000);
						printf("( %d, %d )\n", x2 - x1, j2 * 1000);

					}

				}
			}
			else {//最初以外

			
					x1 = p1[j1 - 1];
					y1 = p2[j1 - 1];
				
				
					x2 = p1[j1];
					y2 = p2[j1];
				

				printf("  %d  %d  %d  %d \n", x1, y1, x2, y2);

				if (x1 != x2) {//x繰り上がりあり

					printf("  3  ");

					b = (x2 - x1)/1000;

					for (j2 = 0; j2 < b; j2++) {

						printf("( %d, %d )", x1 + (j2+1) * 1000, y1);
						printf("( %d,   0 )\n", (j2+1) * 1000);

					}


					a = (y2 - y1) / 1000;
					//printf("  %d  ", a);

					if (a > 0) {

						for (j2 = 0; j2 < a; j2++) {

							printf("( %d, %d )", x2, y1 + (j2+1) * 1000);
							printf("(    0, %d )\n", (j2+1) * 1000);

						}
					}
					else {
						a = -1 * a;

						for (j2 = 0; j2 < a; j2++) {

							printf("( %d, %d )", x2, y1 - (j2+1) * 1000);
							printf("(    0, %d )\n", -1 * (j2 + 1) * 1000);

						}

					}


				}
				else {//x繰り上がりなし
					printf("  4  ");
					
					a = (y2 - y1) / 1000;
					//printf("  %d  ", a);

					if (a > 0) {

						for (j2 = 0; j2 < a; j2++) {

							printf("( %d, %d )", x2, y1 + j2 * 1000);
							printf("(    0, %d )\n", j2 * 1000);

						}
					}
					else {
						a = -1 * a;

						for (j2 = 0; j2 < a; j2++) {

							printf("( %d, %d )", x2, y1 - (j2+1) * 1000);
							printf("(    0, %d )\n", -1*(j2+1) * 1000);

						}

					}

				}

			}

		}

		break;

	}

	return;
}