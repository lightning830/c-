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

P fast(INF, INF);//???????
vector<string> fast_st;//??Z?o?H
vector<string> fast_tr;


struct station
{
    /* data */
    string s;
    string r_trans;//??????@
    string l_trans;
    int r_time;//???????
    int l_time;
    struct station* right;
    struct station* left;
};

struct transport
{
    /* data */
    string tr;//??????@
    string station;//?w
    string to;//??????
    vector<int> times;//????
    struct transport* next;
};

struct station* tree;
struct transport* trans;


P update(P n, int minute){//a??minute?????????
    if(n.second + minute < 60){
        n.second += minute;
    }else{
        n.first++;
        n.first += (n.second + minute - 60) / 60;//60min???i????
        if(n.first >= 24) n.first -= 24;//???t????????
        n.second = (n.second + minute - 60)%60;//???????????min
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
                cout << "   ???????: " << t[n].first << ":" << t[n].second << endl;
                break;
            }
            if(n % 3 == 1){
                cout << "   ?o??????: " << t[n].first << ":" << t[n].second << endl;
            }
            if(n % 3 == 2){
                cout << "   ????????: " << t[n].first << ":" << t[n].second << endl;
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
            return P(((t.first+1 >= 24)? 0: t.first+1), p->times[0]);//???????
        }
        p = p->next;
    }
    cout << "NO" << endl;
    return t;//??????ч╖????????
}

void print_fast(){
    cout << "--- ???????XYZ?w???????[?g?? ---" << endl;

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
        if(tr1.back() == v->r_trans){//??Ми?????
            t1.back() = update(t1.back(), v->r_time);//???????????
            st1.back() = r->s;//??????????
        }else{
            if(tr.back() != "S") t1.push_back(update(t.back(), transfer));//??Ми??????
            t1.push_back(waiting(t1.back(), v->s, v->r_trans, r->s));//???????
            t1.push_back(update(t1.back(), v->r_time));//???????
            tr1.push_back(v->r_trans);//????
            st1.push_back(r->s);//?w?????
        }
        if(r->s == "XYZ?w"){
            fast_update(t1.back(), st1, tr1);
            print_way(t1, st1, tr1);
        }
        dfs(r, t1, st1, tr1);

    }
    if(l != NULL){
        if(tr2.back() == v->l_trans){//??Ми?????
            t2.back() = update(t2.back(), v->l_time);//???????????
            st2.back() = l->s;//??????????
        }else{
            if(tr.back() != "S") t2.push_back(update(t.back(), transfer));//??Ми??????
            t2.push_back(waiting(t2.back(), v->s, v->l_trans, l->s));//???????
            t2.push_back(update(t2.back(), v->l_time));//???????
            tr2.push_back(v->l_trans);//????
            st2.push_back(l->s);//?w?????
        }
        if(l->s == "XYZ?w"){
            fast_update(t2.back(), st2, tr2);
            print_way(t2, st2, tr2);
        }
        dfs(l, t2, st2, tr2);
    }
    return;

}


void create_tree(){
    struct station* st1 = new station;
    *st1 = {"W?w", "?o?X", "?o?X", 8, 27};
    struct station* st2 = new station; 
    *st2 = {"A??", "?o?X", "???m???[??", 30, 24};
    struct station* st3 = new station; 
    *st3 = {"B??", "?n???S", "", 6};
    struct station* st4 = new station; 
    *st4 = {"XYZ?w", "", ""};
    //st4 = {.s = "XYZ?w", .r_trans = "????"}????ч╖????????

    tree = st1;
    tree->right = st2;
    tree->left = st3;
    st2->right = st4;
    st2->left = st4;
    st3->right = st4;
}

void create_time(){
    //?????^??????vector?????????????????H
    struct transport* t1 = new transport; trans = t1;
    *t1 = {"?o?X", "W?w", "A??", busA};
    struct transport* t2 = new transport; t1->next = t2;
    *t2 = {"?o?X", "W?w", "B??", busB};
    struct transport* t3 = new transport; t2->next = t3;
    *t3 = {"???m???[??", "A??", "XYZ?w", mono};
    struct transport* t4 = new transport; t3->next = t4;
    *t4 = {"?n???S", "B??", "XYZ?w", sub};
}

void print_error(){
    cout << "????G???[:?@????????????????????" << endl;
    cout << "[0-23]?? [0-59]??????????????????????" << endl;
}

int main() {
    int hour, minute;
    while(1){
        cout << "w??O??o?X???????????????????????H ";
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