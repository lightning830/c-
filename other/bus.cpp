#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

const int transfer = 1;
const vector<int> busA{3, 12, 19, 25, 32, 39, 44, 51, 57};
const vector<int> busB{18, 41, 52};
const vector<int> mono{5, 15, 25, 35, 45, 55};
const vector<int> sub{4, 17, 31, 48};

P fast(INF, INF);//最速時間
vector<string> fast_st;//最短経路
vector<string> fast_tr;


struct station
{
    /* data */
    string s;
    string r_trans;//移動方法
    string l_trans;
    int r_time;//移動時間
    int l_time;
    struct station* right;
    struct station* left;
};

struct transport
{
    /* data */
    string tr;//移動方法
    string station;//駅
    string to;//ゆきさき
    vector<int> times;//時刻
    struct transport* next;
};

struct station* tree;
struct transport* trans;


P update(P n, int minute){//aをminuteすすませる
    if(n.second + minute < 60){
        n.second += minute;
    }else{
        n.first++;
        n.first += (n.second + minute - 60) / 60;//60min以上進むとき
        if(n.first >= 24) n.first -= 24;//日付をまわるとき
        n.second = (n.second + minute - 60)%60;//まわったあとのmin
    }
    return n;
}

void print_way(vector<P> t, vector<string> st, vector<string> tr){
    cout << "*** ";
    rep(i, st.size()-1){
        cout << st[i] << " -" << tr[i+1] << "-> "; 
    }
    cout << st[st.size()-1] << " ***" << endl;

    int n = 0;
    rep(i, tr.size()-1){
        cout << tr[i+1] << ": " << st[i] << " -> " << st[i+1] << endl;
        n++;
        for(; n < t.size(); n++){
            if(n % 3 == 0){
                cout << "   乗り換え後: " << t[n].first << ":" << t[n].second << endl;
                break;
            }
            if(n % 3 == 1){
                cout << "   出発時刻: " << t[n].first << ":" << t[n].second << endl;
            }
            if(n % 3 == 2){
                cout << "   到着時刻: " << t[n].first << ":" << t[n].second << endl;
            }
        }
    }



    // for(auto&i : t){
    //     cout << i.first << ":" << i.second << " ";
    // }
    // cout << endl;
    // for(auto&i : st){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(auto&i : tr){
    //     cout << i << " ";
    // }
    cout << endl << endl;
}

P waiting(P t, string st, string tr, string to){
    struct transport* p = trans;
    while(p != NULL){
        // cout << st << p->station << " " << tr << p->tr << endl;
        if(st == p->station && tr == p->tr && to == p->to){
            for(auto& x: p->times){
                if(x >= t.second){
                    // cout << t.first << "^" << x << endl;
                    return P(t.first, x);
                } 

            }
            return P(((t.first+1 >= 24)? 0: t.first+1), p->times[0]);//次の時間
        }
        p = p->next;
    }
    cout << "NO" << endl;
    return t;//こうなることはないはず
}

void print_fast(){
    cout << "--- 最も早くXYZ駅につくルートは ---" << endl;

    cout << "*** ";
    // cout << fast_st.size() << " " << fast_tr.size() << endl;
    rep(i, fast_st.size()-1){
        cout << fast_st[i] << " -" << fast_tr[i+1] << "-> "; 
    }
    cout << fast_st[fast_st.size()-1] << " ***" << endl;
}

void fast_update(P t, vector<string> st, vector<string> tr){
    if(fast.first > t.first){
        fast = t; fast_st = st; fast_tr = tr;
    }
    else if(fast.first == t.first && fast.second > t.second){
        fast = t; fast_st = st; fast_tr = tr;
    }
}

