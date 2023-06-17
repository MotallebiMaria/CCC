//00:07:05
//done
//no sample input output files; assumed solved
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
 
int sum;
 
int32_t main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    sum = 1;
    int pos = 1;
    while (sum != 0) {
        cout << "Enter sum of dice:" << endl;
        cin >> sum;
        if (!sum) {
            cout << "You Quit!" << endl;
            break;
        }
        if (pos + sum <= 100) pos += sum;
        if (pos == 54) pos = 19;
        else if (pos == 90) pos = 48;
        else if (pos == 99) pos = 77;
        else if (pos == 9) pos = 34;
        else if (pos == 40) pos = 64;
        else if (pos == 67) pos = 86;
        cout << "You are now on square " << pos << '\n';
        if (pos == 100) {
            cout << "You Win!" << endl;
            break;
        }
    }
    return 0;
}
 
/*
    
*/