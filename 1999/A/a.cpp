//00:36:51
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
 
int scr[5];
vector <pair <int, char>> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("card.in", "r", stdin); freopen("card.out", "w", stdout);
    for (int i = 0; i < 52; i ++) {
        string s;
        cin >> s;
        char c = s[0];
        if (c == 'j' || c == 'q' || c == 'k' || c == 'a') {
            v.pb(mp(i, c));
        }
    }
    v.pb(mp(52, 'X'));
    for (int i = 0; i < v.size(); i ++) {
        int x, y;
        x = scr[0], y = scr[1];
        if (v[i].second == 'a' && v[i + 1].first - v[i].first > 4)
            scr[v[i].first % 2] += 4;
        else if (v[i].second == 'k' && v[i + 1].first - v[i].first > 3)
            scr[v[i].first % 2] += 3;
        else if (v[i].second == 'q' && v[i + 1].first - v[i].first > 2)
            scr[v[i].first % 2] += 2;
        else if (v[i].second == 'j' && v[i + 1].first - v[i].first > 1)
            scr[v[i].first % 2] ++;
        if (scr[0] != x) {
            cout << "Player A scores " << scr[0] - x << " point(s).\n";
        }
        else if (scr[1] != y) {
            cout << "Player B scores " << scr[1] - y << " point(s).\n";
        }
    }

    // while (v.size()) {
    //     char c = v.back()[0];
    //     v.pop_back();
    //     if (!(c == 'j' || c == 'q' || c == 'k' || c == 'a')) {
    //         turn = (turn + 1) % 2;
    //         continue;
    //     }
    //     int ind = -1;
    //     for (int i = v.size() - 1; i >= max((int)v.size() - 4, 0); i --) {
    //         char x = v[i][0];
    //         if (x == 'j' || x == 'q' || x == 'k' || x == 'a') {
    //             ind = i;
    //             break;
    //         }
    //     }
    //     int x = scr[turn];
    //     if (c == 'a' && v.size() >= 4 && ind < v.size() - 4)
    //         scr[turn] += 4;
    //     else if (c == 'k' && v.size() >= 3 && ind < v.size() - 3)
    //         scr[turn] += 3;
    //     else if (c == 'q' && v.size() >= 2 && ind < v.size() - 2)
    //         scr[turn] += 2;
    //     else if (c == 'j' && v.size() >= 1 && ind < v.size() - 1)
    //         scr[turn] ++;
    //     if (scr[turn] != x) {
    //         cout << v.size() << " ";
    //         cout << "Player ";
    //         if (turn == 0)
    //             cout << "A";
    //         else
    //             cout << "B";
    //         cout << " scores " << scr[turn] - x << " point(s).\n";
    //     }
    //     turn = (turn + 1) % 2;
    // }
    cout << "Player A: " << scr[0] << " point(s).\n";
    cout << "Player B: " << scr[1] << " point(s).\n";
    return 0;
}
 
/*
    
*/