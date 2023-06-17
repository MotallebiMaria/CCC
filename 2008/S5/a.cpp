//-00:57:14; done
//solved
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

const int MAXN = 3e1 + 10;
int n;
string dp[MAXN][MAXN][MAXN][MAXN][2];
int cnt[5][4] = {2, 1, 0, 2, 1, 1, 1, 1, 0, 0, 2, 1, 0, 3, 0, 0, 1, 0, 0, 1};

bool can(int a, int b, int c, int d, int ind) {
    if (a < cnt[ind][0]) return false;
    if (b < cnt[ind][1]) return false;
    if (c < cnt[ind][2]) return false;
    if (d < cnt[ind][3]) return false;
    return true;
}

string hehe(int a, int b, int c, int d, int turn) {
    if (dp[a][b][c][d][turn] != "hehe") return dp[a][b][c][d][turn];
    if (!a && !b && !c && !d) {
        if (turn) return dp[a][b][c][d][turn] = "Patrick";
        return dp[a][b][c][d][turn] = "Roland";
    }
    bool cw = false;
    string win = "Patrick";
    if (turn) win = "Roland";
    for (int i = 0; i < 5; i ++) {
        if (can(a, b, c, d, i) && hehe(a - cnt[i][0], b - cnt[i][1], c - cnt[i][2], d - cnt[i][3], turn ^ 1) == win) {
            cw = true;
            break;
        }
    }
    if (cw) {
        if (turn) return dp[a][b][c][d][turn] = "Roland";
        return dp[a][b][c][d][turn] = "Patrick";
    }
    if (turn) return dp[a][b][c][d][turn] = "Patrick";
    return dp[a][b][c][d][turn] = "Roland";
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s5.in", "r", stdin); freopen("s5.out", "w", stdout);
    for (int a = 0; a <= 30; a ++) {
        for (int b = 0; b <= 30; b ++) {
            for (int c = 0; c <= 30; c ++) {
                for (int d = 0; d <= 30; d ++) {
                    dp[a][b][c][d][0] = dp[a][b][c][d][1] = "hehe";
                }
            }
        }
    }
    dp[0][0][0][0][0] = "Roland";
    dp[0][0][0][0][1] = "Patrick";
    cin >> n;
    while (n --) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        dp[a][b][c][d][0] = hehe(a, b, c, d, 0);
        cout << dp[a][b][c][d][0] << '\n';
    }
    return 0;
}
 
/*
    
*/