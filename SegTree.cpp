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
const int MAX = 2e5 + 5;

//0 - based
namespace seg {
    int seg[4*MAX], lazy[4*MAX];
    int n, *v;

    int build(int p = 1, int l = 0, int r = n - 1) {
        lazy[p] = 0;
        if(l == r) return seg[p] = v[l];
        int m = (l+r) / 2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }

    void build(int n2, int* v2){
        n = n2; v = v2;
        build();
    }

    void prop(int p, int l, int r) {
        seg[p] += lazy[p] * (r-l+1);
        if( l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
        lazy[p] = 0;
    }

    int query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if( a <= l && r <= b) return seg[p];
        if(b < l || r < a) return 0;
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p + 1, m+1, r);
    }

    //sumar en un rango[0, i];
    int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if(a <= l && r <= b){
            lazy[p] += x;
            prop(p, l, r);
            return seg[p];
        }

        if(b < l || r < a) return seg[p];
        int m = (l+r)/2;
        return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    seg::build(n, v.data());

}


signed main() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
