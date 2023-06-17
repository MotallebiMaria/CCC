//02:52:24
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
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("dpa.in", "r", stdin); freopen("dpa.out", "w", stdout);
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        cout << n << " is a ";
        if (sum == n) {
            cout << "perfect";
        }
        else if (sum > n) {
            cout << "abundant";
        }
        else {
            cout << "deficient";
        }
        cout << " number.\n";
    }
    return 0;
}
 
/*
    
*/