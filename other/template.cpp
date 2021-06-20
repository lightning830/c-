#include<iostream>
using namespace std;

template <class Number> 
Number twice(Number original){
    return original + original;
}

int main(){
    cout<<twice(3)<<'\n';
}