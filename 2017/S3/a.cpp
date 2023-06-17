//00:22:26; done; 0/15
//00:11:13; mistake: kept 4e3 to 10; 15/15
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

const int MAXN = 1e6 + 10;
int n, l[MAXN], cnt[MAXN], board[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> l[i];
        cnt[l[i]] ++;
    }
    for (int i = 2; i <= 4e3; i ++) {
        // cout << i << ": ";
        for (int j = 1; j <= i / 2; j ++) {
            if (j == i - j) board[i] += cnt[j] / 2;
            else board[i] += min(cnt[j], cnt[i - j]);
            // cout << board[i] << " ";
        }
        // cout << '\n';
    }
    sort(board + 2, board + (int)4e3); reverse(board + 2, board + (int)4e3);
    int cnt = 0;
    for (int i = 2; i <= 4e3; i ++) {
        if (board[i] != board[2]) break;
        cnt ++;
    }
    cout << board[2] << " " << cnt << endl;
    return 0;
}
 
/*
    
*/