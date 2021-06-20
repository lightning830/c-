#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
    void printElems(const long* begin, const long* end)
    {
        for (const long* p = begin; p != end; ++p) {
            std::cout << *p << std::ends;
        }
        std::cout << std::endl;
    }
int main(){
    ifstream ifs("sub1_01.txt");
    int N;
    long long int K;
    ifs >> N >> K;
    long long int A[N];
    for(int i = 0; i < N; i++){
        ifs >> A[i];
    }

    long long int *B;
    B = (long long int *)malloc(N*N*sizeof(long long int)/2);
    
    int n = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            B[n] = A[i] * A[j];
            // cout << A[i] << '*' << A[j] << '=' << B[n] << '\n';
            n++;
        }
    }
    // for(int i = 0; i < N; i++){
    //     cout << A[i] << endl;
    // }
    // for(int i = 0; i < N*(N-1)/2; i++){
    //     cout << B[i] << endl;
    // }
    sort(B, B+N*(N-1)/2);
    // printElems(B, B+N*(N-1)/2);
    cout << B[K-1] << '\n';
    cout << "end" << endl;
    free(B);


}