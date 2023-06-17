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

int n;
vector <ll> ans;

void hehe(ll l, ll r) {
    // cout << l << " " << r << endl;
    if (l == r) {
        ans.pb(l);
        return;
    }
    hehe(l, l + ceil((r - l) / 3));
    hehe(r - (r - l) / 3, r);
    return;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    hehe(0, n);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
 
/*
    
*/