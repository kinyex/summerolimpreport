#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
struct Node {
    ll i;
    ll d;
    vector<pair<ll, ll>> c;
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll t;
    
    cin >> t;
 
    for (ll ti = 0; ti < t; ti++) {
        ll n, m, k, d;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        
        cin >> n >> m >> k >> d;
 
        vector<Node> nodes(n);
        for (ll i = 0; i < n; i++) {
            Node* node = &nodes[i];
            node->i = i;
            node->d = d + 1;
        }
 
        for (ll i = 0; i < k; i++) {
            ll x;
            cin >> x;
            nodes[x - 1].d = 0;
            pq.push({0, x - 1});
        }
 
        for (ll i = 0; i < m; i++) {
            ll a, b, w;
            cin >> a >> b >> w;
            if (w > d) continue;
            nodes[b - 1].c.push_back({a - 1, w});
        }
 
        while (!pq.empty()) {
            ll x = pq.top().first;
            Node* node = &nodes[pq.top().second];
            pq.pop();
            if (x > node->d) continue;
            for (pair<ll, ll> p : node->c) {
                Node* nnode = &nodes[p.first];
                ll w = p.second;
                if (node->d + w <= d && nnode->d > node->d + w) {
                    nnode->d = node->d + w;
                    pq.push({nnode->d, nnode->i});
                }
            }
        }
        
        for (ll i = 0; i < n; i++) {
            if (nodes[i].d <= d) {
                cout << i + 1 << ' ';
            }
        }
        cout << '\n';
 
    }
 
    
 
    return 0;
}
