//
// Created by Seo_Hyun on 11-Jan-20.
//

#include<bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    int val;
};

int n, h, q, n2 = 1, unc, tar, l, r;
int root[1000002];
node nodes[23000005];
int his[1000002], db[1000002];

int createNode(int l, int r) {
    nodes[++unc].l = l;
    nodes[unc].r = r;
    if (l != -1) nodes[unc].val = nodes[l].val;
    if (r != -1) nodes[unc].val += nodes[r].val;
    return unc;
}

int createNode(int v) {
    nodes[++unc].val = v;
    return unc;
}

int createFirstTree(int l = 0, int r = n2) {
    if (l == r) {
        if (l >= n) return -1;
        if (l == tar) return createNode(1);
        else return createNode(0);
    }
    int lt = createFirstTree(l, (l + r) / 2), rt = createFirstTree((l + r) / 2 + 1, r);
    if (lt == -1 && rt == -1) return -1;
    return createNode(lt, rt);
}

int createTree(int laTree, int nh = 0) {
    if (laTree == -1) return -1;
    if (nh == h) return createNode((nodes[laTree].val) + 1);
    if (tar & (1 << (h - nh - 1))) return createNode(nodes[laTree].l, createTree(nodes[laTree].r, nh + 1));
    else return createNode(createTree(nodes[laTree].l, nh + 1), nodes[laTree].r);
}

int queryTree(int tree, int tl = 0, int tr = n2) {
    // 1<<(h-nh-1)
    if (tree == -1) return 0;
    if (tr < l) return 0;
    if (r < tl) return 0;
    if (l <= tl && r >= tr) return nodes[tree].val;
    return queryTree(nodes[tree].l, tl, (tl + tr) / 2) + queryTree(nodes[tree].r, (tl + tr) / 2 + 1, tr);
}


int main() {
    scanf("%d %d", &n, &q);
    int tn = n - 1;
    while (tn) {
        tn >>= 1;
        ++h;
    }
    while (n > n2) n2 <<= 1;
    --n2;
    int t;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if (his[t]) db[his[t] - 1] = i;
        his[t] = i + 1;
    }
    tar = db[0] - 1;
    root[0] = createFirstTree();
    for (int i = 1; i <= n; ++i) {
        if (db[i] == 0) {
            root[i] = root[i - 1];
            continue;
        }
        tar = db[i];
        root[i] = createTree(root[i - 1]);
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        l = a;
        r = b;
        if (!a) {
            if (!b)printf("%d\n", (b - a + 1));
            else printf("%d\n", (b - a + 1) - (queryTree(root[b])));
        } else printf("%d\n", (b - a + 1) - (queryTree(root[b]) - queryTree(root[a - 1])));
    }
}
