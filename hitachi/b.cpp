#include<iostream>
#include<algorithm>
#include<string>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
int main(){
    int A, B, M;
    cin >> A >> B >> M;
    int a[A], b[B];

    int minA, minB;
    cin >> a[0];
    minA = a[0];
    for(int i = 1; i < A; i++){
        cin >> a[i];
        if(minA > a[i]) minA = a[i];
    }
    cin >> b[0];
    minB = b[0];
    for(int i = 1; i < B; i++){
        cin >> b[i];
        if(minB > b[i]) minB = b[i];
    }

    int dismin;
    int x[M], y[M], c[M];
    cin >> x[0] >> y[0] >> c[0];
    dismin = a[x[0]-1] + b[y[0]-1] - c[0];
    for(int i = 1; i < M; i++){
        cin >> x[i] >> y[i] >> c[i];
        int dismin1 = a[x[i]-1] + b[y[i]-1] - c[i];
        if(dismin > dismin1) dismin = dismin1;
    }



    cout << ((minA + minB) > dismin? dismin: (minA + minB)) << endl;


}