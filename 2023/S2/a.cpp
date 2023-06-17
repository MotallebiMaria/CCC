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

const int MAXN = 5e3 + 10;
int n, a[MAXN];
ll dp[MAXN][MAXN], minp[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i ++) {
        minp[i] = INF;
        for (int j = i; j <= n; j ++) {
            dp[i][j] = dp[i - 2][j - 1] + abs(a[j] - a[j - i + 1]);
            minp[i] = min(minp[i], dp[i][j]);
        }
    }
    cout << "0 ";
    for (int i = 2; i <= n; i ++) {
        cout << minp[i] << " ";
    }
    cout << '\n';
    return 0;
}
 
/*
    
*/