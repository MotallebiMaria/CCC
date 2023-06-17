//00:31:39
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
 
int q, m1, m2, m3;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> q >> m1 >> m2 >> m3;
    int turn, cnt;
    turn = cnt = 0;
    while (q) {
        q--;
        if (turn == 0) m1 ++;
        else if (turn == 1) m2++;
        else m3 ++;
        turn = (turn + 1) % 3;
        if (m1 == 35)
            q += 30, m1 = 0;
        if (m2 == 100)
            q += 100, m2 = 0;
        if (m3 == 10)
            q += 9, m3 = 0;
        cnt ++;
    }
    cout << cnt << endl;
    return 0;
}
 
/*
    
*/