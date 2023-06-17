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

class Triangle {
    public:
    ll s1;
    ll s2;
    ll s3;
};

const int MAXN = 1e5 + 10;
int n;
ll a[MAXN];
vector <ll> v(3);
vector <Triangle> t;

Triangle make_triangle(ll x, ll y, ll z) {
    if (x < y) swap(x, y);
    if (x < z) swap(x, z);
    if (y < z) swap(y, z);
    Triangle res;
    res.s1 = x, res.s2 = y, res.s3 = z;
    return res;
}

int gimme(int x, int y) {
    ll lo, hi;
    lo = x + 1, hi = y - 1;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (a[lo] + a[y] > a[x] && a[x] + a[y] > a[lo]) {
            t.pb(make_triangle(lo, y, x));
        }
        if (a[y] + a[mid] <= a[x]) lo = mid;
        else hi = mid - 1;
    }
    if (a[lo] + a[y] > a[x] && a[x] + a[y] > a[lo]) return lo;
    if (a[y] + a[lo] <= a[x]) return -1;
    return -2;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n); reverse(a, a + n);
    int ind = n - 1;
    ll sum = -1;
    for (int i = 0; i < ind - 1; i ++) {
        while (ind > i + 1 && gimme(i, ind) == -1) ind --;
        if (ind == i + 1) break;
        // int num = gimme(i, ind);
        // if (num > 0) {
        //     if (a[i] + a[ind] + a[num] > sum) {
        //         v[0] = i, v[1] = num, v[2] = ind;
        //         sum = a[i] + a[ind] + a[num];
        //     }
        // }
    }
    
    return 0;
}
 
/*
    
*/