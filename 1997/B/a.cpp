//02:17:47
//i think nasty.out:32000 output is wrong
//notes: break out of all loops when nested loops
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
int q;
vector <int> v;
bool mark[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("nasty.in", "r", stdin); freopen("nasty.out", "w", stdout);
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        v.clear();
        fill(mark, mark + MAXN, false);
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                v.pb(i);
                if (i * i != n)
                    v.pb(n / i);
                mark[i] = mark[n / i] = true;
            }
        }
        string ans = "not nasty";
        for (int i = 0; i < v.size() - 2; i++) {
            for (int j = i + 1; j < v.size() - 1; j++) {
                for (int k = j + 1; k < v.size(); k++) {
                    if (mark[v[i] + v[j] + v[k]]) {
                        ans = "nasty";
                        cout << v[i] << " " << v[j] << " " << v[k] << '\n';
                        break;
                    }
                }
                if (ans == "nasty") break;
            }
            if (ans == "nasty") break;
        }
        cout << n << " is " << ans << '\n';
    }
    return 0;
}
 
/*
    
*/