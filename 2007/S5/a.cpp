//00:21:25; done
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
 
const int MAXN = 3e4 + 10, MAXK = 5e2 + 10;
int t, a[MAXN];
ll psum[MAXN], dp[MAXN][MAXK][2];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s5.in", "r", stdin); freopen("s5.out", "w", stdout);
    cin >> t;
    int cnt = 0;
    while (t--) {
        int n, k, w;
        cin >> n >> k >> w;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            psum[i] = psum[i - 1] + a[i];
        }
        if (n <= w * k) {
            cout << psum[n] << '\n';
            continue;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= k; j ++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
                dp[i][j][1] = psum[i] - psum[max(0, i - w)] + (i > w? max(dp[i - w][j - 1][0], dp[i - w][j - 1][1]) : 0);
                cnt ++;
            }
        }
        cout << max(dp[n][k][0], dp[n][k][1]) << '\n';
    }
    return 0;
}
 
/*
    
*/