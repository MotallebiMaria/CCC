//00:20:45; why does it give -1??
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

const int MAXN = 5e1 + 10;
int t, r, c;
char x[MAXN][MAXN];
ll dp[MAXN][MAXN]; //0,0 to i,j
bool mark[MAXN][MAXN];

ll hehe(int i, int j) {
    if (dp[i][j] != INF) return dp[i][j];
    dp[i][j] = INF;
    if (i && !mark[i - 1][j] && (x[i - 1][j] == '+' || x[i - 1][j] == '|')) {
        mark[i][j] = true;
        dp[i][j] = min(hehe(i - 1, j) + 1, dp[i][j]);
        mark[i][j] = false;
    }
    if (j && !mark[i][j - 1] && (x[i][j - 1] == '+' || x[i][j - 1] == '-')) {
        mark[i][j] = true;
        dp[i][j] = min(hehe(i, j - 1) + 1, dp[i][j]);
        mark[i][j] = false;
    }
    if (i + 1 < r && !mark[i + 1][j] && (x[i - 1][j] == '+' || x[i - 1][j] == '|')) {
        mark[i][j] = true;
        dp[i][j] = min(hehe(i + 1, j) + 1, dp[i][j]);
        mark[i][j] = false;
    }
    if (j + 1 < c && !mark[i][j + 1] && (x[i][j + 1] =='+' || x[i][j + 1] == '-')) {
        mark[i][j] = true;
        dp[i][j] = min(hehe(i, j + 1) + 1, dp[i][j]);
        mark[i][j] = false;
    }
    return dp[i][j];
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> t;
    while (t --) {
        cin >> r >> c;
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                cin >> x[i][j];
                fill(dp[i], dp[i] + c + 1, -1);
                fill(mark[i], mark[i] + c + 1, false);
            }
        }
        dp[0][0] = 1;
        dp[r - 1][c - 1] = hehe(r - 1, c - 1);
        if (dp[r - 1][c - 1] != INF && dp[r - 1][c - 1])
            cout << dp[r - 1][c - 1] << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}
 
/*
    + east & south
    - east
    | south
    * blocked
*/