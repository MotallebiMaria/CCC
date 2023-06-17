//00:12:32; done; 0/15
//00:11:11; done; 0/15
//00:08:13; done; 0/15
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
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

const int MAXN = 1e6;
int n, k, d;
ll a[MAXN];
pair <int, int> ap[MAXN];
bool mark[MAXN];

ll days(ll x) {
    fill(mark, mark + n, false);
    ll sum = 0;
    for (int i = 0; i < n; i ++) {
        if (sum >= x) break;
        sum += ap[i].first, mark[ap[i].second] = true;
    }
    ll out, cnt; out = 1, cnt = 0;
    bool b = false;
    for (int i = 0; i < n; i ++) {
        if (b && mark[i]) cnt = 1, out ++, b = false;
        else cnt ++;
        if (mark[i]) b = true;
        if (cnt > k) out ++;
    }
    // cout << x << ": " << out << '\n';
    return out;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
        ap[i] = mp(a[i], i);
    }
    sort(ap, ap + n); reverse(ap, ap + n);
    ll lo, hi; lo = 1, hi = sum;
    d = n / k + (n % k? 1 : 0);
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (days(mid) > d) hi = mid - 1;
        else lo = mid;
    }
    cout << lo << endl;
    return 0;
}
 
/*
    
*/