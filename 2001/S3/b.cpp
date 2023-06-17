//00:34:00
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
 
const int MAXN = 1e3 + 10;
vector <pair <int, int>> v;
bool mark[MAXN][MAXN], used[30];
int d[MAXN];
set <pair <int, int>> ans;
vector <int> let;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("bomb.in", "r", stdin); freopen("bomb.out", "w", stdout);
    char a, b;
    a = b = 'x';
    while (a != '*') {
        cin >> a >> b;
        if (a == '*') break;
        v.pb(mp(a - 'A', b - 'A'));
        d[a - 'A'] ++, d[b - 'A'] ++;
        mark[a - 'A'][a - 'A'] = mark[b - 'A'][b - 'A'] = true;
        mark[a - 'A'][b - 'A'] = mark[b - 'A'][a - 'A'] = true;
        if (!used[a - 'A']) {
            let.pb(a - 'A');
        }
        if (!used[b - 'A']) {
            let.pb(b - 'A');
        }
        used[a - 'A'] = used[b - 'A'] = true;
    }
    for (int i = 0; i < let.size(); i++) {
        for (int j = 0; j < let.size(); j ++) {
            if (mark[let[i]][let[j]]) {
                for (int k = 0; k < v.size(); k ++) {
                    if (mark[let[j]][let[k]])
                        mark[let[i]][let[k]] = mark[let[k]][let[i]] = true;
                }
            }
        }
    }
    for (int i = 0; i < let.size(); i ++) {
        if (mark[0][let[i]] && mark[let[i]][1] && d[let[i]] == 2) {
            for (int j = 0; j < v.size(); j ++) {
                if (v[j].first == let[i] || v[j].second == let[i]) {
                    ans.insert(v[j]);
                }
            }
        }
    }
    for (auto it = ans.begin(); it != ans.end(); it ++) {
        cout << char((*it).first + 'A') << char((*it).second + 'A') << '\n';
    }
    cout << "There are " << ans.size() << " disconnecting roads." << endl;
    return 0;
}
 
/*
    
*/