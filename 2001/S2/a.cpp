//00:24:00
//00:51:00
//-00:05:42
//done
//(un)official solution was stupid; can't control position on screen
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
 
int l, r, pat[15][15];
int seq[10] = {-31, -23, -15, -7, 3, 11, 19, 27, 35};
// int seq2[10] = {-31, -23, -15, -7, 1, 11, 19, 27, 35}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> l >> r;
    int w = 1;
    while (w * w < l - r) w ++;
    int num = 72;
    for (int i = 0; i < 5; i ++) {
        int nump = num;
        pat[i][0] = num;
        for (int j = 1; j < 10; j ++) {
            if (j <= i || j >= 9 - i) {
                nump += seq[j - 1];
            }
            else {
                nump --;
            }
            pat[i][j] = nump;
        }
        num ++;
    }
    int x = 4;
    for (int i = 5; i < 10; i ++) {
        int nump = num;
        pat[i][0] = num;
        for (int j = 1; j < 10; j ++) {
            if (j <= x || j > 9 - x) {
                nump += seq[j - 1];
            }
            else {
                nump ++;
            }
            pat[i][j] = nump;
        }
        num ++;
        x --;
    }
    int a, b, c, d;
    a = b = c = d = -1;
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j ++) {
            if (pat[i][j] <= r - l) {
                if (a == -1) a = i;
                b = i;
                if (c == -1 || j < c) c = j;
                d = j;
            }
        }
    }
    for (int i = a; i <= b; i ++) {
        for (int j = c; j <= d; j ++) {
            if (pat[i][j] + l <= r) {
                cout << pat[i][j] + l;
                if (pat[i][j] + l < 10)
                    cout << " ";
            }
            else {
                cout << "  ";
            }
            cout << "  ";
        }
        cout << '\n';
    }
    return 0;
}
 
/*
    
*/