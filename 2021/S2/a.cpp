//00:11:29; done; 15/15
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

const int MAXN = 5e6 + 10;
int m, n, k;
int row[MAXN], col[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> m >> n >> k;
    while (k --) {
        char c; int x;
        cin >> c >> x;
        if (c == 'R') row[x] ^= 1;
        else col[x] ^= 1;
    }
    ll cnt = 0;
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (row[i] ^ col[j]) cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}
 
/*
    
*/