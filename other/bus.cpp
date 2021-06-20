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

P fast(INF, INF);//Å‘¬ŠÔ
vector<string> fast_st;//Å’ZŒo˜H
vector<string> fast_tr;


struct station
{
    /* data */
    string s;
    string r_trans;//ˆÚ“®•û–@
    string l_trans;
    int r_time;//ˆÚ“®ŠÔ
    int l_time;
    struct station* right;
    struct station* left;
};

struct transport
{
    /* data */
    string tr;//ˆÚ“®•û–@
    string station;//‰w
    string to;//‚ä‚«‚³‚«
    vector<int> times;//
    struct transport* next;
};

struct station* tree;
struct transport* trans;


P update(P n, int minute){//a‚ğminute‚·‚·‚Ü‚¹‚é
    if(n.second + minute < 60){
        n.second += minute;
    }else{
        n.first++;
        n.first += (n.second + minute - 60) / 60;//60minˆÈãi‚Ş‚Æ‚«
        if(n.first >= 24) n.first -= 24;//“ú•t‚ğ‚Ü‚í‚é‚Æ‚«
        n.second = (n.second + minute - 60)%60;//‚Ü‚í‚Á‚½‚ ‚Æ‚Ìmin
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
                cout << "   æ‚èŠ·‚¦Œã: " << t[n].first << ":" << t[n].second << endl;
                break;
            }
            if(n % 3 == 1){
                cout << "   o”­: " << t[n].first << ":" << t[n].second << endl;
            }
            if(n % 3 == 2){
                cout << "   “’…: " << t[n].first << ":" << t[n].second << endl;
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
            return P(((t.first+1 >= 24)? 0: t.first+1), p->times[0]);//Ÿ‚ÌŠÔ
        }
        p = p->next;
    }
    cout << "NO" << endl;
    return t;//‚±‚¤‚È‚é‚±‚Æ‚Í‚È‚¢‚Í‚¸
}

void print_fast(){
    cout << "--- Å‚à‘‚­XYZ‰w‚É‚Â‚­ƒ‹[ƒg‚Í ---" << endl;

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
        if(tr1.back() == v->r_trans){//‚Ì‚è‚©‚¦‚È‚µ
            t1.back() = update(t1.back(), v->r_time);//ŠÔ‚ğ‚¤‚í‚ª‚«
            st1.back() = r->s;//êŠ‚ğ‚¤‚í‚ª‚«
        }else{
            if(tr.back() != "S") t1.push_back(update(t.back(), transfer));//‚Ì‚è‚©‚¦ŠÔ
            t1.push_back(waiting(t1.back(), v->s, v->r_trans, r->s));//‚Ü‚¿ŠÔ
            t1.push_back(update(t1.back(), v->r_time));//ˆÚ“®ŠÔ
            tr1.push_back(v->r_trans);//Œğ’Ê–¼
            st1.push_back(r->s);//‰w‚Â‚¢‚©
        }
        if(r->s == "XYZ‰w"){
            fast_update(t1.back(), st1, tr1);
            print_way(t1, st1, tr1);
        }
        dfs(r, t1, st1, tr1);

    }
    if(l != NULL){
        if(tr2.back() == v->l_trans){//‚Ì‚è‚©‚¦‚È‚µ
            t2.back() = update(t2.back(), v->l_time);//ŠÔ‚ğ‚¤‚í‚ª‚«
            st2.back() = l->s;//êŠ‚ğ‚¤‚í‚ª‚«
        }else{
            if(tr.back() != "S") t2.push_back(update(t.back(), transfer));//‚Ì‚è‚©‚¦ŠÔ
            t2.push_back(waiting(t2.back(), v->s, v->l_trans, l->s));//‚Ü‚¿ŠÔ
            t2.push_back(update(t2.back(), v->l_time));//ˆÚ“®ŠÔ
            tr2.push_back(v->l_trans);//Œğ’Ê–¼
            st2.push_back(l->s);//‰w‚Â‚¢‚©
        }
        if(l->s == "XYZ‰w"){
            fast_update(t2.back(), st2, tr2);
            print_way(t2, st2, tr2);
        }
        dfs(l, t2, st2, tr2);
    }
    return;

}


void create_tree(){
    struct station* st1 = new station;
    *st1 = {"W‰w", "ƒoƒX", "ƒoƒX", 8, 27};
    struct station* st2 = new station; 
    *st2 = {"A’¬", "ƒoƒX", "ƒ‚ƒmƒŒ[ƒ‹", 30, 24};
    struct station* st3 = new station; 
    *st3 = {"B’¬", "’n‰º“S", "", 6};
    struct station* st4 = new station; 
    *st4 = {"XYZ‰w", "", ""};
    //st4 = {.s = "XYZ‰w", .r_trans = "‚È‚É‚©"}‚Æ‚·‚é‚±‚Æ‚à‚Å‚«‚é

    tree = st1;
    tree->right = st2;
    tree->left = st3;
    st2->right = st4;
    st2->left = st4;
    st3->right = st4;
}

void create_time(){
    //“¯‚¶Œ^‚¾‚©‚çvector‚Å‚Â‚È‚°‚½‚Ù‚¤‚ª‚«‚ê‚¢H
    struct transport* t1 = new transport; trans = t1;
    *t1 = {"ƒoƒX", "W‰w", "A’¬", busA};
    struct transport* t2 = new transport; t1->next = t2;
    *t2 = {"ƒoƒX", "W‰w", "B’¬", busB};
    struct transport* t3 = new transport; t2->next = t3;
    *t3 = {"ƒ‚ƒmƒŒ[ƒ‹", "A’¬", "XYZ‰w", mono};
    struct transport* t4 = new transport; t3->next = t4;
    *t4 = {"’n‰º“S", "B’¬", "XYZ‰w", sub};
}

void print_error(){
    cout << "“ü—ÍƒGƒ‰[:@³‚µ‚­“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
    cout << "[0-23] [0-59]•ª‚ÌŠÔ‚Ì”š‚ğ“ü‚ê‚Ä‚­‚¾‚³‚¢" << endl;
}

int main() {
    int hour, minute;
    while(1){
        cout << "w‘å‘O‚ÌƒoƒX’â‚É‰½‰½•ª‚É“’…‚µ‚Ü‚·‚©H ";
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