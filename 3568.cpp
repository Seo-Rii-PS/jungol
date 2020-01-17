//
// Created by Seo_Hyun on 11-Jan-20.
//

#include<bits/stdc++.h>

using namespace std;

struct node {
    node *l, *r;
    int val;

    node() {}

    node(int _v) {
        val = _v;
    }

    node(int _v, node *_l, node *_r) {
        val = _v;
        l = _l;
        r = _r;
    }
};

node *createNode(node *l, node *r) {
    if (l == nullptr) return new node(r->val, l, r);
    if (r == nullptr) return new node(l->val, l, r);
    return new node(l->val + r->val, l, r);
}

node *createNode(int v) {
    return new node(v);
}

int n, h, q, n2 = 1;
vector<int> v;
vector<node *> root;
unordered_map<int, int> his;
vector<int> db;

int gHeight(int s) {
    return 32 - __builtin_clz(s);
}

node *createTree(int tar, node *laTree, int nh = 0) {
    if (laTree == nullptr) return nullptr;
    if (nh == h) return createNode((laTree->val) + 1);
    node *nl = laTree->l, *nr = laTree->r;
    if (tar & (1 << (h - nh - 1))) nr = createTree(tar, laTree->r, nh + 1);
    else nl = createTree(tar, laTree->l, nh + 1);
    return createNode(nl, nr);
}

void updTree(int tar, node *tree, int nh = 0) {
    if (nh == h) {
        tree->val = tree->val + 1;
        return;
    }
    if (tar & (1 << (h - nh - 1))) updTree(tar, tree->r, nh + 1);
    else updTree(tar, tree->l, nh + 1);
    tree->val = (tree->l->val) + (tree->r->val);
}

int queryTree(int l, int r, node *tree, int tl = 0, int tr = n2) {
    // 1<<(h-nh-1)
    if (tr < l) return 0;
    if (r < tl) return 0;
    if (l <= tl && r >= tr) return tree->val;
    return queryTree(l, r, tree->l, tl, (tl + tr) / 2) + queryTree(l, r, tree->r, (tl + tr) / 2 + 1, tr);
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
    v.resize(n);
    db.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        if (his[v[i]]) db[his[v[i]] - 1] = i;
        his[v[i]] = i + 1;
    }
    vector<node *> tv, nv;
    for (int i = 0; i < n; ++i) nv.push_back(createNode((i) && (i == db[0])));
    while (nv.size() > 1) {
        tv = nv;
        nv.clear();
        for (int i = 0; i < tv.size() / 2 * 2; i += 2) nv.push_back(createNode(tv[i], tv[i + 1]));
        if (tv.size() % 2) nv.push_back(createNode(tv.back(), nullptr));
    }
    root.push_back(nv[0]);
    for (int i = 1; i <= n; ++i) {
        if (db[i] == 0) {
            root.push_back(root.back());
            continue;
        }
        root.push_back(createTree(db[i], root.back()));
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        if (!a) {
            if (!b)printf("%d\n", (b - a + 1));
            else printf("%d\n", (b - a + 1) - (queryTree(a, b, root[b])));
        } else printf("%d\n", (b - a + 1) - (queryTree(a, b, root[b]) - queryTree(a, b, root[a - 1])));
    }
}