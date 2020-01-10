//
// Created by Seo_Hyun on 2020-01-04.
//

#include<bits/stdc++.h>

using namespace std;

int n, m;
unsigned char v[102][102], d[102][102][102][102];

int main() {
    scanf("%d %d", &n, &m);
    char t;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &t);
            if (t == '*') v[i][j] = 1;
            if (t == '#') v[i][j] = 2;
        }
    }
    d[0][0][0][0] = 1 + (v[0][0] == 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                for (int l = 0; l < n; ++l) {
                    if (!d[i][j][k][l]) continue;
                    if (v[i + 1][j] != 2) d[i + 1][j][k][l] = max((unsigned char) d[i + 1][j][k][l],
                                                                  (unsigned char) (d[i][j][k][l] +
                                                                                   (unsigned char) ((v[i + 1][j]) &&
                                                                                                    (i + 1 > k ||
                                                                                                     j > l))));
                    if (v[i][j + 1] != 2) d[i][j + 1][k][l] = max((unsigned char) d[i][j + 1][k][l],
                                                                  (unsigned char) (d[i][j][k][l] +
                                                                                   (unsigned char) ((v[i][j + 1]) &&
                                                                                                    (i > k ||
                                                                                                     j + 1 > l))));
                    if (v[k + 1][l] != 2) d[i][j][k + 1][l] = max((unsigned char) d[i][j][k + 1][l],
                                                                  (unsigned char) (d[i][j][k][l] +
                                                                                   (unsigned char) ((v[k + 1][l]) &&
                                                                                                    (k + 1 > i ||
                                                                                                     l > j))));
                    if (v[k][l + 1] != 2) d[i][j][k][l + 1] = max((unsigned char) d[i][j][k][l + 1],
                                                                  (unsigned char) (d[i][j][k][l] +
                                                                                   (unsigned char) ((v[k][l + 1]) &&
                                                                                                    (k > i ||
                                                                                                     l + 1 > j))));
                }
            }
        }
    }
    printf("%d\n", d[m - 1][n - 1][m - 1][n - 1] - 1);
}