void dfs(struct station* v, vector<P> t, vector<string> st, vector<string> tr){
    struct station* r = v->right;
    struct station* l = v->left;
    vector<string> st1 = st;
    vector<string> st2 = st;
    vector<P> t1 = t;
    vector<P> t2 = t;
    vector<string> tr1 = tr;
    vector<string> tr2 = tr;
    
    if(r != NULL){
        if(tr1.back() == v->r_trans){//のりかえなし
            t1.back() = update(t1.back(), v->r_time);//時間をうわがき
            st1.back() = r->s;//場所をうわがき
        }else{
            if(tr.back() != "S") t1.push_back(update(t.back(), transfer));//のりかえ時間
            t1.push_back(waiting(t1.back(), v->s, v->r_trans, r->s));//まち時間
            t1.push_back(update(t1.back(), v->r_time));//移動時間
            tr1.push_back(v->r_trans);//交通名
            st1.push_back(r->s);//駅ついか
        }
        if(r->s == "XYZ駅"){
            fast_update(t1.back(), st1, tr1);
            print_way(t1, st1, tr1);
        }
        dfs(r, t1, st1, tr1);

    }
    if(l != NULL){
        if(tr2.back() == v->l_trans){//のりかえなし
            t2.back() = update(t2.back(), v->l_time);//時間をうわがき
            st2.back() = l->s;//場所をうわがき
        }else{
            if(tr.back() != "S") t2.push_back(update(t.back(), transfer));//のりかえ時間
            t2.push_back(waiting(t2.back(), v->s, v->l_trans, l->s));//まち時間
            t2.push_back(update(t2.back(), v->l_time));//移動時間
            tr2.push_back(v->l_trans);//交通名
            st2.push_back(l->s);//駅ついか
        }
        if(l->s == "XYZ駅"){
            fast_update(t2.back(), st2, tr2);
            print_way(t2, st2, tr2);
        }
        dfs(l, t2, st2, tr2);
    }
    return;

}


void create_tree(){
    struct station* st1 = new station;
    *st1 = {"W駅", "バス", "バス", 8, 27};
    struct station* st2 = new station; 
    *st2 = {"A町", "バス", "モノレール", 30, 24};
    struct station* st3 = new station; 
    *st3 = {"B町", "地下鉄", "", 6};
    struct station* st4 = new station; 
    *st4 = {"XYZ駅", "", ""};
    //st4 = {.s = "XYZ駅", .r_trans = "なにか"}とすることもできる

    tree = st1;
    tree->right = st2;
    tree->left = st3;
    st2->right = st4;
    st2->left = st4;
    st3->right = st4;
}

void create_time(){
    //同じ型だからvectorでつなげたほうがきれい？
    struct transport* t1 = new transport; trans = t1;
    *t1 = {"バス", "W駅", "A町", busA};
    struct transport* t2 = new transport; t1->next = t2;
    *t2 = {"バス", "W駅", "B町", busB};
    struct transport* t3 = new transport; t2->next = t3;
    *t3 = {"モノレール", "A町", "XYZ駅", mono};
    struct transport* t4 = new transport; t3->next = t4;
    *t4 = {"地下鉄", "B町", "XYZ駅", sub};
}

void print_error(){
    cout << "入力エラー:　正しく入力してください" << endl;
    cout << "[0-23]時 [0-59]分の間の数字を入れてください" << endl;
}

int main() {
    int hour, minute;
    while(1){
        cout << "w大前のバス停に何時何分に到着しますか？ ";
        cin >> hour >> minute;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n');
            print_error();
            continue;
        }
        if(0 <= hour && hour < 24 && 0 <= minute && minute <= 59){
            break;
        }else print_error();
    }
    create_tree();
    create_time();
    P now = make_pair(hour, minute);
    vector<P> stock;
    stock.push_back(now);
    vector<string> st;
    st.push_back(tree->s);
    vector<string> tr;
    tr.push_back("S");
    // P a = update(now, 45);
    // cout << a.first << " " << a.second << endl;
    // cout << now.first << " " << now.second << endl;


    dfs(tree, stock, st, tr);
    print_fast();
    // for(auto&i : trans->next->times){
    //     cout << i << endl;
    // }
    // cout << trans->next->times << endl;
    // cout << tree->right->l_trans << endl;

    return 0;
}