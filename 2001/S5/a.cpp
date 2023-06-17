//00:25:10
//done
//not output files; assumed solved
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
 
int m, n;
vector <string> a, b;
vector <int> ans;
bool found;

void hehe(int cnt, string A, string B) {
    if (A == B && A != "") {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i ++) {
            cout << ans[i] + 1 << '\n';
        }
        cout << endl;
        found = true;
        return;
    }
    if (cnt == m) return;
    for (int i = 0; i < n; i ++) {
        ans.pb(i);
        hehe(cnt + 1, A + a[i], B + b[i]);
        ans.pop_back();
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("post.in", "r", stdin); freopen("post.out", "w", stdout);
    cin >> m >> n;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        a.pb(s);
    }
    for (int i = 0; i < n; i ++) {
        string s; 
        cin >> s;
        b.pb(s);
    }
    found = false;
    hehe(0, "", "");
    if (!found) {
        cout << "No solution." << endl;
    }
    return 0;
}
 
/*
    
*/