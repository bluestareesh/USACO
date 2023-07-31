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
int n;
vector<pair<int,int>> x;
map<int,int> closest;
set<map<int,int>> count2;
int answer = 0;
void solve(map<int,int> pairs) {
    for (int i = 1; i <= n; i++) {
        int worm = i;
        for (int j = 0; j < n; j++) {
            worm = closest[pairs[worm]];
        }
        if (worm != 0) {
            //for (auto i : pairs) {
                //cout << i.first << ' ' << i.second<<'\n';
            //}
            count2.insert(pairs);
            //cout << "next\n";
            answer += 1;
        }
    }
}
void pairing(map<int,int> pairs,int paired) {
    if (paired == n) {
        solve(pairs);
        return;
    }
    int i;
    for (i = 1; i <= n; i++) {
        if (pairs[i] == 0) {
            break;
        }
    }
    for (int j = i+1; j <= n; j++) {
        if (pairs[j] != 0) {
            continue;
        }
        pairs[i] = j;
        pairs[j] = i;
        pairing(pairs,paired + 2);
        pairs[i] = 0;
        pairs[j] = 0;
    }
}
int32_t main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp,temp2;
        cin >> temp >> temp2;
        x.push_back(make_pair(temp,temp2));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i) {
                continue;
            }
            if (x[i-1].first < x[j-1].first && x[i-1].second == x[j-1].second) {
                if (closest[i] == 0 || x[j].first - x[i].first > x[closest[i]].first - x[i].first) {
                    closest[i] = j;
                }
            }
        }
    }
    pairing(map<int,int>(),0);
    cout << count2.size() << '\n';
}
