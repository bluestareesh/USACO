#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int n,m;
int answer = 0;
vector<int> first = {3,2,1,0};
vector<int> sec = {1,0,3,2};
vector<int> changex = {0,1,0,-1};
vector<int> changey = {-1,0,1,0};
vector<string> grid;
void dfs(pair<int,int> cords, int dir) {
    int result = 0;
    while (0 <= cords.second && cords.second < n && 0 <= cords.first && cords.first < m) {
        if (grid[cords.second][cords.first] == '\\') {
            dir = first[dir];;
        }
        else {
            dir = sec[dir];
        }
        cords.first += changex[dir];
        cords.second += changey[dir];
        result += 1;
    }
    answer = max(answer,result);
    return;
}
int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n ; i++) {
        string temp;
        cin >> temp;
        grid.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        dfs(make_pair(0,i),1);
        dfs(make_pair(m-1,i),3);
    }
    for (int i = 0; i < m; i++) {
        dfs(make_pair(i,0),2);
        dfs(make_pair(i,n-1),0);
    }
    
    cout << answer << '\n';
}