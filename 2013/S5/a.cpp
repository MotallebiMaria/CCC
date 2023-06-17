//00:19:00
//00:25:19; ik it'll get tle but ahhh; 6/15 less gooo
//00:14:14
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

const int MAXN = 5e6 + 10;
int n; // f[MAXN];
// ll dp[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    int cost = 0;
    while (n > 1) {
        // cout << n << '\n';
        int i = n - 1;
        while (n % i) i --;
        if (i == 1) n --, cost += n;
        else n -= i, cost += n / i;
    }
    cout << cost << endl;
    // fill(dp, dp + n + 1, INF);
    // for (int i = 2; i * i <= n; i ++) {
    //     if (f[i] == i) {
    //         for (int j = i * i; j <= n; j += i) {
    //             f[j] = min(f[j], i);
    //         }
    //     }
    // }
    // for (int i = 2; i <= n ; i ++) {
    //     int x = sqrt(i);
    //     dp[i] = min(dp[x])
    // }
    // cout << dp[n] << endl;
    return 0;
}
 
/*
    
*/