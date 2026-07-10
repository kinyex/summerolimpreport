#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n, m;
    vector<ll> vx;
 
    cin >> n >> m;
 
    for (ll i = 0; i < n * m; i++) {
        ll x;
        cin >> x;
        vx.push_back(x);
    }
 
    for (ll i = 1; i < n * m; i++) {
        ll s = 0;
 
        if (i - 1 >= 0 && i % m != 0) s = vx[i - 1];
        if (i - m - 1 >= 0 && i % m != 0) s = max(s, vx[i - 1]);
        if (i - m >= 0) s = max(s, vx[i - m]);
 
        vx[i] += s;
    }
 
    cout << vx[n * m - 1];
 
 
    cout << '\n';
 
    return 0;
}
