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
    return new node(l->val || r->val, l, r);
}

node *createNode(int v) {
    return new node(v);
}

vector<int> d;
vector<node *> root;
int n, n2 = 1, q;

int main() {
    vector<node *> v, nv;
    vector<vector<node*>> nowTree;
    vector<bool> up, nup;
    int t, ma=0, ci=0, cj=0;
    scanf("%d %d", &n, &q);
    while (n2 < n) n2 <<= 1;
    n2 <<= 1;
    d.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &d[i]);
        ma=max(d[i], ma);
    }
    nowTree.resize(1);
    for (int i = 0; i < n; ++i) {
        node* tNode;
        if (d[i] == 1) tNode=createNode(1);
        else tNode=createNode(0);
        v.push_back(tNode);
        nowTree[0].push_back(tNode);
    }
    while (v.size() > 1) {
        nowTree.push_back(vector<node*>());
        ++ci;
        nv = v;
        v.clear();
        for (int i = 0; i < nv.size(); i += 2) {
            auto tNode=createNode(nv[i], nv[i + 1]);
            v.push_back(tNode);
            nowTree[ci].push_back(tNode);
        }
        if (nv.size() % 2 == 1) v.push_back(nv[nv.size() - 1]);
    }
    root.push_back(v[0]);

}