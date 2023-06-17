//00:50:10; times up
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
 
const int MAXN = 1e3 + 10;
int m, n, k, x[MAXN], y[MAXN], r[MAXN], b[MAXN];
ll net[MAXN][MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> m >> n >> k;
    for (int i = 0; i < k; i ++) {
        cin >> x[i] >> y[i] >> r[i] >> b[i];
    }
    for (int i = 0; i < k; i ++) {
        // for (int j = max(y[i] - r[i], 0); j <= min(y[i] + r[i], m); j ++) {
        //     ll num = sqrt(r[i] * r[i] - j * j);
        //     netn[max(x[i] - num, 0ll)][j] += b[i];
        //     netn[min(x[i] + num + 1, (ll)n)][j] -= b[i];
        // }
        for (int j = max(x[i] - r[i], 1); j <= min(x[i] + r[i], n); j ++) {
            ll num = sqrt(r[i] * r[i] - (j - x[i]) * (j - x[i]));
            net[max(y[i] - num, 1ll)][j] += b[i];
            net[min(y[i] + num + 1, m + 1ll)][j] -= b[i];
        }
    }
    for (int i = m; i > 0; i --) {
        for (int j = 1; j <= n; j ++) {
            cout << net[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = m; i > 0; i --) {
        for (int j = 1; j <= n; j ++) {
            net[i][j] += net[i][j - 1];
            cout << net[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
 
/*
    
*/