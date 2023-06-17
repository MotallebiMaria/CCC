//00:12:00
//+00:02:48; done
//solved
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
 
string m, f;
int x;
bool r[10], d[10];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s1.in", "r", stdin); freopen("s1.out", "w", stdout);
    cin >> m >> f >> x;
    for (int i = 0; i < 5; i ++) {
        if ((m[i * 2] >= 'a' || m[i * 2 + 1] >= 'a') && (f[i * 2] >= 'a' || f[i * 2 + 1] >= 'a'))
            r[i] = true;
        if (m[i * 2] <= 'Z' || m[i * 2 + 1] <= 'Z' || f[i * 2] <= 'Z' || f[i * 2 + 1] <= 'Z')
            d[i] = true;
    }
    while (x--) {
        string s;
        cin >> s;
        string ans = "Possible baby.";
        for (int i = 0; i < 5; i ++) {
            if ((s[i] >= 'a' && !r[i]) || (s[i] <= 'Z' && !d[i]))
                ans = "Not their baby!";
        }
        cout << ans << '\n';
    }
    return 0;
}
 
/*
    
*/