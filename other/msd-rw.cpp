#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<fstream>
using namespace std;

#define PI     acos(-1.0)
#define DT     0.0001

int random_walk(){
    int x = rand();
    return x%2==0 ? 1:-1;
    // if(x%2==0) return 1;
    // else return -1;
    // と同じ
}

int main() {
    // ファイル出力するときは下のコメントアウトを使って，coutの箇所をfoutに変えればいい
    // ofstream fout;
    // fout.open("sample.txt");

    int T = pow(10,4);//1試行で何回運動をするか

    double d[T]; //位置を記憶
    for(int i=0; i<T; i++) d[i] = 0;
    
    srand(time(NULL)); //異なる乱数系列を生むよう設定
    for(int delta = 0; delta <= 100; delta++){
        int x = 0; // 初期位置
        for(int t = 1; t < T; t++){
            x += random_walk();
            d[t] = x;
            // cout << random_walk() << endl;
        }
        double s = 0;
        for(int i = 0; i < T-delta; i++){
            s += pow(d[i+delta]-d[i], 2);
            // cout << s << endl;
        } 

        double msd = s/(T-delta);
        cout << delta << ' ' << msd << endl;

    }

    // for(int i=0; i<T; i++) cout << d[i] << ' ';

    
}
