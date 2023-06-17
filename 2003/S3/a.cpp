//00:33:22
//done
//tc1
//mistake1: not checking down and right cell to see if same room
//mistake1 fixed in -00:19:24
//solved
//unofficial solution was recursion; big brain!
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

const int MAXN = 5e1 + 10;
int f, r, c, num;
char g[MAXN][MAXN];
vector <int> w[MAXN], room;
int mark[MAXN][MAXN];

int hehe(int x) {
    int cnt = 0;
    int prv = -1;
    while (cnt != prv) {
        prv = cnt;
        for (int i = x; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (mark[i][j]) continue;
                if (g[i][j] == '.' && (mark[i - 1][j] == num || (j && mark[i][j - 1] == num) || mark[i + 1][j] == num || mark[i][j + 1] == num)) {
                    mark[i][j] = num, cnt ++;
                    if (g[i + 1][j] == '.' && !mark[i + 1][j])
                        mark[i + 1][j] = num, cnt ++;
                    else if (g[i - 1][j] == '.' && !mark[i - 1][j])
                        mark[i - 1][j] = num, cnt ++;
                    else if (j && g[i][j - 1] == '.' && !mark[i][j - 1])
                        mark[i][j - 1] = num, cnt ++;
                    else if (g[i][j + 1] == '.' && !mark[i][j + 1])
                        mark[i][j + 1] = num, cnt ++;
                }
            }
        }    
    }
    
    return cnt;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> f >> r >> c;
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c;j ++) {
            cin >> g[i][j];
        }
    }
    num = 1;
    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            if (!mark[i][j] && g[i][j] == '.') {
                int cnt = 0;
                for (int k = j ;k < c; k ++) {
                    if (g[i][k] == 'I') break;
                    mark[i][k] = num;
                    cnt ++;
                }
                room.pb(cnt + hehe(i + 1));
                num++;
            }
        }
    }
    // for (int i = 0; i < r; i ++) {
    //     for (int j = 0; j < c ; j ++) {
    //         cout << mark[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // for (int i = 0 ; i < room.size(); i ++) {
    //     cout << room[i] << " ";
    // }
    // cout << '\n';
    sort(all(room));
    reverse(all(room));
    int ans = 0;
    for (int i = 0; i < room.size(); i ++) {
        if (f < room[i]) break;
        f -= room[i];
        ans ++;
    }
    cout << ans << " rooms, " << f << " square metre(s) left over" << endl;
    return 0;
}
 
/*
IIIIIIIIIIIIIIII
I......I.......I
I......III.....I
I........I.....I
I........IIIIIII
IIIIIIIIII.....I
I.I......I.....I
III..III.I.....I
I....I.IIIII...I
I....I.....III.I
I....I.......I.I
I....I.....III.I
I....I.....I...I
IIIIIIIIIIIIIIII

    xxxxxxxxxxxxxxxx
    x6-----x7------x
    x6-----xxx5----x
    x7------xxx4---x
    x5----xxx1xxxxxx

*/