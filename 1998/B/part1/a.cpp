//02:44:44
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
    freopen("perfect.in", "r", stdin); freopen("perfect.out", "w", stdout);
    for (int i = 1000; i < 10000; i ++) {
        int sum = 1;
        for (int j = 2; j * j <= i; j ++) {
            if (i % j == 0) {
                sum += j;
                if (i / j != j)
                    sum += i / j;
            }
        }
        if (sum == i) {
            cout << i << '\n';
        }
    }
    return 0;
}
 
/*
    
*/