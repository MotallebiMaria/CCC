//02:53:30
//solved;
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
 
int q;
 
int32_t main() {
    freopen("censor.in", "r", stdin); freopen("censor.out", "w", stdout);
    cin >> q;
    string s;
    getline(cin, s);
    while (q--) {
        getline(cin, s);
        string word = "";
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == ' ') {
                if (word.size() == 4)
                    word = "****";
                cout << word << " ";
                word = "";
            }
            else word += s[i];
        }
        if (word.size() == 4)
            word = "****";
        cout << word << "\n\n";
    }
    return 0;
}
 
/*
    
*/