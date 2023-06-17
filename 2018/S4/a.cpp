//000:37:05; done; 9/15 (tle last test)
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
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

ll n;
unordered_map <ll, ll> m;

ll hehe(ll x) {
    if (m[x]) return m[x];
    m[x] = x / 2;
    for (ll i = 2; i <= x / 2 + x % 2; i ++) {
        m[x] += hehe(x / i);
    }
    return m[x];
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    m[1] = m[2] = 1;
    cout << hehe(n) << endl;
    return 0;
}
 
/*
    
*/