//01:15:22; done; 10/15
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

const int MAXN = 1e2 + 10;
int n, m, si, sj, ans[MAXN][MAXN];
char c[MAXN][MAXN];
bool mark[MAXN][MAXN], cam[MAXN][MAXN];
vector <pair <int, int>> v[MAXN][MAXN];

bool isConveyer(int x, int y) {
    return (c[x][y] == 'R' || c[x][y] == 'L' || c[x][y] == 'U' || c[x][y] == 'D');
}

void camCover(int x, int y) {
    for (int i = y; i < m - 1; i ++) {
        if (c[x][i] == 'W') break;
        if (!isConveyer(x, i)) 
            cam[x][i] = true;
    }
    for (int i = y; i > 0; i --) {
        if (c[x][i] == 'W') break;
        if (!isConveyer(x, i)) 
            cam[x][i] = true;
    }
    for (int i = x; i < n - 1; i ++) {
        if (c[i][y] == 'W') break;
        if (!isConveyer(i, y)) 
            cam[i][y] = true;
    }
    for (int i = x; i > 0; i --) {
        if (c[i][y] == 'W') break;
        if (!isConveyer(i, y)) 
            cam[i][y] = true;
    }
    return;
}

pair <int, int> convey(int x, int y) {
    int indi, indj; indi = x, indj = y;
    char cur = c[x][y];
    mark[x][y] = true;
    while(c[indi][indj] == cur) {
        if (cur == 'R') indj++;
        else if (cur == 'L') indj --;
        else if (cur == 'U') indi --;
        else indi ++;
    }
    if (c[indi][indj] != 'W' && !cam[indi][indj] && !(isConveyer(indi, indj) && mark[indi][indj])) {
        if (isConveyer(indi, indj)) return convey(indi, indj);
        return mp(indi, indj);
    }
    return mp(-1, -1);
}

void add(int x, int y, int parx, int pary) {
    if (!cam[x][y] && c[x][y] != 'W') {
        if (isConveyer(x, y)) {
            for (int k = 0; k < n; k ++) fill(mark[k], mark[k] + m, false);
            pair <int, int> dest = convey(x, y);
            if (dest != mp(-1, -1) && dest != mp(parx, pary))
                v[parx][pary].pb(dest);
        }
        else v[parx][pary].pb(mp(x, y));
    }
    return;
}

void solve() {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (c[i][j] == 'S') si = i, sj = j;
            else if (c[i][j] == 'C') {
                camCover(i, j);
            }
        }
    }
    // for (int i = 0; i < n; i ++) {
    //     for (int j = 0; j < m; j ++) {
    //         cout << cam[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i < n - 1; i ++) {
        for (int j = 1; j < m - 1; j ++) {
            if (isConveyer(i, j)) {
                for (int k = 0; k < n; k ++) fill(mark[k], mark[k] + m, false);
                pair <int, int> dest = convey(i, j);
                if (dest != mp(-1, -1)) v[i][j].pb(dest);
            }
            else if (c[i][j] == '.' || c[i][j] == 'S') {
                add(i, j + 1, i, j);
                add(i + 1, j, i, j);
                add(i, j - 1, i, j);
                add(i - 1, j, i, j);
            }
        }
    }
    // for (int i = 0; i < n; i ++) {
    //     for (int j = 0; j < m; j ++) {
    //         if (c[i][j] != '.' && !isConveyer(i, j)) continue;
    //         cout << i << " " << j << ": ";
    //         for (int k = 0; k < v[i][j].size(); k ++) {
    //             cout << v[i][j][k].first << " " << v[i][j][k].second << ", ";
    //         }
    //         cout << '\n';
    //     }
    // }
    vector <pair <int, int>> cur;
    cur.pb(mp(si, sj));
    ans[si][sj] = 0;
    while (cur.size()) {
        vector <pair <int, int>> curp;
        for (int i = 0; i < cur.size(); i ++) {
            int x, y; x = cur[i].first, y = cur[i].second;
            for (int j = 0; j < v[x][y].size(); j ++) {
                if (ans[v[x][y][j].first][v[x][y][j].second] > ans[x][y] + 1) {
                    // cout << "modified " << v[x][y][j].first << " " << v[x][y][j].second << '\n';
                    ans[v[x][y][j].first][v[x][y][j].second] = ans[x][y] + 1;
                    curp.pb(mp(v[x][y][j].first, v[x][y][j].second));
                }
            }
        }
        cur = curp;
    }
    return;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> c[i][j];
            ans[i][j] = INF;
        }
    }
    solve();
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (c[i][j] == '.') {
                // cout << i << " " << j << ": ";
                if (ans[i][j] == INF)
                    cout << "-1\n";
                else
                    cout << ans[i][j] << '\n';
            }
        }
    }
    cout << endl;
    return 0;
}
 
/*
    
*/