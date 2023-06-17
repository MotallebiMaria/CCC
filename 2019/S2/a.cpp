//00:46:24; done; 15/15
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

const int MAXN = 2e6 + 10;
int t, ans[MAXN];
bool prime[MAXN];
vector <int> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    for (int i = 2; i <= 2e6; i ++) prime[i] = true;
    for (int i = 2; i * i <= 2e6; i ++) {
        if (prime[i]) {
            for (int j = i * i; j <= 2e6; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= 1e6; i ++) {
        if (prime[i]) {
            v.pb(i);
        }
    }
    for (int i = 4; i <= 2e6; i += 2) {
        for (int j = 0; j < v.size() && v[j] < i; j ++) {
            if (prime[i - v[j]]) {
                ans[i] = v[j];
                break;
            }
        }
    }
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        cout << ans[n * 2] << " " << n * 2 - ans[n * 2] << '\n';
    }
    return 0;
}
 
/*
    
*/