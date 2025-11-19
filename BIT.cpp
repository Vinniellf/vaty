#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359
#define F first
#define S second
#define int long long

typedef long double ld;


// Trabaja con index 0
struct Bit {
    int n; 
    vector<int> bit;
    Bit(int _n = 0) : n(_n), bit(n + 1) {}
    Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
        for(int i = 1; i <= n; i++) {
            bit[i] += v[i - 1];
            int j = i + (i & -i);
            if(j <= n) bit[j] += bit[i];
        }
    }

    void update(int i, int x) {
        for(i++; i <= n; i += i & -i) bit[i] += x;
    }

    int pref(int i) { //suma [0, i]
        int ret = 0;
        //Para index 1
        //for(i; i; i -= i & -i) ret += bit[i];
        for(++i; i; i -= i & -i) ret += bit[i];
        return ret;
    }

    int query(int l, int r) { //suma[l, r]
        return pref(r) - pref(l - 1);
    }

    int upper_bound(int x) {
        int p = 0;
        for(int i = __lg(n); i + 1; i--) {
            if(p + (1 << i) <= n && bit[p + (1<<i)] <= x) x -= bit[p += (1<<i)];
        }
        return p;
    }
};

void solve(){
    int n, q; cin>>n>>q;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    Bit bit(v);

    

}


int main(){
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}


