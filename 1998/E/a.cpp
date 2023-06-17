//looked at solution; re-implemented; solved;
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
 
const int MAXN = 1e2 + 10;
int q, n, elv[MAXN][MAXN], ans[MAXN][MAXN];
set <pair <int, int>> v, p;
 
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
            fill(ans[i], ans[i] + MAXN, INF);
        }
        v.clear();
        v.insert(mp(1, 1));
        ans[1][1] = 0;
        while (v.size()) {
            p.clear();
            for (auto i = v.begin(); i != v.end(); i ++) {
                int x, y;
                x = (*i).first, y = (*i).second;
                // cout << "(" << x << "," << y << ") ";
                if (x + 1 <= n && abs(elv[x + 1][y] - elv[x][y]) <= 2) {
                    int hehe = ans[x + 1][y];
                    ans[x + 1][y] = ans[x][y];
                    if (elv[x + 1][y] > elv[1][1] || elv[x][y] > elv[1][1])
                        ans[x + 1][y] ++;
                    if (ans[x + 1][y] < hehe)
                        p.insert(mp(x + 1, y));
                    else ans[x + 1][y] = hehe;
                }
                if (y + 1 <= n && abs(elv[x][y + 1] - elv[x][y]) <= 2) {
                    int hehe = ans[x][y + 1];
                    ans[x][y + 1] = ans[x][y];
                    if (elv[x][y + 1] > elv[1][1] || elv[x][y] > elv[1][1])
                        ans[x][y + 1] ++;
                    if (ans[x][y + 1] < hehe)
                        p.insert(mp(x, y + 1));
                    else ans[x][y + 1] = hehe;
                }
                if (x - 1 > 0 && abs(elv[x - 1][y] - elv[x][y]) <= 2) {
                    int hehe = ans[x - 1][y];
                    ans[x - 1][y] = ans[x][y];
                    if (elv[x - 1][y] > elv[1][1] || elv[x][y] > elv[1][1])
                        ans[x - 1][y] ++;
                    if (ans[x - 1][y] < hehe)
                        p.insert(mp(x - 1, y));
                    else ans[x - 1][y] = hehe;
                }
                if (y - 1 > 0 && abs(elv[x][y - 1] - elv[x][y]) <= 2) {
                    int hehe = ans[x][y - 1];
                    ans[x][y - 1] = ans[x][y];
                    if (elv[x][y - 1] > elv[1][1] || elv[x][y] > elv[1][1])
                        ans[x][y - 1] ++;
                    if (ans[x][y - 1] < hehe)
                        p.insert(mp(x, y - 1));
                    else ans[x][y - 1] = hehe;
                }
            }
            // cout << '\n';
            v = p;
        }
        if (ans[n][n] == INF)
            cout << "CANNOT MAKE THE TRIP\n";
        else
            cout << ans[n][n] << '\n';
        cout << endl;
    }
    return 0;
}
 
/*
    126410606437752 ways for 25*25
*/