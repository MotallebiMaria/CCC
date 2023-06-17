//00:06:16; done; 15/15
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

const int MAXN = 1e5 + 10;
int n;
pair <double, double> p[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    double ans = 0;
    for (int i = 1; i < n; i ++) {
        ans = max(ans, abs(p[i].second - p[i - 1].second) / (p[i].first - p[i - 1].first));
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/