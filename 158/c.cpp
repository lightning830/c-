#include<iostream>
#include<string.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int cost = 0;
    bool check = false;
    for(; cost <= 1250; cost++){
        // cout << "cost=" << cost <<
        //     " a=" << (int)(cost*0.08) << " " << a <<
        //      " b=" << (int)(cost*0.1) << " " << b << endl;
        if((int)(cost*0.08) == a && (int)(cost*0.1) == b){
            // cout << "here" << endl;
            check = true;
            break;
        }
    }
    cout << (check?cost : -1) << endl;
}