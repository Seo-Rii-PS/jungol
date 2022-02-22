//2021 SEORII®. All right reserved.
//Code created on 2021-12-22

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<int> vec;
    int n;
    cin >> n;
    vec.resize(n);
    for (auto &i: vec) cin >> i;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        auto it = lower_bound(vec.begin(), vec.end(), a);
        if (*it == a) cout << it - vec.begin() << ' ';
        else cout << "-1" << ' ';
    }
    return 0;
}
