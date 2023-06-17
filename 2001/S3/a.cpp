//read solution (not code) from code
//-00:11:28
//done
//note: if time complexity allows, do exactly what problem says (in this case, exactly look for one that doesn't connect A and B, not for side characteristics)
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
bool adj[MAXN][MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("bomb.in", "r", stdin); freopen("bomb.out", "w", stdout);
    char a, b;
    a = b = 'x';
    while (a != '*') {
        cin >> a >> b;
        if (a == '*') break;
        int A = a - 'A', B = b - 'A';
        v.pb(mp(A, B));
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i ++) {
        for (int j = 0; j < 30; j ++) {
            fill(adj[j], adj[j] + 30, false);
        }
        int A, B;
        for (int j = 0; j < v.size(); j ++) {
            if (j == i) continue;
            A = v[j].first, B = v[j].second;
            adj[A][B] = adj[B][A] = true;
        }
        for (int j = 0; j < 26; j ++) {
            adj[j][j] = true;
            for (int k = 0; k < 26; k ++) {
                if (adj[j][k]) {
                    for (int l = 0; l < 26; l ++) {
                        if (adj[j][l]) {
                            adj[k][l] = true;
                        }
                    }
                }
            }
        }
        if (!adj[0][1]) {
            cout << char(v[i].first + 'A') << char(v[i].second + 'A') << '\n';
            cnt ++;
        }
    }
    cout << "There are " << cnt << " disconnecting roads." << endl;
    return 0;
}
 
/*
    
*/