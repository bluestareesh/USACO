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
int answer = 1e9;
int n;
vector<vector<int>> friends;
vector<int> pos;
void solve(int cur_val,int cows_far) {
    if (cur_val > answer) {
        return;
    } 
    if (cows_far == n) {
        answer = min(answer,cur_val);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (pos[i] != 0) {
            continue;
        }
        cows_far += 1;
        pos[i] = cows_far;
        int temp = 0;
        for (int j = 0; j < 3; j++) {
            if (pos[friends[i][j]] != 0) {
                //cout << pos[i] << ' ' << pos[friends[i][j]];
                temp += abs(pos[i] - pos[friends[i][j]]);   
            }
        }
        solve(cur_val + temp,cows_far);
        cows_far -= 1;
        pos[i] = 0;

    }
    
}
int32_t main(void) {
    cin >> n;
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        int temp,temp2,temp3;
        cin >> temp >> temp2 >> temp3;
        temp--;
        temp2--;
        temp3--;
        friends.push_back({temp,temp2,temp3});
    }
    solve(0,0);
    cout << answer << '\n';
}
