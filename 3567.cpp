//
// Created by Seo_Hyun on 10-Jan-20.
//

#include<cstdio>
#include<vector>
#include <algorithm>

using namespace std;

int n, q, n2 = 1;
vector<int> v;

void upd(int p) {
    if (!p) return;
    v[p] = max(v[p * 2], v[p * 2 + 1]);
    upd(p / 2);
}

int findl(int p, int s) {
    if(p==1) return -1;
    p += n2 - 2;
    while (1) {
        if (v[p] > s) break;
        if (__builtin_popcount(p) == 1) return -1;
        if (p % 2 == 0) {
            --p;
            continue;
        }
        p /= 2;
    }
    while (1) {
        if (p >= n2) break;
        if (v[p * 2 + 1] > s) p = p * 2 + 1;
        else p <<= 1;
    }
    return p - n2 + 1;
}

int findr(int p, int s) {
    if(p==n) return -1;
    p += n2;
    while (1) {
        if (v[p] > s) break;
        if (__builtin_popcount(p + 1) == 1) return -1;
        if (p % 2 != 0) {
            ++p;
            continue;
        }
        p /= 2;
    }
    while (1) {
        if (p >= n2) break;
        if (v[p * 2] > s) p <<= 1;
        else p = p * 2 + 1;
    }
    return p - n2 + 1;
}

int main() {
    scanf("%d %d", &n, &q);
    while (n2 < n) n2 *= 2;
    n2 *= 2;
    v.resize(n2 * 2 + 1);
    for (int i = n2 * 2; i > 0; --i) {
        v[i] = -2100000000;
    }
    for (int i = n2; i < n2 + n; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = n2 - 1; i > 0; --i) {
        v[i] = max(v[i * 2], v[i * 2 + 1]);
    }
    for (int i = 0; i < q; ++i) {
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        if (t == 1) printf("%d\n", findr(a, b));
        if (t == 2) printf("%d\n", findl(a, b));
        if (t == 3) {
            v[n2 + a - 1] = b;
            upd((n2 + a - 1) / 2);
        }
    }
}