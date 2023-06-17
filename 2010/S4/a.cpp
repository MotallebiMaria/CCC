//
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

const int MAXN = 1e3 + 10;
int m, corner[MAXN], price[MAXN], e[MAXN][MAXN], mark[MAXN];
vector <int> p[MAXN][MAXN];
vector <pair <int, pair <int, int>>> v, vp, vpp;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> m;
    for (int i = 1; i <= m; i ++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j ++) cin >> corner[j];
        for (int j = 0; j < k; j ++) cin >> price[j];
        for (int j = 0; j < k - 1; j ++) {
            int a, b; a = corner[j], b = corner[(j + 1) % k];
            e[a][b] = e[b][a] = price[j];
            p[a][b].pb(i); p[b][a].pb(i);
        }
    }
    for (int i = 1; i <= 1e3; i ++) {
        for (int j = i + 1; j <= 1e3; j ++) {
            if (p[i][j].size() == 2) {
                v.pb(mp(e[i][j], mp(p[i][j][0], p[i][j][1])));
                vpp.pb(mp(e[i][j], mp(p[i][j][0], p[i][j][1])));
            }
            else if (p[i][j].size() == 1) {
                vp.pb(mp(e[i][j], mp(p[i][j][0], 0)));
                vpp.pb(mp(e[i][j], mp(p[i][j][0], 0)));
            }
        }
    }
    for (int i = 0; i < vp.size(); i ++) {
        for (int j = i + 1; j < vp.size(); j ++) {
            v.pb(mp(v[i].first + v[j].first, mp(vp[i].second.first, vp[j].second.first)));
        }
    }
    // gather inside:
    int ans = 0;
    sort(all(v));
    for (int i = 0; i < v.size(); i ++) {
        if (mark[v[i].second.first] + mark[v[i].second.second] <= 1) {
            ans += v[i].first;
            mark[v[i].second.first] = mark[v[i].second.second] = 1;
        }
    }
    // gather outside:
    int ansp = 0;
    sort(all(vpp));
    fill(mark, mark + m + 1, 0);
    for (int i = 0; i < vpp.size(); i ++) {
        if (mark[vpp[i].second.first] + mark[vpp[i].second.second] <= 1) {
            ansp += vpp[i].first;
            mark[vpp[i].second.first] = mark[vpp[i].second.second] = 1;
        }
    }
    for (int i = 1; i <= m; i ++) {

    }
    cout << ans << " " << ansp << endl;
    return 0;
}
 
/*
    
*/