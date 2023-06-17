//00:26:21
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
 
int l, r;

string toStr(int x) {
    string out = "";
    while (x) {
        out += char(x % 10 + '0');
        x /= 10;
    }
    reverse(all(out));
    return out;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> l >> r;
    int cnt = 0;
    for (int i = l; i <= r; i ++) {
        string s = toStr(i);
        // cout << s << '\n';
        bool rot = true;
        for (int j = 0; j <= s.size() / 2; j ++) {
            if (!(s[j] == '0' || s[j] == '1' || s[j] == '8' || s[j] == '9' || s[j] == '6')) {
                rot = false;
                break;
            }
            if (s[j] == '6') {
                if (s[s.size() - j - 1] != '9') {
                    rot = false;
                    break;
                }
            }
            else if (s[i] == '9') {
                if (s[s.size() - j - 1] != '6') {
                    rot = false;
                    break;
                }
            }
            else if (s[j] != s[s.size() - j - 1]) {
                rot = false;
                break;
            }
        }
        if (rot) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
 
/*
    
*/