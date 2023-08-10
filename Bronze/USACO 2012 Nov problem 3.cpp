#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int n;
int answer = 0;
int good(pair<int,int> rec,set<pair<int,int>> all) {
    if (rec.first == -1 || rec.first == n || rec.second == -1 || rec.second == n || all.find(rec) != all.end()) {
        return 0;
    }
    //printf("%d %d 9o\n",rec.first,rec.second);
    all.insert(rec);
    return 1;
}
void find(vector<string> &grid, int le, int ri,pair<int,int> cords,set<pair<int,int>> all) {
    if (ri > le) {
        return;
    }
    else {
        if (le == ri) {
            answer = max(le+ri,answer);
        }
    }
    all.insert(cords);
    cords.first += 1;
    if (good(cords,all)) {
        if (grid[cords.first][cords.second] == '(') {
            find(grid,le+1,ri,cords,all);
        }
        else {
            find(grid,le,ri+1,cords,all);
        }
    }
    cords.first -= 2;
    if (good(cords,all)) {
        if (grid[cords.first][cords.second] == '(') {
            find(grid,le+1,ri,cords,all);
        }
        else {
            find(grid,le,ri+1,cords,all);
        }
    }
    cords.first += 1;
    cords.second += 1;
    if (good(cords,all)) {
        if (grid[cords.first][cords.second] == '(') {
            find(grid,le+1,ri,cords,all);
        }
        else {
            find(grid,le,ri+1,cords,all);
        }
    }
    cords.second -= 2;
    if (good(cords,all)) {
        if (grid[cords.first][cords.second] == '(') {
            find(grid,le+1,ri,cords,all);
        }
        else {
            find(grid,le,ri+1,cords,all);
        }
    }
}
int main(void) {
    scanf("%d\n",&n);
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        for (int j =0 ; j < n; j++) {
            char temp;
            scanf("%c",&temp);
            grid[i] += temp;
        }
        scanf("\n");
    }
    if (grid[0][0] == '(') {
        find(grid,1,0,make_pair(0,0),set<pair<int,int>>());
        cout << answer/2 << '\n';
    }
    else {
        cout << "0\n";
    }
}