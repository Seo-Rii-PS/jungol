//2021 SEORII®. All right reserved.
//Code created on 2021-12-22

#include<bits/stdc++.h>

int main() {
    int m, c, d = 0;
    scanf("%d %*d %d", &m, &c);
    std::vector<int> v(c), b(c - 1);
    for (int i = 0; i < c; ++i) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for (int i = 1; i < c; ++i) b[i - 1] = v[i] - v[i - 1] - 1;
    sort(b.begin(), b.end(), std::greater<int>());
    for (int i = 0; i < std::min(m - 1, c - 1); ++i) d -= b[i];
    printf("%d\n", std::max(0, d + v[c - 1] - v[0] + 1));
}