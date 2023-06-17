//00:38:48
//gave up
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

const int MAXN = 1e3 + 10;
int c, r, d, ans;
int w[MAXN][MAXN], dc[MAXN];
bool used[MAXN];

void hehe(int cur, int minw, int cnt) {
    if (cnt == d) {
        ans = max(ans, minw);
        return;
    }
    for (int i = 0; i < c; i ++) {
        if (w[cur][i] && !used[i]) {

            hehe(i, min(minw, w[cur][i]), cnt + 1);
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("truck.in", "r", stdin); freopen("truck.out", "w", stdout);
    cin >> c >> r >> d;
    for (int i = 0; i < r; i++) {
        fill(w[i], w[i] + c, -1);
    }
    for (int i = 0; i < r; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        w[x][y] = w[y][x] = z;
    }
    for (int i = 0; i < d; i ++) {
        cin >> dc[i];
    }
    hehe(1, INF, 0);
    return 0;
}
 
/*
    
*/