// #include <iostream>
// #include <string>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  // このコードは標準入力と標準出力を用いたサンプルコードです。
  // このコードは好きなように編集・削除してもらって構いません。
  // ---
  // This is a sample code to use stdin and stdout.
  // Edit and remove this code as you like.

  string line;
  int index = 1;
  while (!cin.eof()) {
    getline(cin, line);//lineに1行分の文字列が格納される
    cout << "line[" << index++ << "]:" << line << "\n";
  }
  return 0;
}
