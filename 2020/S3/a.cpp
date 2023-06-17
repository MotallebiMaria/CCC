//00:46:00; done (expecting 7/15); 7/15
//
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <unordered_set>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

const int MAXN = 2e5 + 10;
string s, h;
int cnt[30], cnth[MAXN][30];
bool mark[MAXN];
unordered_set <string> ans;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> s >> h;
    int num = s.size();
    s = " " + s; h = " " + h;
    for (int i = 1; i < s.size(); i ++) {
        cnt[s[i] - 'a'] ++;
    }
    for (int i = 1; i < h.size(); i ++) {
        for (int j = 0; j < 26; j ++) {
            cnth[i][j] = cnth[i - 1][j];
        }
        cnth[i][h[i] - 'a'] ++;
    }
    for (int i = num; i < h.size(); i ++) {
        bool good = true;
        for (int j = 0; j < 26; j ++) {
            if (cnth[i][j] - cnth[i - num][j] != cnt[j]) {
                // cout << i << " " << i - num << " " << j << " was not equal" << endl;
                good = false;
                break;
            }
        }
        if (good) mark[i] = true;
    }
    string x = "";
    for (int i = 1; i <= num; i ++) x += h[i];
    if (mark[num]) ans.insert(x);
    for (int i = num + 1; i < h.size(); i ++) {
        x += h[i];
        x.erase(x.begin());
        if (mark[i]) ans.insert(x);
    }
    cout << ans.size() << endl;
    return 0;
}
 
/*
    
*/