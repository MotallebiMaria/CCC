//00:38:09; done
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

const int MAXN= 2e1 + 10;
int t, r, c;
char x[MAXN][MAXN];
vector <pair <int, int>> v[MAXN][MAXN], cur, curp;
bool mark[MAXN][MAXN];
ll dfs[MAXN][MAXN];

void addHor(int i, int j) {
    if (j) v[i][j].pb(mp(i, j - 1));
    if (j + 1 < c) v[i][j].pb(mp(i, j + 1));
}

void addVer(int i, int j) {
    if (i) v[i][j].pb(mp(i - 1, j));
    if (i + 1 < r) v[i][j].pb(mp(i + 1, j));
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i = 0; i< r; i ++) {
            for (int j = 0; j < c; j ++) {
                cin >> x[i][j];
                v[i][j].clear();
            }
            fill(dfs[i], dfs[i] + c, -1);
            fill(mark[i], mark[i] + c, false);
        }
        for (int i =0; i < r; i ++) {
            for (int j =0; j < c; j ++) {
                if (x[i][j] == '+') {
                    addHor(i, j);
                    addVer(i, j);
                }
                else if (x[i][j] == '-') addHor(i, j);
                else if (x[i][j] == '|') addVer(i, j);
            }
        }
        dfs[0][0] = 1, mark[0][0] = true;
        cur.clear();
        cur.pb(mp(0,0));
        while (cur.size()) {
            curp.clear();
            for (int i = 0; i < cur.size(); i ++) {
                int a, b;
                a = cur[i].first, b = cur[i].second;
                for (int j = 0; j < v[a][b].size(); j ++) {
                    int c, d;
                    c = v[a][b][j].first, d = v[a][b][j].second;
                    if (mark[c][d]) continue;
                    dfs[c][d] = dfs[a][b] + 1;
                    curp.pb(v[a][b][j]);
                    mark[c][d] = true;
                }
            }
            // for (int i =0; i < curp.size(); i ++) {
            //     cout << curp[i].first << "-" << curp[i].second << " , ";
            // }
            // cout << '\n';
            cur = curp;
        }
        cout << dfs[r - 1][c - 1] << '\n';
    }
    return 0;
}
 
/*
    1
    3
    2
    -|
    |-
    --
*/