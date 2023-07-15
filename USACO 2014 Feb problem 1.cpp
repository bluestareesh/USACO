#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;
 
typedef long long ll;
# define int ll
vector<string> grid;
set<pair<int,int>> lk;
int n,m;
int look(pair<int,int> temp, int cur, int state) {
    cout << temp.first << ' ' << temp.second << ' ' << cur << '\n';
    if (temp.first >= n || temp.second >= m || temp.first < 0 || temp.second < 0 || lk.find(temp) != lk.end()) {
        return cur;
    }
    lk.insert(temp);
    if (grid[temp.first][temp.second] == '\\') {
        if (state == 1) {
            return look(make_pair(temp.first+1,temp.second),cur+1,0);
        }
        else {
            return look(make_pair(temp.first,temp.second+1),cur+1,1);
        }
    }
    else {
        if (state == 1) {
            return look(make_pair(temp.first-1,temp.second),cur+1,0);
        }
        else {
            return look(make_pair(temp.first,temp.second-1),cur+1,1);
        }
    }
}
int32_t main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        grid.push_back(temp);
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(look(make_pair(i,0), 0,1),answer);
    }
    for (int j = 0; j < m; j++) {
        answer = max(look(make_pair(0,j), 0,0),answer);
    }
    cout << answer << '\n';
}
