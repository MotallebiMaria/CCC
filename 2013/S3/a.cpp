//00:51:47; done
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
 
int t, g, mark[5][5], score[5], ans;
// vector <pair <string, pair <int, int>>> v;

void gamegobrrr(int game) {
    if (game > 6) {
        bool good = true;
        for (int i = 1; i <= 4; i ++) {
            if (i != t && score[i] >= score[t]) good = false;
        }
        if (good) ans ++;
        // if (good) {
        //     for (int i= 0; i < v.size(); i ++) {
        //         cout << v[i].second.first << v[i].first << v[i].second.second << ", ";
        //     }
        //     cout << '\n';
        // }
        return;
    }
    for (int i = 1; i <= 4; i ++) {
        for (int j = 1; j <= 4; j ++) {
            if (i != j && mark[i][j] == -1) {
                mark[i][j] = 3, mark[j][i] = 0;
                score[i] += 3;
                // v.pb(mp(" won ", mp(i, j)));
                gamegobrrr(game + 1);
                // v.pop_back();
                if (i > j) {
                    // v.pb(mp(" tied ", mp(i, j)));
                    mark[i][j] = mark[j][i] = 1;
                    score[i] -= 2, score[j] ++;
                    gamegobrrr(game + 1);
                    // v.pop_back();
                    score[i] --, score[j] --;
                }
                else score[i] -= 3;
                mark[i][j] = mark[j][i] = -1;
            }
        }
    }
    return;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    for (int i = 1; i <= 4; i ++) fill(mark[i], mark[i] + 5, -1);
    cin >> t >> g;
    for (int i = 0; i < g; i ++) {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        if (sa > sb) mark[a][b] = 3, mark[b][a] = 0;
        else if (sb > sa) mark[b][a] = 3, mark[a][b] = 0;
        else mark[a][b] = mark[b][a] = 1;
        score[a] += mark[a][b], score[b] += mark[b][a];
    }
    gamegobrrr(g + 1);
    int fact = 1;
    for (int i = 2; i <= 6 - g; i ++) fact *= i;
    cout << ans / fact << endl;
    return 0;
}
 
/*
    
*/