//00:12:00
//-00:00:50
//done
//solved
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
 
int p, g, r, o, tot, mint;
set <pair <int, pair <int, pair <int, int>>>> s;

void hehe(int a, int b, int c, int d, int sum) {
    if (sum > tot) return;
    if (sum == tot) {
        s.insert(mp(a, mp(b, mp(c, d))));
        mint = min(mint, a + b + c + d);
        return;
    }
    hehe(a + 1, b, c, d, sum + p);
    hehe(a, b + 1, c, d, sum + g);
    hehe(a, b, c + 1, d, sum + r);
    hehe(a, b, c, d + 1, sum + o);
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> p >> g >> r >> o >> tot;
    mint = INF;
    hehe(0, 0, 0, 0, 0);
    for (auto it = s.begin(); it != s.end(); it ++) {
        cout << "# of PINK is " << (*it).first << " ";
        cout << "# of GREEN is " << (*it).second.first << " ";
        cout << "# of RED is " << (*it).second.second.first << " ";
        cout << "# of ORANGE is " << (*it).second.second.second << " ";
        cout << '\n';
    }
    cout << "Total combinations is " << s.size() << ".\n";
    cout << "Minimum number of tickets to print is " << mint << "." << endl;
    return 0;
}
 
/*
    
*/