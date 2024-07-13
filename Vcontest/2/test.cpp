#include<iostream>
#include<string>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;

  if(s == "+"){
    cout << a + b << endl;
  }else if(s == "-"){
    cout << a - b << endl;
  }else if(s == "*"){
    cout << a * b << endl;
  }else if(s == "/"){
    cout << a / b << endl;
  }else{
    cout << "wrong IN" << endl;
  }

  return 0;
}
