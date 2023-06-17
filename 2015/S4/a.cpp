//00:15:00; no idea
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9

const int MAXM = 1e4 + 10, MAXN = 2e3 + 10;
int k, n, m, src, dest;
vector <pair <pair <ll, ll>, int>> e[MAXM];
ll dp[MAXN][MAXN]; // time of src to i with h <= j
bool mark[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> k >> n >> m;
    for (int i = 1; i <= m; i ++) {
        fill(dp[i], dp[i] + k, INF);
    }
    for (int i = 1; i <= m; i ++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        e[a].pb(mp(mp(1ll *t, 1ll * h), b));
        e[b].pb(mp(mp(1ll *t, 1ll * h), a));
    }
    cin >> src >> dest;
    for (int i = 0; i < k; i ++) dp[src][i] = 0;
    queue <int> q; q.push(src);
    // cout << "about to start" << endl;
    while (q.size()) {
        int cur = q.front();
        // cout << cur << endl;
        q.pop();
        mark[cur] = false;
        for (int i = 0; i < e[cur].size(); i ++) {
            int num = e[cur][i].second;
            int curh = e[cur][i].first.second;
            int curt = e[cur][i].first.first;
            for (int j = 0; j + curh < k; j ++) {
                if (dp[cur][j] + curt < dp[num][j+ curh]) {
                    dp[num][j + curh] = dp[cur][j] + curt;
                    if (mark[num]) continue;
                    q.push(num);
                    mark[num] = true;
                }
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < k; i ++) {
        ans = min(ans, dp[dest][i]);
    }
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
 
/*
    
*/