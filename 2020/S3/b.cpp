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

string n, h;
map <char, int> cntn, cnth;
map <size_t, bool> used;

bool perm(map <char, int> m1, map <char, int> m2) {
    for (int i = 0; i < 26; i ++) {
        char let = 'a' + i;
        if (m1[let] != m2[let]) return false;
    }
    return true;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> h;
    for (int i = 0; i < n.size(); i ++) cntn[n[i]] ++;
    int cnt = 0;
    for (int i = 0; i < h.size() - n.size() + 1; i ++) {
        string sub = h.substr(i, n.size());
        if (i == 0) {
            for (int j = 0; j < h.size(); j ++) {
                cnth[sub[j]] ++;
            }
        }
        else {
            char rem = h[i - 1], add = h[i + sub.size() - 1];
            cnth[add] ++, cnth[rem] --;
        }
        hash <string> hasher;
        size_t hash = hasher(sub);
        if (!used[hash] && perm(cntn, cnth)) {
            cnt ++;
            used[hash] = true;
        }
    }
    cout << cnt << endl;
    return 0;
}
 
/*
    
*/