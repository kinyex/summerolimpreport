#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
struct St {
    ll v;
    ll i;
};
 
bool foo(St a, St b) {
    return a.v < b.v;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n, m;
    vector<St> v;
 
    cin >> n >> m;
 
    for (ll i = 0; i < n; i++) {
        St el;
        el.i = i + 1;
        cin >> el.v;
        v.push_back(el);
    }
 
    sort(v.begin(), v.end(), foo);
 
    for (int i = 0; i < n; i++) {
        if (m <= v[i].v) {
            cout << "NO" << '\n';
            return 0;
        }
        m += v[i].v;
    }
 
    cout << "YES" << '\n';
    for  (auto el : v) {
        cout << el.i << ' ';
    }
    cout << '\n';
 
    return 0;
}
