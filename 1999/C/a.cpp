//stopped at 01:28:56; not worth it
//update: read solution; was worth it
//00:44:22; done; solved
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

const int MAXN = 3e2 + 10;
int q, n, b, t, l, r;
char c[MAXN][MAXN];

void hehe(int cnt, int l, int r, int t, int b) {
    if (cnt > n) return;
    int len = b - t + 1;
    for (int i = t + len / 3; i < t + len / 3 * 2; i ++) {
        for (int j = l + len / 3; j < l + len / 3 * 2; j ++) {
            c[i][j] = ' ';
        }
    }
    hehe(cnt + 1, l, l + len / 3 - 1, t, t + len / 3 - 1);
    hehe(cnt + 1, l, l + len / 3 - 1, t + len / 3, t + len / 3 * 2 - 1);
    hehe(cnt + 1, l, l + len / 3 - 1, t + len / 3 * 2, b);

    hehe(cnt + 1, l + len / 3, l + len / 3 * 2 - 1, t, t + len / 3 - 1);
    hehe(cnt + 1, l + len / 3, l + len / 3 * 2 - 1, t + len / 3 * 2, b);

    hehe(cnt + 1, l + len / 3 * 2, r, t, t + len / 3 - 1);
    hehe(cnt + 1, l + len / 3 * 2, r, t + len / 3, t + len / 3 * 2 - 1);
    hehe(cnt + 1, l + len / 3 * 2, r, t + len / 3 * 2, b);
    return;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("frac.in", "r", stdin); freopen("frac.out", "w", stdout);
    cin >> q;
    while (q --) {
        cin >> n >> t >> b >> l >> r;
        int p = 1;
        for (int i = 0; i < n; i ++) p *= 3;
        for (int i = 1; i <= p; i ++) {
            for (int j = 1; j <= p; j ++) {
                c[i][j] = '*';
            }
        }
        hehe(0, 1, p, 1, p);
        for (int i = b; i >= t; i --) {
            for (int j = l; j <= r; j ++) {
                cout << c[i][j] << " ";
            }
            cout << '\n';
        }
        cout << endl;
    }
    return 0;
}
 
/*
    
*/