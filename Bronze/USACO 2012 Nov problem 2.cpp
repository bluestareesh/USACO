#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;
# define int ll
int32_t main(void) {
    freopen("typo.in","r",stdin);
    freopen("typo.out","w",stdout);
    string s;
    cin >> s;
    int le_count = 0;
    int ri_count = 0;
    for (char i : s) {
        if (i == '(') {
            le_count += 1;
        }
        else {
            ri_count += 1;
        }
    }
    if (le_count == ri_count) {
        cout << "0\n";
    }
    else {
        set<int> answer;
        int one = 0;
        int two = 0;
        int pos = 0 ;
        if (le_count > ri_count) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ')') {
                    two += 1;
                }
                else {
                    one += 1;
                    pos = i;
                }
                if (two > one) {
                    continue;
                }
                else if (two+1 <= one-1) {
                    //cout << pos << '\n';
                    answer.insert(pos);
                }
            }
        }
        else {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ')') {
                    two += 1;
                    pos = i;
                }
                else {
                    one += 1;
                }
                if (two-1 > one) {
                    continue;
                }
                else if (two-1 <= one+1 && two != 0) {
                    //cout << pos << '\n';
                    answer.insert(pos);
                }
            }
        }
        cout << answer.size() << '\n';
    }
}
