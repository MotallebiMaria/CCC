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

const int MAXN = 3e1 + 10;
int k, a[MAXN], dp[MAXN];
vector <pair <int, int>> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> k;
    for (int i = 1; i <= k; i ++) cin >> a[i];
    for (int i = 1; i <= k; i ++) {
        for (int j = i - 1; j > 0 && j >= i - 3; j --) {
            if (a[j]) break;
            dp[i] = min(dp[i], dp[j] + 1);
        }
        if (!a[i]) dp[i] = dp[i - 1];
    }
    cout << dp[k] << endl;
    // a[0] = 2;
    // for (int i = 1; i <= k; i ++) {
    //     if (a[i] != a[i - 1]) v.pb(mp(0, a[i]));
    //     v.back().first ++;
    // }
    // int ans = 0;
    // for (int i = 0; i < v.size(); i += 2) {
    //     if (i == 0 && v[i].second == 0) i++;
    //     int ansp, num;
    //     ansp = num = INF;
    //     if (!i) {
    //         ansp = 
    //     }
    //     if (i == v.size() - 2 && v[i].first + v[i + 1].first >= 4 && v[i + 1].first < ansp) {
    //         if ()
    //     }
    // }
    return 0;
}
 
/*
    
*/