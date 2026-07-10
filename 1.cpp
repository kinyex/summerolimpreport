#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    long long n;
    vector<vector<int>> vv;
 
    cin >> n;
    
    for (long long i = 0; i < n; i++) {
        int m, k = 0;
        cin >> m;
        vector<int> v;
        for (long long i = 0; i < m; i++) {
            int el;
            cin >> el;
            v.push_back(el);
        }
 
        bool f = true;
        while (f) {
            f = false;
            for (int j = 0; j < m - 1; j++) {
                if (v[j] > v[j + 1]) {
                    int tmp = v[j + 1];
                    v[j + 1] = v[j];
                    v[j] = tmp;
                    k++;
                    f = true;
                }
            }
        }
 
        cout << k << '\n';
    }
 
    return 0;
}
