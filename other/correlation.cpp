#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<fstream>
using namespace std;

#define PI     acos(-1.0)
#define DT     0.0001

int main() {
    int N = pow(10, 1);

    // 読み込み
    ifstream ifs("./data.txt");
    int buf_size = 81;
    char str[buf_size];
    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        return -1;
    }
    double a[100];
    int i = 0;
    while(ifs >> a[i]){
        i++;
    }
    // for(int i=0; i<10; i++) cout << a[i] << ' ';

    // 平均
    double ave = 0;
    for(int i=0; i<N; i++){
        ave+=a[i];
    }
    ave /= N;
    // cout << "ave=" << ave << endl;

    // 左の項を求めて平均の二乗を引く
    for(int n=0; n<100; n++){
        double xx = 0;
        for(int i=0; i<N-n; i++){
            xx += a[i]*a[i+n];
        }
        xx /= double(N-n);

        double c = xx-ave*ave;
        cout << n << " " << c << endl;
    }


    return 0;
    
    
}
