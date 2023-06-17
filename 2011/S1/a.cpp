//
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
 
int n, tcnt, scnt;
string s;
 
int32_t main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    getline(cin, s);
    while (n --) {
        getline(cin, s);
        for (int i = 0;  i< s.size(); i ++) {
            if (s[i] == 't' || s[i] == 'T') tcnt++;
            else if (s[i] == 's' || s[i] == 'S') scnt++;
        }
    }
    if (tcnt > scnt)
        cout << "English";
    else
        cout << "French";
    cout << endl;
    return 0;
}
 
/*

*/