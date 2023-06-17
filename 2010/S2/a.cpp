//
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
 
int k;
map <string, char> val;
map <string, bool> mark;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> k;
    for (int i = 0; i < k; i ++) {
        char c;
        string s;
        cin >> c >> s;
        val[s] = c;
        mark[s] = true;
    }
    string huf;
    cin >> huf;
    string s, ans;
    s = ans = "";
    for (int i = 0; i < huf.size(); i ++) {
        s += huf[i];
        if (mark[s]) {
            ans += val[s];
            s = "";
        }
    }
    cout << ans << endl;
    return 0;
}
 
/*
5
A 00
B 01
C 10
D 110
E 111
00000101111
*/