//00:04:58; done; accepted
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
int t, n, d[MAXN], p[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> t >> n;
    for (int i = 0; i < n; i ++) cin >> d[i];
    for (int i = 0; i < n; i ++) cin >> p[i];
    sort(d, d + n); sort(p, p + n);
    int ans = 0;
    if (t == 1) {
        for (int i = 0; i < n; i ++ ) {
            ans += max(d[i], p[i]);
        }
    }
    else {
        int ind = n - 1;
        for (int i= 0; i < n; i ++) {
            ans += max(d[i], p[ind --]);
        }
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/