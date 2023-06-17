//02:23:29
//solved; understood official solution
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
 
int q;

void hehe(int ind, int rem, string pat) {
    if (ind == 0) {
        for (int i = pat.size() - 1; i >= 0; i--) {
            cout << pat[i];
        }
        cout << '\n';
        return;
    }
    if (ind <= rem) {
        hehe(ind - 1, rem - 1, pat + "1");
    }
    else {
        hehe(ind - 1, rem, pat + "0");
        if (rem) {
            hehe(ind - 1, rem - 1, pat + "1");
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("pat.in", "r", stdin); freopen("pat.out", "w", stdout);
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << "The bit patterns are\n";
        hehe(n, k, "");
        cout << '\n';
    }
    return 0;
}
 
/*
    
*/