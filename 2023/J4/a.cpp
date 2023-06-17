//15/15
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

const int MAXN = 2e5 + 10;
int n, a[2][MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; i ++) {
        if (a[i][0] && !a[(i + 1) % 2][0]) ans ++;
        for (int j = 1; j < n; j ++) {
            if (a[i][j - 1] && !a[i][j]) ans += 2;
            if (a[i][j] && j % 2) ans ++;
            else if (a[i][j] && j % 2 == 0 && !a[(i + 1) % 2][j]) {
                // cout << i << " " << j << " yeahhh\n";
                ans ++;
            }
        }
        if (a[i][n - 1]) ans += 2;
    }
    cout << ans << '\n';
    return 0;
}
 
/*
    
*/