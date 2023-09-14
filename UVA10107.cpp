#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
# define int ll
int32_t main(void) {
    priority_queue<int> amx;
    priority_queue <int, vector<int>, greater<int>> imn;
    vector<int> need;
    int count = 0;
    while (!cin.eof()) {
        count += 1;
        int temp;
        cin >> temp;
        if (need.size() == 0) {
            need.push_back(temp);
            cout << temp;
            cout << '\n';
            continue;
        }
        if (need.size() == 1) {
            need.push_back(temp);
            cout << (need[0] + need[1])/2 << '\n';
            if (need[0] > need[1]) {
                amx.push(need[1]);
                imn.push(need[0]);
            }
            else {
                amx.push(need[0]);
                imn.push(need[1]);
            }
            continue;
        }
        if (temp > amx.top()) {
            imn.push(temp);
        }
        else {
            amx.push(temp);
        }
        int temp2;
        if (imn.size() > amx.size()+1) {
            temp2 = imn.top();
            imn.pop();
            amx.push(temp2);
        }
        if (amx.size() > imn.size()+1) {
            temp2 = amx.top();
            amx.pop();
            imn.push(temp2);
        }
        if (amx.size() == imn.size()) {
            cout << (imn.top()+amx.top())/2 << "\n";
        }
        else {
            if (amx.size() > imn.size()) {
                cout << amx.top() << "\n";
            }
            else {
                cout << imn.top() << "\n";
            }
        }
    }
}