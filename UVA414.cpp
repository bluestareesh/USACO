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
        int n;
        cin >> n;
        //cout << n << " 9\n";
        if (n == 0) {
            break;
        }
        int mi = 26;
        int su = 0;
        scanf("\n");
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < 25; j++) {
                char x;
                scanf("%c",&x);
                //cout << x;
                if (x != 'X') {
                    temp += 1;
                }
            }
            //cout << '\n';
            scanf("\n");
            mi = min(temp,mi);
            su += temp;
        }
        cout << su - mi*n << '\n';
    }
}