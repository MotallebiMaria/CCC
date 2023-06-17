//00:49:49; will come back
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
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

const int MAXN = 1e6 + 10;
string s;
int cnt[MAXN][3], ans[3];
vector <int> v[3];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> s;
    cnt[0][s[0] - 'A'] ++;
    for (int i = 1; i < s.size(); i ++) {
        for (int j = 0; j < 3; j ++) cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'A'] ++;
        v[s[i] - 'A'].pb(i);
    }
    ans[0] = ans[1] = ans[2] = INF;
    int n = s.size() - 1;
    for (int i = 0; i < s.size(); i ++) {
        int num = s[i] - 'A';
        if (i + 1 >= cnt[n][num])
            ans[num] = min(ans[num], cnt[n][num] - cnt[i][num]);
        if (i <= s.size() - cnt[n][num])
    }
    cout << (ans[0] + ans[1] + ans[2]) / 2 << endl;
    return 0;
}
 
/*
    
*/