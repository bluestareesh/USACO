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
    int n;
    cin >> n;
    vector<pair<int,pair<string,int>>> x;
    for (int i =0 ;i < n; i++ ){
        int temp,val;
        string name;
        char d;
        cin >> temp >> name >> d >> val;
        if (d == '-') {
            val = -val;
        }
        x.push_back({temp,{name,val}});
    }
    sort(x.begin(),x.end());
    vector<int> cows = {7,7,7};
    vector<string> cur = {"Bessie","Mildred","Elsie"};
    int answer = 0;
    for (auto i : x) {
        if (i.second.first == "Bessie") {
            cows[0] += i.second.second;
        }
        if (i.second.first == "Mildred") {
            cows[1] += i.second.second;
        }
        if (i.second.first == "Elsie") {
            cows[2] += i.second.second;
        }
        vector<string> cur2;
        int temp = *max_element(cows.begin(),cows.end());
        if (cows[0] == temp ){
            cur2.push_back("Bessie");
        } 
        if (cows[1] == temp) {
            cur2.push_back("Mildred");
        }
        if (cows[2] == temp) {
            cur2.push_back("Elsie");
        }
        if (cur2 != cur) {
            answer += 1;
            cur = cur2;
        }
    }
    cout << answer << '\n';
}
