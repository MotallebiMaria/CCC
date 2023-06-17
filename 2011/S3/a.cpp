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
 
int t;
ll p[20];

string isCrystal(int m, ll x, ll y) {
    if (y < p[m - 1] && x >= p[m - 1] && x < p[m] - p[m - 1])
        return "crystal";
    if (y < 2 * p[m - 1] && y >= p[m - 1] && x >= 2 * p[m - 1] && x < p[m] - 2 * p[m - 1])
        return "crystal";
    if (y >= p[m] / 2 || x < p[m - 1] || x >= p[m] - p[m - 1])
        return "empty";
    if (m == 1) {
        if (y == 0 || x == 2) return "crystal";
        return "empty";
    }
    return isCrystal(m - 1, x % p[m - 1], y % p[m - 1]);
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    p[0] = 1;
    for (int i = 1; i <= 13; i ++) p[i] = p[i - 1] * 5;
    cin >> t;
    while (t--) {
        int m;
        ll x, y;
        cin >> m >> x >> y;
        cout << isCrystal(m, x, y) << endl;
    }
    return 0;
}
 
/*
    
*/