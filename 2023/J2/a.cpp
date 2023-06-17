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

int n;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        if (s == "Poblano") ans += 1500;
        else if (s == "Mirasol") ans += 6000;
        else if (s == "Serrano") ans += 15500;
        else if (s == "Cayenne") ans += 40000;
        else if (s == "Thai") ans += 75000;
        else ans += 125000;
    }
    cout << ans << '\n';
    return 0;
}
 
/*
    
*/