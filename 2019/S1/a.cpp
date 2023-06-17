//00:04:57; done; 15/15
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

string s;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> s;
    int cnth, cntv; cnth = cntv = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'H') cnth ++;
        else cntv ++;
    }
    cnth &= 1, cntv &= 1;
    if (cnth && cntv)
        cout << "4 3\n2 1";
    else if (cnth)
        cout << "3 4\n1 2";
    else if (cntv)
        cout << "2 1\n4 3";
    else
        cout << "1 2\n3 4";
    cout << endl;
    return 0;
}
 
/*
    
*/