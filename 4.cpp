#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n, s = 0;
    vector<ll> v, vv;
 
    cin >> n;
 
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
        vv.push_back(x);
        s += x;
    }
 
    for (ll i = 1; i < n; i++) {
        vector<ll> vvv;
        for (ll j = 0; j < n - i; j++) {
            ll x = max(vv[j], v[j + i]);
            vvv.push_back(x);
            s += x;
        }
        for (ll j = 0; j < n - i; j++) {
            vv[j] = vvv[j];
        }
    }
 
    cout << s << '\n';
 
    return 0;
}
