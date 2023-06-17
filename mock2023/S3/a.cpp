//
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

int t;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> t;
    while (t --) {
        ll k, n, a, b, c;
        cin >> k >> n >> a >> b >> c;
        ll maxp, minp; maxp = 0, minp = INF;
        ll tot = n * (n - 1);
        if (b > a && b > c) {
            maxp = b * (n - 1);
        }
        else {
            if (a < c) swap(a, c);
            ll lo, hi; lo = 0, hi = tot / 2;
            while (lo < hi) {
                ll mid = lo + (hi - lo) / 2;
                
            }
        }
        if (b < a && b < c) {
            minp = b * (n - 1);
        }
        else {
            if (a > c) swap(a, c);

        }
        cout << maxp << " " << minp << '\n';
    }
    return 0;
}
 
/*
    
*/