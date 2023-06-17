//00:45:54
//00:50:45; bruh
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
 
const int MAXN = 1e5 + 10;
int n, m, pho[MAXN], bfs[MAXN], par[MAXN];
bool mark[MAXN];
vector <int> v[MAXN], cur, curp, vp[MAXN], path;
vector <pair <int, int >> maxp;

pair <int, int> hehe(int cnt, int x) {
    if (v[x].empty()) return mp(cnt, x);
    pair <int, int> out = mp(cnt, x);
    for (int i = 0; i < v[x].size(); i ++) {
        if (v[x][i] == par[x]) continue;
        pair <int, int> num = hehe(v[x][i], cnt + 1);
        if (num.second > out.second)
            out = num;
    }
    return out;
}

int gothrough(int ver, int prev) {
    int out = 0;
    for (int i = 0; i < v[ver].size(); i ++) {
        if (v[ver][i] != prev && v[ver][i] != par[ver]) {
            out += gothrough(v[ver][i], ver);
        }
    }
    return out;
} 
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> pho[i];
    }
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b); v[b].pb(a);
    }
    fill(bfs, bfs + n, INF);
    cur.pb(pho[0]);
    bfs[pho[0]] = 0, par[pho[0]] = pho[0];
    while (cur.size()) {
        curp.clear();
        for (int i = 0; i < cur.size(); i ++) {
            for (int j = 0; j < v[cur[i]].size(); j ++) {
                if (bfs[v[cur[i]][j]] > bfs[cur[i]] + 1) {
                    curp.pb(v[cur[i]][j]);
                    bfs[v[cur[i]][j]] = bfs[cur[i]] + 1;
                    par[v[cur[i]][j]] = cur[i];
                }
            }
        }
        cur = curp;
    }
    for (int i = 1; i < m; i ++) {
        int ver = pho[i];
        while (!mark[ver]) {
            mark[ver] = true;
            ver = par[ver];
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            if (mark[v[i][j]])
                vp[i].pb(v[i][j]);
        }
        v[i] = vp[i];
    }
    maxp.pb(mp(0, pho[0]));
    for (int i = 0; i < v[pho[0]].size(); i ++) {
        maxp.pb(hehe(1, v[pho[0]][i]));
    }
    sort(all(maxp));
    int l, r; l = maxp[0].second, r = maxp[1].second;
    fill(bfs, bfs + n, INF);
    cur.clear(); cur.pb(pho[0]);
    bfs[l] = 0, par[l] = l;
    while (cur.size()) {
        curp.clear();
        for (int i = 0; i < cur.size(); i ++) {
            for (int j = 0; j < v[cur[i]].size(); j ++) {
                if (bfs[v[cur[i]][j]] > bfs[cur[i]] + 1) {
                    curp.pb(v[cur[i]][j]);
                    bfs[v[cur[i]][j]] = bfs[cur[i]] + 1;
                    par[v[cur[i]][j]] = cur[i];
                }
            }
        }
        cur = curp;
    }
    int ver = r;
    while (ver != l) {
        path.pb(ver);
        ver = par[ver];
    }
    int ans = 0;
    for (int i = 0; i < path.size(); i ++) {
        ans += 1 + gothrough(path[i], (i? i - 1: -1));
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/