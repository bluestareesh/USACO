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
    while (1) {
        string temp;
        cin >> temp;
        if (temp == "#") {
            break;
        }
        if (next_permutation(temp.begin(),temp.end()) == 0) {
            cout << "No Successor\n";
        }
        else {
            cout << temp << '\n';
        }
    }
}