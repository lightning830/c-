#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

template<class T>
class Table{
public:
    string key;
    T obj;
    Table *left;
    Table *right;

    void operator-=(string s);
    void operator()(string s);
    void insert(string s, T x);
};

template<class T>
void Table<T>::insert(string s, T x){
    this->key = s;
    this->obj = x;
}

int main() {
    // string s,t;
    // cin >> s >> t;
    // if(s > t) cout << s << ">" << t << endl;
    // else cout << s << "<" << t << endl;
    Table<int> table;
    table.insert("abc", 8);
    Table<string> table2;
    table2.insert("aaa", "fuck");
    table.left = table2;
    cout << table.left->key << " " << table.left->obj << endl;



    return 0;
}