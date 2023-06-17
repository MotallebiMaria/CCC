//gave up at 02:15:16
//read solution
//tried to implement solution; failed; will do again
//-00:26:02; solved
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

const int MAXN = 1e2 + 10;
int q, r, c, pr, pc, kr, kc, b[MAXN][MAXN], parx, pary;
vector <pair <int, int>> v, vp;

void addPt(int x, int y) {
    if (x >= 0 && x < r && y >= 0 && y < c && b[x][y] > b[parx][pary] + 1) {
        vp.pb(mp(x, y));
        b[x][y] = b[parx][pary] + 1;
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("knight.in", "r", stdin); freopen("knight.out", "w", stdout);
    cin >> q;
    while (q--) {
        cin >> r >> c >> pr >> pc >> kr >> kc;
        //99
        // 2
        // 1
        // 1
        // 1
        // 2
        pr--, pc--, kr--, kc--;
        for (int i = 0; i < r; i++) {
            fill(b[i], b[i] + MAXN, INF);
        }
        v.clear();
        v.pb(mp(kr, kc));
        b[kr][kc] = 0;
        while (v.size()) {
            vp.clear();
            for (int i = 0; i < v.size(); i ++) {
                parx = v[i].first, pary = v[i].second;
                addPt(parx + 2, pary + 1);
                addPt(parx + 2, pary - 1);
                addPt(parx - 2, pary + 1);
                addPt(parx - 2, pary - 1);
                addPt(parx + 1, pary + 2);
                addPt(parx + 1, pary - 2);
                addPt(parx - 1, pary + 2);
                addPt(parx - 1, pary - 2);
            }
            v = vp;
        }
        // for (int i = r - 1; i >= 0; i --) {
        //     for (int j = 0; j < c; j ++) {
        //         cout << b[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        string verdict = "Loss";
        int mvs = 1;
        for (int i = pr + 1; i < r - 1; i ++) {
            if (b[i][pc] <= mvs && (mvs - b[i][pc]) % 2 == 0) {
                verdict = "Win";
                cout << "Win in " << mvs << " knight move(s).\n";
                break;
            }
            mvs ++;
        }
        if (verdict == "Loss") {
            mvs = 0;
            for (int i = pr; i < r - 1; i ++) {
                if (b[i + 1][pc] <= mvs && (mvs - b[i + 1][pc]) % 2 == 0) {
                    verdict = "Stalemate";
                    cout << "Stalemate in " << mvs << " knight move(s).\n";
                    break;
                }
                mvs ++;
            }
        }
        if (verdict == "Loss")
            cout << "Loss in " << r - pr - 2 << " knight move(s).\n";
        cout << endl;
    }
    return 0;
}
 
/*
    every position on p.second
    try to maintain by back and forth movement until p reaches
*/