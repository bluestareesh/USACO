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
int one = 0;
int two = 1;
int three = 0;
int four = 1;
int32_t main(void) {
    int n;
    cin >> n;
    map<string,pair<int,int>> cords;
    vector<vector<int>> malk = {{1,1,-1,-1},{1,-1,-1,1},{-1,-1,1,1},{-1,1,1-1}};
    cords["FR"] = {1,1};
    cords["FL"] = {0,1};
    cords["RL"] = {0,0};
    cords["RR"] = {1,0};
    //y0+x1-x0,x0+y0-y1
    int dir = 0;
    for (int i = 0; i <n ; i++) {
        string temp;
        cin >> temp;
        string fina =temp.substr(2,1);
        string foo = temp.substr(0,2);
        pair<int,int> temp2 = cords[foo];
        if (fina == "P") {
            for (auto i : cords) {
                if (i.first == foo) {
                    continue;
                }
                pair <int,int> temp3 = i.second;
                temp3.first -= temp2.first;
                temp3.second -= temp2.second;
                pair <int,int> temp4 = {temp3.second,-temp3.first};
                temp4.first += temp2.first;
                temp4.second += temp2.second;
                cords[i.first] = temp4;
            }
            dir = (dir+1) % 4;
        }
        else {
            if (fina == "F") {
                if (dir % 2 == 0) {
                    cords[foo].second += malk[dir][0];
                }
                else {
                    cords[foo].first += malk[dir][0];
                }
            }
            if (fina == "B") {
                if (dir % 2 == 0) {
                    cords[foo].second += malk[dir][2];
                }
                else {
                    cords[foo].first += malk[dir][2];
                }
            }
            if (fina == "R") {
                if (dir % 2 == 0) {
                    cords[foo].first += malk[dir][1];
                }
                else {
                    cords[foo].second += malk[dir][1];
                }
            }
            if (fina == "L") {
                if (dir % 2 == 0) {
                    cords[foo].first += malk[dir][3];
                }
                else {
                    cords[foo].second += malk[dir][3];
                }
            }
        }
        for (auto i : cords) {
            //cout << i.second.first << ' ' << i.second.second << '\n';
            one = min(one,i.second.first);
            two = max(two,i.second.first);
            three = min(three,i.second.second);
            four = max(four,i.second.second);
        }
        //cout << "h\n";
    }
    cout << (two-one+1) * (four - three+1) << '\n';
}