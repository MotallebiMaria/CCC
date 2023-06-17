//00:10:47; done
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
 
string s;
int val[30];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> s;
    val['I' - 'A'] = 1, val['V' - 'A'] = 2, val['X' - 'A'] = 3, val['L' - 'A'] = 4, val['C' - 'A'] = 5, val['D' - 'A'] = 6, val['M' - 'A'] = 7;
    int ans = 0;
    for (int i = s.size() - 2; i >= 0; i -= 2) {
        int num = s[i] - '0';
        char c = s[i + 1];
        if (c == 'V') num *= 5;
        else if (c == 'X') num *= 10;
        else if (c == 'L') num *= 50;
        else if (c == 'C') num *= 100;
        else if (c == 'D') num *= 500;
        else if (c == 'M') num *= 1000;
        if (i < s.size() - 2 && val[c - 'A'] < val[s[i + 3] - 'A'])
            ans -= num;
        else ans += num;
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/