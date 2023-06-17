//00:08:47
//done
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
 
int t;
vector <int> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s1.in", "r", stdin); freopen("s1.out", "w", stdout);
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        v.clear();
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '-') continue;
            if (s[i] <= '9') {
                v.pb(s[i] - '0');
                continue;
            }
            if (s[i] <= 'O')
                v.pb((s[i] - 'A') / 3 + 2);
            else if (s[i] <= 'S')
                v.pb(7);
            else if (s[i] <= 'V')
                v.pb(8);
            else
                v.pb(9);
        }
        for (int i = 0; i < min((int)v.size(), 10); i ++) {
            cout << v[i];
            if (i == 2 || i == 5)
                cout << '-';
        }
        cout << '\n';
    }
    return 0;
}
 
/*
    
*/