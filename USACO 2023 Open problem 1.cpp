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
int32_t main(void) {
    int n;
    cin >> n;
    vector <int> all;
    int su = 0;
    vector <int> green(n+1);
    int total = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        all.push_back(temp);
    }
    vector<int> rem(all);
    sort(all.begin(),all.end());
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1) {
            green[i] = green[i+1];
        }
        green[i] += all[i];
        total += green[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int temp,temp2;
        cin >> temp >> temp2;
        temp--;
        int pos = lower_bound(all.begin(),all.end(),temp2) - all.begin();
        int old_pos = lower_bound(all.begin(),all.end(),rem[temp]) - all.begin();
        int fina = total;
        if (pos <= old_pos) {
            fina += green[pos] - green[old_pos];
            fina -= (old_pos + 1) * rem[temp];
            fina += (pos + 1) * temp2;
        }
        else {
            fina -= green[old_pos+1] - green[pos];
            fina -= (old_pos + 1) * rem[temp];
            fina += (pos) * temp2;
        }
        cout << fina << '\n';
    }
}
