//
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
 
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
string w;
int r, c, ans;
char x[MAXN][MAXN];
bool mark[MAXN][MAXN];

void go(int i, int j, int ind) {
    if (i < 0 || i >= r || j < 0 || j >= c || mark[i][j]) return;
    if (ind == w.size() - 1 && x[i][j] == w[ind]) {
        ans ++;
        cout << "ended at " << i << " " << j << '\n';
        return;
    }
    if (x[i][j] != w[ind]) return;
    mark[i][j] = true;
    go(i - 1, j, ind + 1);
    go(i - 1, j - 1, ind + 1);
    go(i - 1, j + 1, ind + 1);
    go(i + 1, j, ind + 1);
    go(i + 1, j - 1, ind + 1);
    go(i + 1, j + 1, ind + 1);
    go(i, j + 1, ind + 1);
    go(i, j - 1, ind + 1);
    return;
} 
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> w >> r >> c;
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            cin >> x[i][j];
        }
    }
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            go(i, j, 0);
        }
    }
    cout << ans << '\n';
    return 0;
}
 
/*
    
*/