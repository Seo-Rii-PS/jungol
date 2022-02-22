//2021 SEORII®. All right reserved.
//Code created on 2021-12-21

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            string a, b;
            cin >> a >> b;
            ++mp[b];
        }
        int ans = 1;
        for (auto&[k, v]: mp) {
            ans *= (v + 1);
        }
        cout << ans - 1 << endl;
    }
    return 0;
}