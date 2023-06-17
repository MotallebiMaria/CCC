//
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
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

const int MAXN = 2e3 + 10;
int n, m, r, c;
char ans[MAXN][MAXN];
vector <pair <int, int>> v[MAXN][MAXN];

bool rowpal(int row) {
    for (int i = 1; i <= m / 2; i ++) {
        if (ans[row][i] != ans[row][m - i + 1]) return false;
    }
    return true;
}

bool colpal(int col) {
    for (int i = 1; i <= n / 2; i ++) {
        if (ans[i][col] != ans[n - i + 1][col]) return false;
    }
    return true;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= r; i ++) {
        for (int j = 1; j <= m / 2; j ++) {
            v[i][j].pb(mp(i, m - j + 1));
        }
    }
    for (int i = 1; i <= c; i ++) {
        for (int j = 1; j <= n / 2; j ++) {
            v[j][i].pb(mp(n - j + 1, i));
        }
    }
    for (int i =1; i <= n; i ++) {
        fill(ans[i], ans[i] + m + 1, 'z');
        // for (int j = 1; j <= m; j ++)
    }
    char hehe = 'a';
    for (int i = 1; i <= r; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (ans[i][j] == 'z') {
                ans[i][j] = hehe;
                hehe ++;
                if (hehe == 'x') hehe = 'a';
            }
            for (int k = 0; k < v[i][j].size(); k ++) {
                ans[v[i][j][k].first][v[i][j][k].second] = ans[i][j];
            }
        }
    }
    for (int i = 1; i <= c; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (ans[j][i] == 'z') {
                // cout << "xgave " << j << " " << i << " " << hehe << '\n';
                ans[j][i] = hehe;
                hehe ++;
                if (hehe == 'x') hehe = 'a';
            }
            for (int k = 0; k < v[j][i].size(); k ++) {
                ans[v[j][i][k].first][v[j][i][k].second] = ans[j][i];
            }
        }
    }
    for (int i = r + 1; i <= n ;i ++) {
        int num = i % 3;
        hehe = 'x' + num;
        for (int j = c + 1; j <= m; j ++) {
            ans[i][j] = hehe;
            hehe ++;
            if (hehe == 'z' + 1) hehe = 'x';
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if ((i <= r && !rowpal(i)) || (j <= c && !colpal(j)) || (i > r && rowpal(i)) || (j > c && colpal(j))) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j =1; j <= m; j ++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    // for (int i = 1; i <= n; i ++) {
    //     int num = i % 26;
    //     char hehe = 'a' + num;
    //     for (int j = 1; j <= m; j ++) {
    //         if (i <= r || j <= c) ans[i][j] = 'a';
    //         else {
    //             ans[i][j] = hehe;
    //             hehe ++;
    //             if (hehe == 'z' + 1) hehe = 'b';
    //         }
    //     }
    // }
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    return 0;
}
 
/*
    
*/