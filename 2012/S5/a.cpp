//00:07:29; done
//solved
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
int r, c, k, ans[MAXN][MAXN];
bool mark[MAXN][MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> r >> c >> k;
    for (int i = 0; i < k; i ++) {
        int x, y;
        cin >> x >> y;
        mark[x][y] = true;
    }
    int num = 1;
    for (int i = 1; i <= c; i ++) {
        if (mark[1][i]) num = 0;
        ans[1][i] = num;
    }
    num = 1;
    for (int i = 1; i <= r; i ++) {
        if (mark[i][1]) num = 0;
        ans[i][1] = num;
    }
    for (int i = 2; i <= r; i ++) {
        for (int j = 2; j <= c; j ++) {
            if (mark[i][j]) ans[i][j] = 0;
            else ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
        }
    }
    cout << ans[r][c] << endl;
    return 0;
}
 
/*
    
*/