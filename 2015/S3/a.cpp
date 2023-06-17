//00:33:51; done; accepted
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

const int MAXN = 1e5 + 10;
int G, p, g[MAXN];
bool mark[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> G >> p;
    for (int i = 0; i < p; i ++) cin >> g[i];
    int ans = 0;
    for (int i = 0; i < p; i ++) {
        int lo, hi;
        lo = 1; hi = g[i];
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (mark[mid]) hi = mid - 1;
            else lo = mid;
        }
        int num = lo;
        lo = 1, hi = g[i];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mark[mid]) lo = mid + 1;
            else hi = mid;
        }
        if (mark[lo] && mark[num]) break;
        if (!mark[lo] && !mark[num]) {
            if (lo > num) mark[lo] = true;
            else mark[num] = true;
        }
        else if (!mark[lo]) mark[lo] = true;
        else mark[num] = true;
        ans ++;
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/