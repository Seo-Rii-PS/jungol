//
// Created by Seo_Hyun on 2020-01-02.
//

#include<bits/stdc++.h>

using namespace std;

bool isFilled[16][16];
set<pair<int, int>> box, fin;
pair<int, int> player;
int n, m, cnt;

int getSize(int s) {
    if (s > 0) return 1;
    if (s < 0) return -1;
    return 0;
}

bool moveCharacter(pair<int, int> p) {
    auto res = make_pair(player.first + p.first, player.second + p.second);
    if (res.first < 0 || res.first >= n) return false;
    if (res.second < 0 || res.second >= m) return false;
    if (!isFilled[res.first][res.second]) {
        player = res;
        return true;
    } else {
        auto b = box.find(res);
        if (b == box.end()) return false;
        if (isFilled[res.first + getSize(p.first)][res.second + getSize(p.second)]) return false;
        box.erase(b);
        box.insert(make_pair(res.first + getSize(p.first), res.second + getSize(p.second)));
        isFilled[res.first][res.second] = false;
        isFilled[res.first + getSize(p.first)][res.second + getSize(p.second)] = true;
        cnt += fin.find(res) != fin.end();
        cnt -= fin.find(make_pair(res.first + getSize(p.first), res.second + getSize(p.second))) != fin.end();
        player = res;
        return true;
    }
}

int main() {
    char t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &t);
            if (t == '#' || t == 'b' || t == 'B') isFilled[i][j] = true;
            if (t == '+' || t == 'B' || t == 'W') fin.insert(make_pair(i, j));
            if (t == 'b' || t == 'B') box.insert(make_pair(i, j));
            if (t == 'w' || t == 'W') player = make_pair(i, j);
            if (t == 'B') --cnt;
        }
    }
    cnt += box.size();
    fflush(stdin);
    while (true) {
        scanf("%c", &t);
        if (t == 10 || t == 13) break;
        if (t == 'U') moveCharacter(make_pair(-1, 0));
        if (t == 'D') moveCharacter(make_pair(1, 0));
        if (t == 'L') moveCharacter(make_pair(0, -1));
        if (t == 'R') moveCharacter(make_pair(0, 1));
    }
    if (cnt) printf("incomplete\n");
    else printf("complete\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool isBox = box.find(make_pair(i, j)) != box.end(), isFin =
                    fin.find(make_pair(i, j)) != fin.end(), isUser = player == make_pair(i, j);
            if (isBox && isFin) printf("B");
            else if (isUser && isFin) printf("W");
            else if (isBox) printf("b");
            else if (isUser) printf("w");
            else if (isFin) printf("+");
            else if (isFilled[i][j]) printf("#");
            else printf(".");
        }
        printf("\n");
    }
}