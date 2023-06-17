//80 mins remaining
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
 
const int MAXN = 1e1 + 10;
int m, n, a, b, c;
char x[MAXN][MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("s5.in", "r", stdin); freopen("s5.out", "w", stdout);
    cin >> m >> n >> a >> b >> c;
    for (int i = 0; i < m; i ++) {
        for (int j = 0;j < n; j ++) {
            cin >> x[i][j];
        }
    }

    return 0;
}
 
/*
    
*/