//00:03:05
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
 
int n, d;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> d;
    int gcd = __gcd(n, d);
    n /= gcd, d /= gcd;
    cout << n / d;
    if (n % d) {
        cout << " " << n - (n / d) * d << "/" << d;
    }
    cout << endl;
    return 0;
}
 
/*
    
*/