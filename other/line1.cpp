#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    vector<string> v;                  
    string str, s;                      
    getline(cin,str);               
    stringstream ss{str};             
    while ( getline(ss, s, ' ') ){    
        v.push_back(s);
    }
    for (const string& s : v){        
        cout << s << endl;
    }

    return 0;
}