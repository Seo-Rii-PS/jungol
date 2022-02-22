//
// Created by Seo_Hyun on 20-Jan-20.
//

#include<bits/stdc++.h>

using namespace std;

long long n, ar1, ar2, lax;
vector<tuple<long long, long long, long long>> v;
vector<tuple<long long, bool, long long>> l;
multiset<long long> curr;

int main() {
    cin >> n;
    v.resize(n);
    l.reserve(n * 2 + 2);
    for (auto &i:v) {
        cin >> get<0>(i) >> get<1>(i) >> get<2>(i);
        l.push_back(make_tuple(get<0>(i), true, get<2>(i)));
        l.push_back(make_tuple(get<1>(i), false, get<2>(i)));
    }
    sort(l.begin(), l.end());
    for (auto i:l) {
        long long x, h;
        bool ty;
        tie(x, ty, h) = i;
        if (!lax) lax = x;
        if (!curr.empty()) ar1 += (*(--curr.end())) * (x - lax);
        if (!curr.empty()) ar2 += (*(--curr.end())) * (x - lax);
        if (curr.size() > 1) ar2 -= (*(--(--curr.end()))) * (x - lax);
        lax = x;
        if (ty) curr.insert(h);
        else curr.erase(curr.find(h));
    }
    cout << ar1 << endl << ar2 << endl;
}