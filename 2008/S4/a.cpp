//-00:25:11; done; all wa
//-01:25:59; wa2,3,4,5; order isn't fixed, can rearrange
//-00:02:42; wa again; didn't fully permutate, just cycled through
//-00:23:25; solved
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

int n, c[5];
bool mark[5];
vector <vector <int>> perm;
vector <int> v;

void permutate(int ind) {
    if (ind == 4) {
        // for (int i = 0; i < 4; i ++) cout << v[i] << " ";
        // cout << endl;
        perm.pb(v);
        return;
    }
    for (int i = 0; i < 4; i ++) {
        if (!mark[i]) {
            mark[i] = true;
            v.pb(c[i]);
            permutate(ind + 1);
            v.pop_back();
            mark[i] = false;
        }
    }
    return;
}

bool gimme(int x, int num, int ind, int r) {
    if (ind == r) {
        if (num == x) return true;
        return false;
    }
    if (gimme(x, num - c[ind], ind + 1, r)) return true;
    if (gimme(x, num + c[ind], ind + 1, r)) return true;
    if (num % c[ind] == 0 && gimme(x, num / c[ind], ind + 1, r)) return true;
    if (gimme(x, num * c[ind], ind + 1, r)) return true;
    return false;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s4.in", "r", stdin); freopen("s4.out", "w", stdout);
    cin >> n;
    while (n --) {
        for (int i = 0; i < 4; i ++) cin >> c[i];
        fill(mark, mark + 4, false);
        perm.clear();
        permutate(0);
        int ans = 0;
        for (int turn = 0; turn < 24; turn ++) {
            for (int i = 0; i < 4; i ++) c[i] = perm[turn][i];
            for (int i = 24; i > 0; i --) {
                if (gimme(i, c[0], 1, 4)) { // normal
                    ans = max(ans, i);
                }
                for (int j = 1; j <= i; j ++) { // 2 2 +
                    if (gimme(j, c[0], 1, 2) && gimme(i - j, c[2], 3, 4)) {
                        ans = max(ans, i);
                    }
                }
                for (int j = i; j <= 169; j ++) { // 2 2 -
                    if (gimme(j, c[0], 1, 2) && gimme(j - i, c[2], 3, 4)) {
                        ans = max(ans, i);
                    }
                }
                for (int j = 1; j <= i; j ++) { // 2 2 *
                    if (i % j == 0 && gimme(j, c[0], 1, 2) && gimme(i / j, c[2], 3, 4)) {
                        ans = max(ans, i);
                    }
                }
                for (int j = 1; j <= 169; j ++) { // 2 2 /
                    if (gimme(j * i, c[0], 1, 2) && gimme(j, c[2], 3, 4)) {
                        ans = max(ans, i);
                    }
                }
                if (gimme(i - c[0], c[1], 2, 4)) { // 1 3 +
                    ans = max(ans, i);
                }
                if (gimme(c[0] - i, c[1], 2, 4)) { // 1 3 -
                    ans = max(ans, i);
                }
                if (i % c[0] == 0 && gimme(i / c[0], c[1], 2, 4)) { // 1 3 *
                    ans = max(ans, i);
                }
                if (c[0] % i == 0 && gimme(c[0] / i, c[1], 2, 4)) { // 1 3 /
                    ans = max(ans, i);
                }
            }
            
        }
        cout << ans << endl;
    }
    return 0;
}
 
/*
    
*/