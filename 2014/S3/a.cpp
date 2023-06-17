//00:18:27; done; 3/15
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

const int MAXN = 1e5 + 10;
int t, a[MAXN], hold[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = n; i > 0; i --) cin >> a[i];
        int num, ind; num = 1, ind = 0;
        string ans = "Y";
        for (int i = 1; i <= n; i ++) {
            if (a[i] == num) num ++;
            else if (hold[ind] == num) ind --, num ++, i --;
            else hold[++ind] = a[i];
        }
        for (int i = ind; i > 0; i --) {
            if (hold[i] != num) {
                ans = "N";
                break;
            }
            num ++;
        }
        cout << ans << "\n";
    }
    return 0;
}
 
/*
    2
    4
    2
    3
    1
    4
    4
    4
    1
    3
    2
*/