//00:20:40
//00:49:35
//00:48:38; done; 0/15
//00:46;00; bruh why can't i solve this
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

const int MAXN = 1e6 + 10;
ll n, m, k, ans[MAXN];
int ind[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    if (k < n || k > n * (n + 1) / 2 || (m == 1 && k > n)) {
        cout << -1 << endl;
        return 0;
    }
    int rep, sum;
    rep = 0;
    ans[1] = ind[1] = sum = 1;
    for (int i = 2; i <= n; i ++) {
        int lo, hi; lo = 1, hi = m;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (sum + i - ind[mid] + n - i > k) lo = mid + 1;
            else hi = mid;
        }
        if (sum + i - max(ind[lo], rep) + n - i > k) {
            cout << -1 << endl;
            return 0;
        }
        ans[i] = lo;
        sum += i - max(ind[lo], rep);
        rep = max(rep, ind[lo]);
        ind[lo] = i;
        cout << i << ": " << lo << " " << sum << '\n';
    }
    if (sum == k) {
        for (int i = 1; i <= n; i ++) {
            cout << ans[i] << " ";
        }
    }
    else {
        cout << -1;
    }
    cout << endl;
    return 0;
}
 
/*
    
*/