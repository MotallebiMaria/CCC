//00:14:52
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
 
int d, m;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> d >> m;
    int day = d * -1 + 2;
    cout << "Sun Mon Tue Wed Thr Fri Sat\n";
    while (day <= m) {
        for (int j = 0; j < 7; j ++) {
            if (day > m) break;
            if (day <= 0)
                cout << "    ";
            else if (day < 10)
                cout << "  " << day << " ";
            else
                cout << " " << day << " ";
            day ++;
        }
        cout << '\n';
    }
    cout << endl;
    return 0;
}
 
/*
    
*/