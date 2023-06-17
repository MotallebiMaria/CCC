//02:37:57
//mistakes commented; understood official solution
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
vector <int> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("div.in", "r", stdin); freopen("div.out", "w", stdout);
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        v.clear();
        for (int i = 0; i < s.size(); i++) {
            v.pb(s[i] - '0');
        }
        string num = s;
        while (num.size() > 2) {
            cout << num << '\n';
            v[v.size() - 2] -= v.back();
            v.pop_back();
            if (v.back() < 0) {
                v.back() += 10;
                //v[v.size() - 2] --; //2: didn't consider v[v.size() - 2] == 0
                //2: added
                int ind = 2;
                while (v[v.size() - ind] == 0 && ind <= v.size()) {
                    v[v.size() - ind] = 9;
                    ind++;
                }
                v[v.size() - ind] --;
                //2: ended
            }
            //1: added
            bool b = false;
            //1: ended
            //4: added
            num = "";
            //4: ended
            for (int i = 0; i < v.size(); i++) { //1: didn't consider when v[v.size() - ind] becomes 0 after subtraction
                //1: added
                if (v[i] != 0) b = true;
                if (b) {
                    //4: added
                    num += char(v[i] + '0');
                    //4: ended
                }
                //1: ended
            } //4: might get 1 digit but still print it
            //4: added
            if (num.size() == 1) break;
            //4: ended;
        }
        cout << num << '\n';
        cout << "The number " << s << " is ";
        if (v.size() > 1 && (v[0] * 10 + v[1]) % 11 == 0) { //3: divisible by 11, not 11 itself (was v[0] == 1 && v[1] == 1)
            cout << "divisible";
        }
        else {
            cout << "not divisible";
        }
        cout << " by 11\n";
    }
    return 0;
}
 
/*
    
*/