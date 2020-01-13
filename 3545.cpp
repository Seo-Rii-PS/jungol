//
// Created by Seo_Hyun on 2020-01-01.
//

#include<bits/stdc++.h>

using namespace std;

const int arrSize = 32768;

unsigned char byteArr[arrSize];
unsigned char *ptr = byteArr;
int pairSet[128001];
string str;
stack<int> stk;

int main() {
    char t;
    bool ign = false;
    while (scanf("%c", &t) != EOF) {
        if (t == 10 || t == 13) ign = false;
        if (t == '%') ign = true;
        if (ign) continue;
        if (t == '[') stk.push(str.length());
        if (t == ']') {
            if (stk.empty()) {
                printf("COMPILE ERROR\n");
                return 0;
            }
            pairSet[str.length()] = stk.top();
            pairSet[stk.top()] = str.length();
            stk.pop();
        }
        str += t;
    }
    if (!stk.empty()) {
        printf("COMPILE ERROR\n");
        return 0;
    }
    for (int i = 0; i < str.length(); ++i) {
        //printf("%d\n", i);
        t = str[i];
        if (t == '>') {
            ++ptr;
            if (ptr == byteArr + arrSize) ptr = byteArr;
        }
        if (t == '<') {
            --ptr;
            if (ptr < byteArr) ptr = byteArr + arrSize - 1;
        }
        if (t == '+') {
            if (*ptr == UCHAR_MAX) *ptr = 0;
            else ++(*ptr);
        }
        if (t == '-') {
            if (*ptr == 0) *ptr = UCHAR_MAX;
            else --(*ptr);
        }
        if (t == '.') printf("%c", (char) (*ptr));
        if (t == '[' || t == ']') {
            if ((*ptr != 0) ^ (t == ']')) continue;
            else i = pairSet[i];
        }
    }
    return 0;
}