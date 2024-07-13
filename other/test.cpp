// ブラウン運動の平均二乗変位
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<fstream>
using namespace std;

#define PI     acos(-1.0)
#define DT     0.0001

int main() {
    int     i,N;
    double  X,Y,dw;
    double  x,y,D;
    double  k;

    // ファイル出力するときは下のコメントアウトを使って，coutの箇所をfoutに変えればいい
    // ofstream fout;
    // fout.open("sample.txt");

    N = pow(10,4);//1試行で何回ブラウン運動をするか
    double msd[N+10];
    for(int i=0; i<N+10; i++) msd[i] = 0;
    
    srand(time(NULL)); //異なる乱数系列を生むよう設定
    
    int M = 10;//試行回数
    
    for(int j=0; j<M; j++){//M回試行する
        x   = 0.;
        y   = 0.;
        D   = 1.;
        k   = 2.;
    
        for (i=1; i<=N; i++){//N時間ブラウン運動をする
            
            X = ((double)rand())/((double)RAND_MAX);
            Y = ((double)rand())/((double)RAND_MAX);
            dw = sqrt(2.0 * D * DT) * pow(-2.*log(X),0.5)*cos(2*PI*Y); //white gaussian
            if(!isinf(dw)) x = x - k * x * DT + dw;//現在のx座標
            
            X = ((double)rand())/((double)RAND_MAX);
            Y = ((double)rand())/((double)RAND_MAX);
            dw = sqrt(2.0 * D * DT) * pow(-2.*log(X),0.5)*cos(2*PI*Y); //white gaussian

            if(!isinf(dw)) y = y - k * y * DT + dw;//現在のy座標

            msd[i] += x*x+y*y;//時間iにおける二乗変位をすべての試行分加算．（後でMで割るため問題なし）
        }
    
    }
    for(int i=0; i<=N; i++) cout << i * (double)DT << " " << msd[i]/M << endl;//Mで割って平均にする（平均二乗変位）
}
