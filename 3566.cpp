//
// Created by Seo_Hyun on 10-Jan-20.
//

#include<cstdio>
#include<vector>

using namespace std;

int n, q;
vector<long long> in, v, prod, acc;

long long gs(long long to) {
    if (!to) return 0;
    return v[to] + gs(to - (to & -to));
}

long long gAcc(long long s) {
    long long i = s, p = acc[s];
    while ((i -= i & -i)) p += acc[i];
    return p;
}

long long gProd(long long s) {
    long long i = s, p = prod[s];
    while ((i -= i & -i)) p += prod[i];
    return p;
}

void addAcc(long long l, long long r, long long s) {
    long long i = l;
    acc[i] += s;
    while ((i += (i & -i)) <= n)
        acc[i] += s;
    if (r == n) return;
    i = r + 1;
    acc[i] -= s;
    while ((i += (i & -i)) <= n)
        acc[i] -= s;
}

void addProd(long long l, long long r, long long s) {
    long long i = l;
    prod[i] += s;
    while ((i += (i & -i)) <= n)
        prod[i] += s;
    if (r == n) return;
    i = r + 1;
    prod[i] -= s;
    while ((i += (i & -i)) <= n)
        prod[i] -= s;
}

int main() {
    scanf("%d %d", &n, &q);
    v.resize(n + 1);
    acc.resize(n + 1);
    prod.resize(n + 1);
    in.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &in[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int j = i;
        v[j] += in[i];
        while ((j += j & -j) <= n) v[j] += in[i];
    }
    for (int i = 0; i < q; ++i) {
        long long t, a, b, c;
        scanf("%lld %lld", &t, &a);
        if (t < 3) scanf("%lld %lld", &b, &c);
        if (t == 1) addAcc(a, b, c);
        if (t == 2) {
            addAcc(a, b, -1 * c * a);
            addProd(a, b, c);
        }
        if (t == 3) printf("%lld\n", gs(a) - gs(a - 1) + gAcc(a) + a * gProd(a));
    }
}
