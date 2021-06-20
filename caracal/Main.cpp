#include <iostream>
using namespace std;
int main(){
    long H;
    cin >> H;

    long i;
    for(i=(long)0;;i++){
        H=H/2;
        if(H<=1)break;
    }
    long n = 1;
    for(long j = (long)0; j <= i; j++){
        n = n * 2;
    }
    long *Hs;
    Hs = (long*)malloc(n * sizeof(long));
    Hs = new long[n]; 
    cout<<n<<endl;
}