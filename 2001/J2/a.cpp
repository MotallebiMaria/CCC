//00:06:51
//-00:18:16
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
 
int x, m;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> x >> m;
    int ans = 1;
    while ((x * ans) % m != 1 && ans < m) {
        ans ++;
    }
    if (ans < m)
        cout << ans << endl;
    else
        cout << "No such integer exists." << endl;
    return 0;
}
 
/*
    
*/