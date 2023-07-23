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
int r_answer = 0;
using namespace std;
void simu(map<int,int> need) {
    need[-1] = -1;
    for (int start=0; start<n; start++) {
        int pos = start;
        for (int count=0; count<n; count++) {
            pos = closest[need[pos]];
        }
        if (pos != -1)  {
            r_answer += 1;
            return;
        }
    }
  return;
}
void answer(map<int,int> pais,set<int> check) {
    if (check.size() == x.size()) {
        simu(pais);
        return;
    }
    for (int i = 0; i < x.size(); i++) {
        if (check.find(i) != check.end()) {
            continue;
        }
        check.insert(i);
        for (int j = i+1; j < x.size(); j++) {
            if (check.find(j) != check.end()) {
                continue;
            }
            check.insert(j);
            pais[i] = j;
            pais[j] = i;
            answer(pais,check);
            pais.erase(i);
            pais.erase(j);
            check.erase(j);
        }
        check.erase(i);
    }
}
int32_t main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp,temp2;
        cin >> temp >> temp2;
        x.push_back(make_pair(temp,temp2));
        closest[i] = -1;
    }
    closest[-1] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            if (i == j) {
                continue;
            }
            if (x[i].first < x[j].first && x[i].second == x[j].second) {
                if (closest[i] == -1) {
                    closest[i] = j;
                }
                else {
                    int temp = closest[i];
                    if (x[i].first - x[temp].first > x[i].first - x[j].first) {
                        closest[i] = j;
                    }
                }
            }
        }
    }
    //for (auto i : closest) {
        //cout << i.first << ' '  << i.second << '\n';
    //}
    //cout << "lk" << '\n';
    answer(map<int,int>(), set<int>());
    cout << r_answer/2 << '\n';
}
