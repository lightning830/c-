#include<bits/stdc++.h>//全部includeしてくれる。おれはめんどくさいからいつもこうしてる
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)

template<class T> class Table{//クラス定義
    struct Node{//二分探索木構造体定義
        string key;//キー
        T value;//任意の型のキーに対する値
        // Node* parent;
        Node* left;//左方向の子
        Node* right;//右方向の子
    };
    Node* head;//二分探索木の頂点、ここを始点で木を作成
    Node* deleteNode(string s, Node* p);//ノードを削除する再起関数
    Node* successor(Node* p);//deleteNodeで使う。削除対象のノードの次に大きいノードのポインタを返す
public://ここ以降は外部からのアクセス可能。-=, (), insertを外部で使えるようにするため。
    Table(){head = NULL;}//コンストラクタ
    void operator-=(string s);//キーsのノードを削除する演算子オーバーロード(-=は演算子だから普通の関数定義はできない)
    void operator()(string s);//キーsのノードを確認する演算子オーバーロード(()も演算子)
    void insert(string s, T x);//キーsに任意の型のxを追加する関数
    ~Table(){};//デクストラクタ
};

template<class T> typename Table<T>::Node* Table<T>::successor(Node* p){
    Node* q = p;//このノードの次に大きいものを探す
    q = q->right;
    //あるノードの次に大きいということは、そのノードの右の子に行って、そこからずっと左の子をたどったもの
    while(q->left != NULL) q = q->left;
    return q;
}



template<class T> typename Table<T>::Node* Table<T>::deleteNode(string s, Node* p){
    if(p == NULL){//ないとき
        cout << "nothing" << endl;
        return NULL;
    }
    if(p->key > s){//削除対象が自身より小さければ、左部分木から削除する
        p->left = deleteNode(s, p->left);
    }else if(p->key < s){//削除対象が自身よりおおきければ、右部分木から削除する
        p->right = deleteNode(s, p->right);
    }else{//等しければ自身を削除する
        if(p->left == NULL && p->right == NULL) p = NULL;//子を持たない場合、自身をnullで置き換える
        else if(p->left == NULL || p->right == NULL){//子を一つ持つ場合自身をその子で置き換える
            if(p->right == NULL){delete p; p = p->left;}//いらないメモリはdeleteで開放できる
            else{delete p; p = p->right;}
        }else{//二つの子を持つ場合、自身をそのsuccessorの値で上書きし、元のsuccessorを削除する
            p->key = successor(p)->key;
            p->value = successor(p)->value;
            p->right = deleteNode(p->key, p->right);
        }
    }
    return p;
}

template<class T> void Table<T>::insert(string s, T x){
    //挿入するノードを作成する
    struct Node* tmp;
    tmp = new Node;//c++ではnewで自動的にメモリ確保してくれる
    tmp->left = NULL; tmp->right = NULL;
    tmp->key = s; tmp->value = x;

    //先頭ノードpで入れる場所まで探索
    Node* p = head;
    if(p == NULL){//head自体が空のときはそのまま代入
        head = tmp;
        return;
    }
    while(1){
        if(p->key < s){//右の子を探索
            if(p->right == NULL){//空だったときに挿入
                p->right = tmp;
                break;
            }
            p = p->right;
        }else{//左の子を探索
            if(p->left == NULL){
                p->left = tmp;
                break;
            }
            p = p->left;
        }
    }
}


template<class T> void Table<T>::operator()(string s){
    Node* p = head;//headを起点に探索
    cout << "search->" << s << endl;
    while(1){
        cout << "now->" << p->key << endl;//探索の様子を出力
        if(p->key == s){//見つけた場合それを出力
            cout << p->value << endl;
            return;
        }
        if(p->key < s){//右の子を探索
            if(p->right == NULL){//なかったらNOTHING
                cout << "NOTHING" << endl;
                return;
            }
            p = p->right;
        }else{//左の子を探索
            if(p->left == NULL){//なかったらNOTHING
                cout << "NOTHING" << endl;
                return;
            }
            p = p->left;
        }
    }

}

template<class T> void Table<T>::operator-=(string s){
    Node* p = head;
    //headを起点にしてキーsのノードを削除。再起関数を使いたかったからあえてdeleteNodeを作った
    deleteNode(s, p);
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
    table("abb");//14 キーabbをtableから探索
    table("abbc");//3
    table-="aab";//キーaabをtableから削除
    table-="aaaa";//nothing キーaaaaはないのでnothing
    table("aab");//NOTHING キーaabは削除済みでないのでNOTHING
    table-="bbc";
    table("bbc");//NOTHING　キーbbcは削除済み
    table("ccc");//10 キーcccを探索
    cout << endl;

    Table<string> table2;//同様に値がstring型であるTable型tableを作成して実行
    table2.insert("abc", "zz");
    table2.insert("aab", "tt");
    table2.insert("abb", "ww");
    table2.insert("ccc", "ee");
    table2("abb");//ww
    table2("ccc");//ee
    table2-="abc";
    table2("abc");//NOTHING
    table2("abb");//ww


    return 0;
}