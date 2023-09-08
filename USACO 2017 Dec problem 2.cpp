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
    map<int,int> a;
    vector<string> answer(n);
    vector<string> id;
    for (int i = 0; i < n; i++ ){
        int temp;
        cin >> temp;
        a[temp-1] = i;
    }
    for (int i = 0; i < n; i++ ){
        string temp;
        cin >> temp;
        id.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        int temp = i;
        for (int j = 0; j < 3; j++) {
            temp = a[temp];
        }
        answer[temp] = id[i];
    }
    for (int i = 0; i < n; i++ ){
        cout << answer[i] << '\n';
    }
}
