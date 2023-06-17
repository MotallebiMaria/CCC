//00:18:37; done; 15/15
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

const int MAXN = 2e5 + 10;
int n, p[MAXN], w[MAXN], d[MAXN];

ll timegobrrr(ll pos) {
    ll out = 0;
    for (int i = 0; i < n; i ++) {
        ll dist = abs(pos - p[i]);
        out += w[i] * (dist - min(1ll * d[i], dist));
    }
    return out;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    ll l, r; l = INF; r = 0;
    for (int i = 0; i < n; i ++) {
        cin >> p[i] >> w[i] >> d[i];
        l = min(l, 1ll * p[i]), r = max(r, 1ll * p[i]);
    }
    ll lo, hi; lo = l, hi = r;
    while (hi - lo > 2) {
        ll m1 = lo + (hi - lo) / 3;
        ll m2 = hi - (hi - lo) / 3;
        ll f1 = timegobrrr(m1);
        ll f2 = timegobrrr(m2);
        if (f1 > f2) lo = m1;
        else if (f1 < f2) hi = m2;
        else lo = m1, hi = m2;
    }
    cout << min(timegobrrr(lo), min(timegobrrr(lo + 1), timegobrrr(hi))) << endl;
    return 0;
}
 
/*
    
*/