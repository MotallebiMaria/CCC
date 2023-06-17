//00:03:36
//done
//tc3; mistake1: didn't check for end of string matching
//-00:03:00 mistake1 fixed
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
string s[5];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        for (int i = 0; i < 3; i ++) cin >> s[i];
        string ans = "Yes";
        for (int i = 0; i < 3; i ++) {
            string word = "";
            for (int j = 0 ;j  < s[i].size(); j ++) {
                word += s[i][j];
                for (int k = 0; k < 3; k ++) {
                    if (k != i && s[k] == word) {
                        ans = "No";
                        break;
                    }
                }
            }
            word = "";
            for (int j = s[i].size() - 1; j >= 0; j --) {
                word += s[i][j];
                for (int k = 0; k < 3; k ++) {
                    string x = s[k];
                    reverse(all(x));
                    if (k != i && x == word) {
                        ans = "No";
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
 
/*
    
*/