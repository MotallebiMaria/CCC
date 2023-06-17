//15/15
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

const int MAXN = 1e5 + 10;
int t, fib[MAXN];
bool prime[MAXN], isfib[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    for (int i = 1; i <= 1e5; i ++) prime[i] = true;
    for (int i = 2; i * i <= 1e5; i ++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 1e5; j += i) {
            prime[j] = false;
        }
    }
    fib[0] = fib[1] = 1;
    isfib[1] = true;
    for (int i = 2; fib[i - 1] + fib[i - 2] <= 1e5; i ++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        isfib[fib[i]] = true;
    }
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        if (isfib[n] && !prime[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
 
/*
    
*/