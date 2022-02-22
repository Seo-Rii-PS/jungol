//
// Created by Seo_Hyun on 20-Jan-20.
//

#include<bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

void wr(int tar, string s) {
    if (v[tar].length() > s.length()) v[tar] = s;
    if (v[tar].length() >= s.length() && v[tar] > s) v[tar] = s;
    if (v[tar].empty()) v[tar] = s;
}

int main() {
    v.resize(1001);
    v[1] = "12";
    v[2] = "34";
    v[3] = "56";
    for (int i = 4; i <= 1000; ++i) {
        if (i % 2 == 0) wr(i, "1" + v[i / 2] + "2");
        if (i % 3 == 0) wr(i, "3" + v[i / 3] + "4");
        if (i % 5 == 0) wr(i, "5" + v[i / 5] + "6");
        for (int j = 1; j <= i / 2; ++j) {
            wr(i, v[j] + v[i - j]);
            wr(i, v[i - j] + v[j]);
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        for (auto j:v[t]) {
            if (j == '1') cout << '(';
            if (j == '2') cout << ')';
            if (j == '3') cout << '{';
            if (j == '4') cout << '}';
            if (j == '5') cout << '[';
            if (j == '6') cout << ']';
        }
        cout << endl;
    }
}