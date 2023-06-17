//01:14:53
//00:59:37
//solved; understood official solution
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
int q, x[MAXN], y[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("max.int", "r", stdin); freopen("max.out", "w", stdout);
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> y[i];
        }
        reverse(y, y + n);
        int mxD = 0;
        for (int i = 0; i < n; i++) {
            if (i && x[i] == x[i - 1]) continue;
            int ind = lower_bound(y, y + n, x[i]) - y;
            ind = n - ind - 1;
            // cout << i << ": " << x[i] << ": " << ind << ", " << *lower_bound(y, y + n, x[i]) << '\n';
            mxD = max(mxD, max(ind - i, 0));
        }
        cout << "The maximum distance is " << mxD << '\n';
    }
    return 0;
}
 
/*
    
*/