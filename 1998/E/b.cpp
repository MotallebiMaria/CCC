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
 
const int MAXN = 1e2 + 10;
int q, n, elv[MAXN][MAXN], ans;

void hehe(int x, int y, int cnt) {
    if (x == n && y == n) {
        ans = min(ans, cnt);
        return;
    }
    if (x < n && abs(elv[x][y] - elv[x + 1][y]) <= 2) {
        hehe(x + 1, y, cnt + ((elv[x][y] > elv[1][1] || elv[x + 1][y] > elv[1][1])? 1 : 0));
    }
    if (y < n && abs(elv[x][y] - elv[x][y + 1]) <= 2) {
        hehe(x, y + 1, cnt + ((elv[x][y] > elv[1][1] || elv[x][y + 1] > elv[1][1])? 1 : 0));
    }
    return;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("passage.in", "r", stdin); freopen("passage.out", "w", stdout);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> elv[i][j];
            }
        }
        ans = INF;
        hehe(1, 1, 0);
        if (ans == INF)
            cout << "CANNOT MAKE THE TRIP\n";
        else
            cout << ans << '\n';
        cout << endl;
    }
    return 0;
}
 
/*
    126410606437752 ways for 25*25
*/