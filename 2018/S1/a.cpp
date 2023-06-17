//00:11:06; done; 15/15
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

const int MAXN = 1e2 + 10;
int n;
double a[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    sort(a, a + n);
    double ans = INF;
    for (int i = 2; i < n; i ++) {
        ans = min(ans, (a[i] + a[i - 1]) / 2 - (a[i - 1] + a[i - 2]) / 2);
    }
    cout << setprecision(1) << fixed << ans << endl;
    return 0;
}
 
/*
    
*/