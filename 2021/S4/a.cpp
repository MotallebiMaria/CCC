//01:24:35; done; 15/15
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
 
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
int n, w, d, p[MAXN], ind[MAXN];
ll bfs[MAXN], way[MAXN];
vector <int> v[MAXN];
multiset <pair <ll, int>> ms; // shortest walkways to n

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> w >> d;
    for (int i = 0; i < w; i ++) {
        int a, b;
        cin >> a >> b;
        v[b].pb(a);
    }
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
        ind[p[i]] = i;
    }
    vector <int> cur;
    cur.pb(n);
    fill(bfs, bfs + n + 1, INF);
    bfs[n] = 0;
    while (cur.size()) {
        vector <int> curp;
        for (int i = 0; i < cur.size(); i ++) {
            for (int j = 0; j < v[cur[i]].size(); j ++) {
                if (bfs[v[cur[i]][j]] > bfs[cur[i]] + 1) {
                    bfs[v[cur[i]][j]] = bfs[cur[i]] + 1;
                    curp.pb(v[cur[i]][j]);
                }
            }
        }
        cur = curp;
    }
    for (int i = 1; i < n; i ++) {
        if (bfs[i] != INF) {
            way[i] = bfs[i] + ind[i] - 1;
            // cout << i << ": " << bfs[i] << " " << way[i] << '\n';
            ms.insert(mp(way[i], i));
        }
    }
    while (d --) {
        int x, y;
        cin >> x >> y;
        swap(ind[p[x]], ind[p[y]]);
        swap(p[x], p[y]);
        ll ans = ind[n] - 1;
        ans = min(ans, bfs[1]);
        ms.erase(mp(way[p[x]], p[x]));
        ms.erase(mp(way[p[y]], p[y]));
        way[p[x]] = bfs[p[x]] + ind[p[x]] - 1;
        way[p[y]] = bfs[p[y]] + ind[p[y]] - 1;
        ms.insert(mp(way[p[x]], p[x]));
        ms.insert(mp(way[p[y]], p[y]));
        ans = min(ans, (*ms.begin()).first);
        cout << ans << '\n';
    }
    return 0;
}
 
/*
    
*/