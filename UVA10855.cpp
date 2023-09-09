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
void change(vector<string> &small_grid,int n) {
    string temp2 = "";
    for (int i = 0; i < n; i++) {
        temp2 += 'T';
    }
    vector<string> temp(n,temp2);
    for (int i = 0; i < n; i++) {
        for (int j =0 ; j < n; j++) {
            temp[j][n-i-1] = small_grid[i][j];
        }
    }
    small_grid = temp;
}
int32_t main(void) {
    while (1) {
        int N,n;
        cin >> N >> n;
        if (N == 0 && n == 0) {
            break;
        }
        vector<string> grid;
        vector<string> small_grid;
        for (int i = 0; i < N; i++) {
            string temp;
            cin >> temp;
            grid.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            small_grid.push_back(temp);
        }
        for (int t = 0; t < 4; t++) {
            int answer = 0;
            for (int i = 0; i < N-n+1; i++ ){
                for (int j = 0; j < N-n+1; j++) {
                    vector<string> check(n,"");
                    //cout << i << '\n';
                    for (int h = i; h < n+i; h++ ){
                        for (int k = j; k < n+j; k++) {
                            check[h-i] += grid[h][k];
                            //cout << grid[h][k];
                        }
                        //cout << '\n';
                    }
                    if (check == small_grid) {
                        answer += 1;
                    }
                }
            }
            cout << answer << ' ';
            change(small_grid,n);
        }
        cout << '\n';
    }
}