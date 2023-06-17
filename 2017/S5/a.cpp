//00:02:31
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

const int MAXN = 2e5 + 10;
int n, m, q, l[MAXN], a[MAXN], num[MAXN], tree[MAXN];
vector <int> lnst[MAXN];

int sum(int k) {
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}

void add(int k, int x) {
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
    return;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> l[i];
        lnst[l[i]].pb(i);
    }
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        add(i, a[i]);
    }
    while (q --) {
        int num;
        cin >> num;
        if (num == 1) {
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << '\n';
        }
        else {
            int x;
            cin >> x;
            for (int i = 0; i < lnst[x].size(); i ++) {
                add(lnst[x][i], -1 * )
            }
        }
    }
    return 0;
}
 
/*
    
*/