//00:10:16
//done
//little worried about the time limit; 
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
 
int n;
vector <string> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("substr.in", "r", stdin); freopen("substr.out", "w", stdout);
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        v.clear();
        for (int i = 0; i < s.size(); i ++) {
            string sub = "";
            for (int j = i; j < s.size(); j ++) {
                sub += s[j];
                v.pb(sub);
            }
        }
        sort(all(v));
        int cnt = 2;
        for (int i = 1; i < v.size(); i ++) {
            if (v[i] != v[i - 1]) cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}
 
/*
    
*/