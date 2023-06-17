//02:42:50
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
 

 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); freopen("cube.out", "w", stdout);
    for (int i = 100; i < 1000; i++) {
        int x = i;
        int sum = 0;
        while (x) {
            sum += (x % 10) * (x % 10) * (x % 10);
            x /= 10;
        }
        if (sum == i) {
            cout << i << '\n';
        }
    }
    return 0;
}
 
/*
    
*/