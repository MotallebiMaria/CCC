//00:04:49; done; 11/15
//00:04:13; 11/15
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

const int MAXN = 1e4 + 10;
int n;
double h[MAXN], w[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i <= (n? n : -1); i ++) cin >> h[i];
    for (int i = 0; i < n; i ++) cin >> w[i];
    double ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += w[i] * (double)(h[i] + h[i + 1]);
    }
    cout << fixed << ans / 2 << endl;
    return 0;
}
 
/*
    
*/