//00:14:34
//done
//-00:07:00 tried to understand testcase why 2nd 80?? seems wrong
//mistake1: calculate savings in time, not time itself
//-00:01:30 mistake1 fixed
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

int l;
map <string, bool> m;
vector <string> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s4.in", "r", stdin); freopen("s4.out", "w", stdout);
    cin >> l;
    while (l--) {
        int n;
        cin >> n;
        int ans, cnt;
        ans = cnt = 0;
        v.clear(); m.clear();
        for (int i = 0; i < n; i ++) {
            string s;
            cin >> s;
            v.pb(s);
        }
        for (int i = 0; i < n; i ++) {
            string s = v[i];
            if (!m[s] && s != v.back()) {
                cnt ++;
                m[s] = true;
            }
            else {
                cnt --;
            }
            ans = max(ans, cnt);
            // cout << s << " " << cnt << '\n';
        }
        cout << n * 10 - ans * 20 << endl;
    }
    return 0;
}
 
/*
    
*/