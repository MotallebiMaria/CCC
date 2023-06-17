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
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> k;
    for (int i = 1; i <= k; i ++) cin >> a[i];
    bool on = false;
    int ind = 1;
    for (int i = 1; i <= k; i ++) {
        if (!a[i] && on && i) {
            v.pb(mp(ind, i - 1));
            on = false;
        }
        if (a[i] && !on) ind = i, on = true;
    }
    if (a[k]) v.pb(mp(ind, k));
    int cnt, ans; ind = 1, cnt = ans = 0;
    for (int i = 0; i < v.size(); i ++) {
        if (cnt + v[i].second - v[i].first + 1 > 7) {
            ans += i - ind + 1 - cnt;
            ind = i, cnt = 0;
        }
        cnt += v[i].second - v[i].first + 1;
    }
    ans += k - ind + 1 - cnt;
    cout << ans << endl;
    return 0;
}
 
/*
    
*/