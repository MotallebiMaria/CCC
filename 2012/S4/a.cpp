//00:36:29; will solve after S5
//00:12:29; done; wa2:5
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
 
int n, a[10], ans;
vector <int> v[10];
map <string, bool> mark;

string strperm() {
    string out = "";
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            out += v[i][j] + '0';
        }
        if (i < n - 1) out += "|";
    }
    return out;
}

void hehe(int moves) {
    // cout << moves << endl;
    // for (int i = 0; i < n; i ++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < v[i].size(); j ++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    bool finish = true;
    for (int i = 0; i < n; i ++) {
        if (v[i].size() > 1 || v[i].empty() || (i && v[i].back() < v[i - 1].back())) {
            finish = false;
            break;
        } 
    }
    if (finish) {
        ans = min(ans, moves);
        return;
    }
    for (int i = 0; i < n; i ++) {
        if (v[i].empty()) continue;
        if (i && (v[i - 1].empty() || v[i].back() < v[i - 1].back())) {
            v[i - 1].pb(v[i].back());
            v[i].pop_back();
            if (!mark[strperm()]) {
                // cout << "entered " << strperm() << " with mark " << mark[strperm()] << '\n';
                mark[strperm()] = true;;
                hehe(moves + 1);
            }
            v[i].pb(v[i - 1].back());
            v[i - 1].pop_back();
        }
        if (i < n - 1 && (v[i + 1].empty() || v[i].back() < v[i + 1].back())) {
            v[i + 1].pb(v[i].back());
            v[i].pop_back();
            if (!mark[strperm()]) {
                // cout << "entered " << strperm() << " with mark " << mark[strperm()] << '\n';
                mark[strperm()] = true;
                hehe(moves + 1);
            }
            v[i].pb(v[i + 1].back());
            v[i + 1].pop_back();
        }
    }
    return;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    while (n) {
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
            v[i].clear();
            v[i].pb(a[i]);
        }
        mark.clear();
        mark[strperm()] = true;
        ans = INF;
        hehe(0);
        if (ans == INF)
            cout << "IMPOSSIBLE";
        else
            cout << ans;
        cout << '\n';
        cin >> n;
    }
    return 0;
}
 
/*
    
*/