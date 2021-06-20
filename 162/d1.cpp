#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long int n;
  cin >> n;
  string s;
  cin >> s;
  long int r = 0;
  long int g = 0;
  long int b = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == 'R') r++;
    if(s[i] == 'G') g++;
    if(s[i] == 'B') b++;
  }
  long int sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 1; i+j+j < n; j++){
      if((s[i]^s[i+j]^s[i+j+j])==('R'^'G'^'B'))sum++;
    }
  }
  long int ans = r*g*b - sum;
  cout << ans << endl;
}
