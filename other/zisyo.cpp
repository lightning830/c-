#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;
 
struct BIT{
private:
    vector<ll> a;
    int n;
public:
    BIT(int sz){
        n=sz;
        a.resize(sz+1);
    }
    ll sum(int i){
        ll res=0;
        while(i>0){
            res+=a[i];
            i-=i&-i;
        }
        return res;
    }
    ll sum(int i,int j){
        return sum(j)-sum(i-1);
    }
    void add(int i,ll x){//i番目にxを入れる
        while(i<=n){
            a[i]+=x;
            i+=i&-i;
        }
    }
};
 
int main(){
    int n;
    cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll fact[n];
    fact[0]=1;
    for(int i=1;i<n;++i){
        fact[i]=(fact[i-1]*i)%mod;
    }
    BIT bit(n);
    ll ans=0;
    rep(i,n){
        ans+=(a[i]-bit.sum(a[i])-1)*fact[n-1-i];
        ans%=mod;
        bit.add(a[i],1);
    }
    cout<<ans+1<<endl;
// 例として「35142」で考えてみる。
// 辞書順なので先頭から考えればよい。
// 35142の一桁目は3なので「一桁目が1,2の順列」よりも後ろになる。
// 「一桁目が1,2の順列」は2 * 4!通り。
// 次に、35142の二桁目は5なので、「一桁目が3かつ二桁目が4以下の順列」よりも
// 後ろになる。ここで注意しなければいけないのが、
// 二桁目のパターン数を考える際は既に使用した数は差し引いて考えることである。
// 具体的に言えば、4以下の数は本来1, 2, 3, 4の4通りであるが、
// 一桁目において3を既に使用しているため、二桁目のパターンは1,2,4の3通りとなり、
// 「一桁目が3かつ二桁目が4以下の順列」は(4-1) * 3!通りとなる。

//sum(4)だと4以下ですでに登場している数の和が返る。
//4はだめだけど4は自分だから数えられない
}