//00:59:55
//gave up
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
 
const int MAXN = 1e2 + 10;
int m, n, val[MAXN][MAXN], dp[MAXN][MAXN][5];

int hehe(int x, int y, int z) { // z = last move from: 0:up 1:left 2:down
    if (val[x][y] == -1 || x < 0 || x >= m || y < 0 || y >= n)
        return -1;
    if (z == 0) {
        if (dp[x - 1][y][0] == -2)
            dp[x - 1][y][0] = hehe(x - 1, y, 0);
        if (dp[x - 1][y][1] == -2)
            dp[x - 1][y][1] = hehe(x - 1, y, 1);
        if (dp[x - 1][y][2] == -2)
            dp[x - 1][y][2] = hehe(x - 1, y, 2);
        int num = max(dp[x - 1][y][0], max(dp[x - 1][y][1], dp[x - 1][y][2]));
        return num + val[x][y];
    }
    if (z == 1) {
        if (dp[x][y - 1][0] == -2)
            dp[x][y - 1][0] = hehe(x, y - 1, 0);
        if (dp[x][y - 1][1] == -2)
            dp[x][y - 1][1] = hehe(x, y - 1, 1);
        if (dp[x][y - 1][2] == -2)
            dp[x][y - 1][2] = hehe(x, y - 1, 2);
        int num = max(dp[x][y - 1][0], max(dp[x][y - 1][1], dp[x][y - 1][2]));
        return num + val[x][y];
    }
    if (dp[x + 1][y][0] == -2)
        dp[x + 1][y][0] = hehe(x + 1, y, 0);
    if (dp[x + 1][y][1] == -2)
        dp[x + 1][y][1] = hehe(x + 1, y, 1);
    if (dp[x + 1][y][2] == -2)
        dp[x + 1][y][2] = hehe(x + 1, y, 2);
    int num = max(dp[x + 1][y][0], max(dp[x + 1][y][1], dp[x + 1][y][2]));
    return num + val[x][y];
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> m >> n;
    if (n == 0 && m == 0) return 0;
    for (int i = m - 1; i >= 0; i --) {
        for (int j = 0; j < n; j ++) {
            char c;
            cin >> c;
            if (c == '*') val[i][j] = -1;
            else if (c == '.') val[i][j] = 0;
            else val[i][j] = c - '0';
        }
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n;j ++) {
            fill(dp[i][j], dp[i][j] + 3, -2);
        }
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            dp[i][j][0] = hehe(i, j, 0);
            dp[i][j][1] = hehe(i, j, 1);
            dp[i][j][2] = hehe(i, j, 2);
        }
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            int tot = max(dp[i][j][0], max(dp[i][j][1], dp[i][j][2]));
            cout << tot << " ";
        }
        cout << '\n';
    }
    int ans = max(dp[0][n - 1][0], max(dp[0][n - 1][1], dp[0][n - 1][2]));
    cout << ans << endl;
    main();
}
 
/*
    
*/