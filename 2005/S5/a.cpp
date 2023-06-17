//00:18:51
//done
//tc4 wa, tc6-10 tle
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <set>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
 
int t;
set <ll> s;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s5.in", "r", stdin); freopen("s5.out", "w", stdout);
    cin >> t;
    ll ans = 0;
    int n = t;
    while (t--) {
        ll a;
        cin >> a;
        s.insert(-1 * a);
        ans += distance(s.begin(), s.find(-1 * a)) + 1;
    }
    cout << setprecision(2) << fixed << (double)ans / (double)n << endl;
    return 0;
}
 
/*
    
*/