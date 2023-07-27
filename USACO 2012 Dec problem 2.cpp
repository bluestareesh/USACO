#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
# define int ll
int32_t main(void) {
    freopen("scramble.in","r",stdin);
    freopen("scramble.out","w",stdout);
    int n;
    cin>> n;
    vector <pair<string,int>> all;
    map<string,int> need;
    vector<pair<int,int>> answer(n);
    for (int i = 0; i <  n; i++){
        string temp;
        cin >> temp;
        sort(temp.begin(),temp.end());
        all.push_back(make_pair(temp,0));
        need[temp] = i;
        reverse(temp.begin(),temp.end());
        all.push_back(make_pair(temp,1));
        need[temp] = i;
    }
    sort(all.begin(),all.end());
    int one = 0; 
    int two = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (all[i].second == 0) {
            answer[need[all[i].first]].first = two;
            one += 1;
        }
        else {
            answer[need[all[i].first]].second = one-1;
            two += 1;
        }
    }
    //for (auto i : all) {
        //cout << i.first << ' ' << i.second << '\n';
    //}
    for (auto i : answer) {
        cout << i.first+1 << ' ' << i.second+1 << '\n';
    }
}