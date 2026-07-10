#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
struct St {
    ll i;
    bool f;
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m, u, v;
    
    cin >> n >> m >> u >> v;
 
    vector<St> sts(n);
    for (ll i = 0; i < n; i++) {
        sts[i].i = i;
        sts[i].f = true;
    }
 
    vector<vector<St*>> vv(n);
 
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        vv[x - 1].push_back(&sts[y - 1]);
        vv[y - 1].push_back(&sts[x - 1]);
    }
 
    if (u == v) {
        cout << v << '\n';
        return 0;
    }
 
    stack<St*> st;
    st.push(&sts[u - 1]);
    sts[u - 1].f = false;
 
    while (!st.empty()) {
        St* x = st.top();
        bool f = false;
        for (St* y : vv[x->i]) {
            if (y->i == v - 1) {
                stack<St*> nst;
                st.push(y);
                while (!st.empty()) {
                    nst.push(st.top());
                    st.pop();
                }
                while (!nst.empty()) {
                    cout << nst.top()->i + 1 << ' ';
                    nst.pop();
                }
                cout << '\n';
                return 0;
            }
            if (y->f) {
                y->f = false;
                st.push(y);
                f = true;
                break;
            }
        }
        if (f) continue;
        st.pop();
    }
    
    cout << -1 << '\n';
 
    return 0;
}
