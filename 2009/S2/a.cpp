//00:17:30; done
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

const int MAXN = 3e1 + 10;
int r, l, b[MAXN][MAXN], cnt[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> r >> l;
    for (int i = r; i > 0; i --) {
        for (int j = 1; j <= l; j ++) {
            cin >> b[i][j];
        }
    }
    for (int i = r; i > 1 ; i--) {
        for (int j = 1; j <= l; j ++) {
            if (b[i][j] ^ b[i - 1][j] != b[i - 1][j])
                cnt[j] = 2;
            else
                cnt[j] = 1;
        }
    }
    ll ans = 1;
    for (int i = 1; i <= l; i ++) {
        if (cnt[i] == 2 || (b[0][i] ^ b[1][i] != b[0][i]))
            ans *= 2;
    }
    cout << ans << endl;
    return 0;
}
 
/*
    constructive algorithm go brrrr
*/