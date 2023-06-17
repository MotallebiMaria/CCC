//00:30:27
//note: time limit 3 secs (= 1,500,000,000)
//done
//tc1-3
//-00:19:14
//upper case X was wrote lower case
//tc3
//L wasn't included
//note: pay attention to input output words and cases
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

const int MAXN = 1e3 + 10;
int r, c, m;
string cl[MAXN];
char mv[MAXN * 30], ans[MAXN][MAXN];
vector <pair <int, int>> v[5];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("blind.in", "r", stdin); freopen("blind.out", "w", stdout);
    cin >> r >> c;
    for (int i = 0; i < r; i ++) {
        cin >> cl[i];
        for (int j = 0; j < c; j ++) {
            ans[i][j] = cl[i][j];
        }
    }
    cin >> m;
    for (int i = 0 ;i < m; i ++) {
        cin >> mv[i];
    }
    for (int i = 0; i < 4; i ++) {
        int dir = i;
        for (int j = 0; j < m; j ++) {
            if (mv[j] == 'R') dir = (dir + 1) % 4;
            else if (mv[j] == 'L') dir = dir - 1 + ((dir == 0)? 4 : 0);
            else {
                v[i].pb(mp(0, 0));
                if (dir == 0) v[i].back().first --;
                else if (dir == 1) v[i].back().second ++;
                else if (dir == 2) v[i].back().first ++;
                else v[i].back().second --;
            }
        }
    }
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            if (cl[i][j] == 'X') continue;
            bool mishe = true;
            for (int k = 0; k < 4; k ++) {
                mishe = true;
                int x, y;
                x = i, y = j;
                for (int l = 0; l < v[k].size(); l ++) {
                    x += v[k][l].first, y += v[k][l].second;
                    if (x < 0 || x >= r || y < 0 || y >= c || cl[x][y] == 'X') {
                        mishe = false;
                        break;
                    }
                }   
                if (mishe) {
                    ans[x][y] = '*';
                    break;
                }
            }
        }
    }
    for (int i = 0; i < r; i ++) {
        for (int j = 0 ; j < c; j ++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}
 
/*
    5
    5
    .....
    .X.X.
    .....
    .X.X.
    .....
    16
    R
    F
    F
    L
    L
    L
    F
    F
    L
    L
    L
    F
    F
    R
    F
    F
*/