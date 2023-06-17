//00:03:50; done; 15/15
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

const int MAXN = 1e5 + 10;
int n, a[MAXN], b[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    for (int i = 1; i <= n; i ++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    int ans = n;
    while (ans > 0) {
        if (a[ans] == b[ans]) break;
        ans --;
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/