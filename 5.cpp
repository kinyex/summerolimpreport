#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const ll c = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    
    cin >> n;
 
    ll a = 1;
 
    for (ll i = 3; i < n; i++) {
        a = a * i % c;
    }
 
    cout << a << '\n';
 
    return 0;
}
