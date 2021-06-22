#include<bits/stdc++.h>//全部includeしてくれる。おれはめんどくさいからいつもこうしてる
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)

#define HASHSIZE 17

template<class T> class Table{//クラス定義
    struct Node{//二分探索木構造体定義
        string key;//キー
        T value;//任意の型のキーに対する値
        Node* next;
    };
    struct Node* hashtable[HASHSIZE];
    int hash(string str);
public://ここ以降は外部からのアクセス可能。-=, (), insertを外部で使えるようにするため。
    Table();//コンストラクタ
    void operator-=(string s);//キーsのノードを削除する演算子オーバーロード(-=は演算子だから普通の関数定義はできない)
    void operator()(string s);//キーsのノードを確認する演算子オーバーロード(()も演算子)
    void insert(string s, T x);//キーsに任意の型のxを追加する関数
    ~Table(){};//デクストラクタ
};

template<class T> Table<T>::Table(){
    for(int i = 0; i < HASHSIZE; i++){
        hashtable[i] = NULL;
    }
}


template<class T> int Table<T>::hash(string str){
    const char* str_char = str.c_str();
    int n = 0;
    while(*str_char != '\0'){//strのasciiコードの和を計算
        n += *str_char;
        str_char++;
    }
    return abs(n%HASHSIZE);//modをとり値をhashsizeに収める
}

template<class T> void Table<T>::insert(string s, T x){
    //挿入するノードを作成する
    struct Node* tmp;
    tmp = new Node;//c++ではnewで自動的にメモリ確保してくれる
    tmp->key = s; tmp->value = x;
    int hash_num = hash(s);
    struct Node* p = hashtable[hash_num];
    if(p == NULL){
        p = tmp;
    }
    while(p != NULL){
        cout << "yeay" << endl;
        if(s.compare(p->key)){
            cout << "same" << endl;
            tmp->next = p->next;
            p->next = tmp;
            break;
        }else{
            cout << "No" << endl;
            p = p->next;
        }
    }
}


template<class T> void Table<T>::operator()(string s){

}

template<class T> void Table<T>::operator-=(string s){

}

int main() {
    Table<int> table;//値がintであるTable型tableを作成
    table.insert("abc", 9);//キーabc、値9のものを追加
    table.insert("bbc", 12);
    table.insert("ccc", 10);
    table.insert("aab", 132);
    table.insert("a", 2);
    table.insert("abb", 14);
    table.insert("abbc", 3);
    table.insert("abc", 10);
    // table("abb");//14 キーabbをtableから探索
    // table("abbc");//3
    // table-="aab";//キーaabをtableから削除
    // table-="aaaa";//nothing キーaaaaはないのでnothing
    // table("aab");//NOTHING キーaabは削除済みでないのでNOTHING
    // table-="bbc";
    // table("bbc");//NOTHING　キーbbcは削除済み
    // table("ccc");//10 キーcccを探索
    // cout << endl;

    // Table<string> table2;//同様に値がstring型であるTable型tableを作成して実行
    // table2.insert("abc", "zz");
    // table2.insert("aab", "tt");
    // table2.insert("abb", "ww");
    // table2.insert("ccc", "ee");
    // table2("abb");//ww
    // table2("ccc");//ee
    // table2-="abc";
    // table2("abc");//NOTHING
    // table2("abb");//ww


    return 0;
}