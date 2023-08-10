#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int n;
set <pair<int,int>> all;
int good(pair<int,int> rec, char check,vector<vector<char>> grid) {
    if (rec.first == -1 || rec.first == n || rec.second == -1 || rec.second == n || grid[rec.first][rec.second] != check || all.find(rec) != all.end()) {
        return 0;
    }
    //printf("%d %d 9o\n",rec.first,rec.second);
    all.insert(rec);
    return 1;
}
int find(vector<vector<char>> grid, int cur) {
    for (int i = 0; i < n; i++) {
        for (int j =0 ;j < n; j++) {
            pair <int,int> temp;
            temp.first = i;
            temp.second = j;
            if (all.find(temp) != all.end()) {
                continue;
            }
            vector<pair<int,int>> que;
            que.push_back(temp);
            int bef = all.size();
            while (que.size() != 0) {
                pair<int,int> temp3 = que[que.size()-1];
                //printf("%d %d\n",temp3.first,temp3.second);
                que.pop_back();
                all.insert(temp3);
                char temp2 = grid[temp3.first][temp3.second];
                temp3.first -= 1;
                if (good(temp3,temp2,grid)) {
                    que.push_back(temp3);
                }
                temp3.first += 2;
                if (good(temp3,temp2,grid)) {
                    que.push_back(temp3);
                }
                temp3.first -= 1;
                temp3.second -= 1;
                if (good(temp3,temp2,grid)) {
                    que.push_back(temp3);
                }
                temp3.second += 2;
                if (good(temp3,temp2,grid)) {
                    que.push_back(temp3);
                }
                temp3.second -= 1;
            }
            //printf("%d %d\n",i,j);
            if (bef != all.size()) {
                cur += 1;
            }
        }
    }
    return cur;
}
int main(void) {
    scanf("%d\n",&n);
    vector<vector<char>> cow_grid(n,vector<char>());
    vector<vector<char>> hu_grid(n,vector<char>());
    for (int i = 0; i < n; i++) {
        for (int j =0 ; j < n; j++) {
            char temp;
            scanf("%c",&temp);
            hu_grid[i].push_back(temp);
            if (temp == 'R') {
                temp = 'G';
            }
            cow_grid[i].push_back(temp);
        }
        scanf("\n");
    }
    printf("%d ",find(hu_grid,0));
    all.clear();
    printf("%d\n",find(cow_grid,0));
}