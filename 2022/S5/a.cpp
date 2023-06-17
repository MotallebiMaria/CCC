//01:04:19 left 0/15
//00:53:45 left 0/15
//
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
 
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
int n, c[MAXN], cnt[MAXN];
bool mark[MAXN];
vector <int> v[MAXN];
multiset <pair <double, int>> s, sp;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b); v[b].pb(a);
    }
    int cnty = 0;
    for (int i = 1; i <= n; i ++) {
        char x;
        cin >> x;
        mark[i] = (x == 'Y');
        cnty += mark[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            if (!mark[v[i][j]]) cnt[i] ++;
        }
        if (!cnt[i] || !mark[i]) continue;
        // cout << i << ": " << cnt[i] << '\n';
        s.insert(mp((double)c[i] / cnt[i], i));
    }
    ll ans = 0;
    while (cnty < n) {
        pair <double, int> cur = (*s.begin());
        s.erase(cur);
        // cout << cur.second << " ";
        ans += c[cur.second];
        for (int i = 0; i < v[cur.second].size(); i ++) {
            int num = v[cur.second][i];
            if (mark[num]) continue;
            mark[num] = true, cnty ++;
            if (cnt[num])
                s.insert(mp((double)c[num] / cnt[num], num));
            for (int j = 0; j < v[num].size(); j ++) {
                int ind = v[num][j];
                if (!(mark[ind] && cnt[ind])) continue;
                s.erase(mp((double)c[ind] / cnt[ind], ind));
                cnt[ind] --;
                s.insert(mp((double)c[ind] / cnt[ind], ind));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/