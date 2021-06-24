#include<bits/stdc++.h>//全部includeしてくれる。おれはめんどくさいからいつもこうしてる
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)

#define HASHSIZE 3

template<class T> class Table{//クラス定義
    struct Node{//二分探索木構造体定義
        string key;//キー
        T value;//任意の型のキーに対する値
        Node* next;
    };
    Node* hashtable[HASHSIZE];//ハッシュテーブルを定義
    int hash(string str);
public://ここ以降は外部からのアクセス可能。-=, (), insertを外部で使えるようにするため。
    Table();//コンストラクタ
    void check();//ハッシュテーブルのノードを列挙する関数、確認用
    void operator-=(string s);//キーsのノードを削除する演算子オーバーロード(-=は演算子だから普通の関数定義はできない)
    void operator()(string s);//キーsのノードを確認する演算子オーバーロード(()も演算子)
    void insert(string s, T x);//キーsに任意の型のxを追加する関数
    ~Table(){};//デクストラクタ
};

template<class T> Table<T>::Table(){//コンストラクタ定義
    for(int i = 0; i < HASHSIZE; i++){//全てのハッシュテーブルをNULLで初期化
        hashtable[i] = NULL;
    }
}

template<class T> void Table<T>::check(){
    for(int i = 0; i < HASHSIZE; i++){//全てのハッシュテーブルに対して
        cout << "---hashtable " << i << "---" << endl;
        //ハッシュテーブルがNULLになるまで出力して回る
        struct Node* p = hashtable[i];
        if(p==NULL){//存在しないとき
            cout << "NULL" <<endl;
        }
        while(p != NULL){//列挙
            cout << "key=" <<p->key << " value=" << p->value << endl;
            p = p->next;
        }
        cout << endl;
    }

}

template<class T> int Table<T>::hash(string str){
    const char* str_char = str.c_str();//string->const char変換
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
    tmp->key = s; tmp->value = x; tmp->next = NULL;//ノードに代入
    int hash_num = hash(s);//キーによってハッシュ値を求める
    struct Node* p = hashtable[hash_num];//ハッシュ値よりハッシュテーブルのポインタを用意
    if(p == NULL){//ハッシュテーブルがまだ何もないとき
        hashtable[hash_num] = tmp;//そのまま代入
        return;
    }
    while(1){//すでにあるときはキーがすでに存在するか探索
        if(!s.compare(p->key)){//存在したとき、valueを上書き
            p->value = x;
            delete tmp;
            return;
        }
        if(p->next == NULL){//ついそ存在しなかったとき、一番後ろにノードをつける
            p->next = tmp;
            return;
        }
        p = p->next;//次を探索
    }
}


template<class T> void Table<T>::operator()(string s){
    int hash_num = hash(s);
    struct Node* p = hashtable[hash_num];
    while(p != NULL){
        if(!s.compare(p->key)){//見つけたとき
            cout << p->value << endl;
            return;
        }
        p = p->next;
    }
}

template<class T> void Table<T>::operator-=(string s){
    int hash_num = hash(s);
    struct Node* p_pre = hashtable[hash_num];
    struct Node* p_now = hashtable[hash_num];
    p_now = p_now->next;

    if(p_pre == NULL) return;
    if(!s.compare(p_pre->key)){
        hashtable[hash_num] = p_now;
        delete(p_pre);
        return;
    }
    while(p_now != NULL){
        if(!s.compare(p_now->key)){//見つけたとき
            p_pre->next = p_now->next;
            delete(p_now);
            return;
        }
        p_now = p_now->next;
        p_pre = p_pre->next;
    }
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
    table.insert("abc", 10);//abcは10で上書きされる
    table("abb");//14 キーabbをtableから探索
    table("abbc");//3
    table("a");//2
    table.check();
    table-="aab";//キーaabをtableから削除
    table-="abc";
    table.check();
    // table("aab");//NOTHING キーaabは削除済みでないのでNOTHING
    // table-="bbc";
    // table("bbc");//NOTHING　キーbbcは削除済み
    // table("ccc");//10 キーcccを探索
    // cout << endl;

    Table<string> table2;//同様に値がstring型であるTable型tableを作成して実行
    table2.insert("abc", "zz");
    table2.insert("aab", "tt");
    table2.insert("abb", "ww");
    table2.insert("ccc", "ee");
    table2.check();

    table2("abb");//ww
    table2("ccc");//ee
    table2-="abc";
    table2("abc");//なにも返さない
    table2("abb");//ww
    table2.check();


    return 0;
}