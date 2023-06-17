//00:11:59; done
//tle2, tle5; 
//00:09:31; solved (had to go from n to 1; should've listened to the hint)
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

const int MAXN = 1e4 + 10;
int n;
ll dp[MAXN];
vector <int> c[MAXN], p[MAXN], v, vp;

ll hehe(int ind) {
    if (dp[ind] != -1) return dp[ind];
    dp[ind] = 0;
    for (int i = 0; i < p[ind].size(); i ++) {
        dp[ind] += hehe(p[ind][i]);
    }
    return dp[ind];
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s4.in", "r", stdin); freopen("s4.out", "w", stdout);
    cin >> n;
    int a, b;
    cin >> a >> b;
    while (!(a == 0 && b == 0)) {
        p[b].pb(a);
        c[a].pb(b);
        cin >> a >> b;
    }
    fill(dp, dp + n + 1, -1);
    dp[1] = 1;
    for (int i = 1; i <= n; i ++) {
        dp[i] = hehe(i);
    }
    // v.pb(1);
    // while (v.size()) {
    //     vp.clear();
    //     for (int i = 0; i < v.size(); i ++) {
    //         for (int j = 0; j < c[v[i]].size(); j ++) {
    //             dp[c[v[i]][j]] += dp[v[i]];
    //             vp.pb(c[v[i]][j]);
    //         }
    //     }
    //     v = vp;
    // }
    cout << dp[n] << endl;
    return 0;
}
 
/*
    
*/