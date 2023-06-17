//00:52:38; just realised it's a graph algorithm
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

const int MAXN = 2e1 + 10;
int t, r,c ;
ll dp[MAXN][MAXN], dpp[MAXN][MAXN];
char x[MAXN][MAXN];
bool mark[MAXN][MAXN];

ll hehe(int i, int j) {
    if (dp[i][j] != INF) return dp[i][j];
    ll a, b; a = b = -1;
    if (i && (x[i - 1][j] == '|' || x[i - 1][j] == '+'))
        a = hehe(i - 1, j);
    if (j && (x[i][j - 1] =='-' || x[i][j - 1] == '+'))
        b = hehe(i, j - 1);
    return dp[i][j] = min(a, b) + 1;
}

ll huehue(int i, int j) {
    if (dpp[i][j] != INF) return dpp[i][j];
    ll a, b; a = b = INF;
    if (i + 1 < r && !mark[i + 1][j] && (x[i - 1][j] == '+' || x[i - 1][j] == '|')) {
        mark[i + 1][j] = true;
        a = hehe(i + 1, j);
        mark[i + 1][j] = false;
    }
    if (j + 1 < c && !mark[i][j + 1] && (x[i][j + 1] =='+' || x[i][j + 1] == '-')) {
        mark[i][j + 1] = true;
        b = hehe(i, j + 1);
        mark[i][j + 1] = false;
    }
    return dpp[i][j] = min(min(a, b) + 1, dp[i][j]);
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i = 0; i < r; i ++) {
            for (int j  = 0; j < c; j ++) {
                cin >> x[i][j];
            }
            fill(dp[i], dp[i] + c, INF);
            fill(dpp[i], dpp[i] + c, INF);
            fill(mark[i], mark[i] + c, false);
        }
        dp[0][0] = 1;
        dp[r - 1][c - 1] = hehe(r - 1, c - 1);
        mark[r - 1][c - 1] = true;
        dpp[r - 1][c - 1] = huehue(r - 1, c - 1);
        if (dpp[r - 1][c - 1] >= INF)
            cout << "-1\n";
        else
            cout << dp[r - 1][c  - 1] << '\n';
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                cout << dpp[i][j] << " ";
            }
            cout << '\n';
        }
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