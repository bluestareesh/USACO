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
int answer = 0;
set<pair<int,int>> x;
set<pair<int,int>> visited;
bool valid(pair<int,int> temp2)
{
  return temp2.first>=0 && temp2.first<=101 && temp2.second>=0 && temp2.second<=101;
}
void dfs(pair<int,int> temp) {
    if (!(valid(temp))) {
        return;
    }
    if (x.find(temp) != x.end()) {
        answer += 1;
        return;
    }
    if (visited.find(temp) != visited.end()) {
        return;
    }
    visited.insert(temp);
    dfs(make_pair(temp.first+1,temp.second));
    dfs(make_pair(temp.first-1,temp.second));
    dfs(make_pair(temp.first,temp.second+1));
    dfs(make_pair(temp.first,temp.second-1));
}
int32_t main(void) {
    int n;
    cin >> n;
    int first = 0;
    int sec = 0;
    for (int i = 0; i < n; i++) {
        int temp,temp2;
        cin >> temp >> temp2;
        if (i == 0) {
            first = temp;
            sec = temp2;
        }
        x.insert(make_pair(temp,temp2));
    }
    dfs(make_pair(0,0));
    cout << answer << '\n';
}
