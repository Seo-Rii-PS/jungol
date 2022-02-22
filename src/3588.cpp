//
// Created by Seo_Hyun on 01-Feb-20.
//

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> T;
unordered_map<int, int> reMap;
vector<tuple<int, bool, T>> v;
vector<int> yAxis;
vector<T> tr;
int n, n2 = 1;

void updTree(int pl, int add, int s, int e, int l = 0, int r = n2 - 1) {
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        tr[pl].second += add;
        tr[pl].first = tr[pl].second ? (yAxis[r + 1] - yAxis[l]) : (pl < n2 ? tr[pl * 2].first + tr[pl * 2 + 1].first
                                                                            : 0);
        return;
    }
    updTree(pl * 2, add, s, e, l, (l + r) / 2);
    updTree(pl * 2 + 1, add, s, e, (l + r) / 2 + 1, r);
    tr[pl].first = tr[pl].second ? (yAxis[r + 1] - yAxis[l]) : tr[pl * 2].first + tr[pl * 2 + 1].first;
}

int main() {
    scanf("%d", &n);
    while (n2 < n) n2 *= 2;
    n2 *= 2;
    tr.resize(n2 * 2);
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        v.emplace_back(a, false, make_pair(b, d));
        v.emplace_back(c, true, make_pair(b, d));
        yAxis.emplace_back(b);
        yAxis.emplace_back(d);
    }
    sort(yAxis.begin(), yAxis.end());
    yAxis.erase(unique(yAxis.begin(), yAxis.end()), yAxis.end());
    for (int i = 0; i < yAxis.size(); ++i) reMap[yAxis[i]] = i;
    sort(v.begin(), v.end());
    int x, lax = 0;
    long long ar = 0;
    bool ty;
    T range;
    for (auto i:v) {
        tie(x, ty, range) = i;
        ar += (long long) (x - lax) * tr[1].first;
        updTree(1, 1 - ty * 2, reMap[range.first], reMap[range.second] - 1);
        lax = x;
    }
    printf("%lld\n", ar);
}
