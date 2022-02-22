//
// Created by Seo_Hyun on 2020-01-04.
//

#include<bits/stdc++.h>

using namespace std;

int n, m, t, ma;
vector<vector<bool>> d;

int main() {
    scanf("%d %d", &n, &m);
    d = vector<vector<bool>>(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        t %= m;
        d[i][t] = true;
        d[i][0] = true;
        ma = max(ma, t);
        for (int j = 0; j < i - 1; ++j) {
            for (int k = 0; k < m - t; ++k) {
                if (d[j][k]) {
                    d[i][k + t] = true;
                    ma = max(ma, k + t);
                }
            }
        }
    }
    printf("%d", ma);
}