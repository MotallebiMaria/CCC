//
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
 
const int MAXN = 1e6 + 10;
int h, k;
ll adr[MAXN], ans;
bool mark[MAXN];

int hoseCnt(int x) {
    fill(mark, mark + (int)1e6, false);
    int out = INF;
    for (int i = 0; i < h; i ++) {
        // cout << i << ":" << endl;
        int cnt = 1;
        int ind = (i + 1) % h;
        ll sum = 0;
        do {
            int num = adr[ind] - (ind? adr[ind - 1] : adr[h - 1] - 1e6);
            if ((sum + num) / 2 + (sum + num) % 2 > x) {
                cnt ++;
                sum = 0;
            }
            sum += num;
            ind = (ind + 1) % h;
            // cout << ind << endl;
        } while(ind != (i + 1) % h);
        out = min(out, cnt);
    }
    return out;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> h;
    for (int i = 0; i < h; i ++) {
        cin >> adr[i];
    }
    cin >> k;
    if (k >= h) {
        cout << 0 << endl;
        return 0;
    }
    sort(adr, adr + h);
    ans = INF;
    ll minp = adr[0] - adr[h - 1] + 1000000;
    for (int i = 1; i < h; i ++) {
        minp = min(minp, adr[i] - adr[i - 1]);
    }
    int lo, hi;
    lo = minp / 2 + minp % 2, hi = (adr[h - 1] - adr[0]) / 2 + (adr[h - 1] - adr[0]) % 2;
    while (lo < hi) {
        // cout << lo << " " << hi << endl;
        int mid = lo + (hi - lo) / 2;
        if (hoseCnt(mid) > k)
            lo = mid + 1;
        else
            hi = mid;
    }
    cout << lo << endl;
    return 0;
}
 
/*
4
0
67000
68000
77000
2
*/