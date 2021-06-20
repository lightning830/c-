#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    string str1, str2;
    cin >> str1;
    int n = str1.size();
    str2 = str1;
    reverse(str2.begin(), str2.end());
    if(str1 == str2){
        string str3, str4;
        str3 = str1.substr(0, (n-1)/2);
        str4 = str3;
        reverse(str4.begin(), str4.end());
        if(str3 == str4){
            string str5, str6;
            str5 = str1.substr((n+3)/2-1);
            // cout << str5 << " " << str6 << endl;
            str6 = str5;
            reverse(str6.begin(), str6.end());
            if(str5 == str6) cout << "Yes" << endl;
            else cout << "No" << endl;

        }else cout << "No" << endl;
    }else cout << "No" << endl;
}