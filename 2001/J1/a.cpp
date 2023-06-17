//00:03:09
//done
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
 
int h;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> h;
    for (int i = 1; i <= h; i += 2) {
        for (int j = 0; j < i; j ++) {
            cout << "*";
        }
        for (int j = 0; j < 2 * h - 2 * i; j ++) {
            cout << " ";
        }
        for (int j = 0; j < i; j ++) {
            cout << "*";
        }
        cout << '\n';
    }
    for (int i = h - 2; i > 0; i -= 2) {
        for (int j = 0; j < i; j ++) {
            cout << "*";
        }
        for (int j = 0; j < 2 * h - 2 * i; j ++) {
            cout << " ";
        }
        for (int j = 0; j < i; j ++) {
            cout << "*";
        }
        cout << '\n';
    }
    return 0;
}
 
/*
    
*/