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
    while (!(cin.eof())) {
        int n;
        cin >> n;
        vector <int> all;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            all.push_back(temp);
        }
        vector<int> check;
        for (int i = 0; i < n-1; i++) {
            check.push_back(all[i+1]-all[i]);
        }
        sort(check.begin(),check.end());
        bool yes = 1;
        for (int i = 0; i < n-1; i++) {
            if (i+1 != check[i]) {
                yes = 0;
                break;
            }
        }
        if (yes) {
            cout << "Jolly\n";
        }
        else {
            cout << "Not jolly\n";
        }
    }
}