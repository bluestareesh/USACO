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
int n,m;
int check(vector<string> &a, int i, int j,char M, char O) {
	int q = 0;
    string temp = "";
    temp += a[i][j];
    temp += a[i+1][j];
    temp += a[i+2][j];
	if(temp[0] == M && temp[1] == O && temp[2] == O) {
		q += 1;
    }
    temp = "";
    temp += a[i][j];
    temp += a[i-1][j];
    temp += a[i-2][j];
	if(temp[0] == M && temp[1] == O && temp[2] == O) {
		q += 1;
    }
    temp = "";
    temp += a[i][j];
    temp += a[i][j+1];
    temp += a[i][j+2];
	if(temp[0] == M && temp[1] == O && temp[2] == O) {
		q += 1;
    }
    temp = "";
    temp += a[i][j];
    temp += a[i][j-1];
    temp += a[i][j-2];
	if(temp[0] == M && temp[1] == O && temp[2] == O) {
		q += 1;
    }
    temp = "";
    temp += a[i][j];
    temp += a[i+1][j+1];
    temp += a[i+2][j+2];
	if(temp[0] == M && temp[1] == O && temp[2] == O) {
		q += 1;
    }
    temp = "";
    temp += a[i][j];
    temp += a[i-1][j-1];
    temp += a[i-2][j-2];
	if(temp[0] == M && temp[1] == O && temp[2] == O) {
		q += 1;
    }
    temp ="";
    temp += a[i][j];
    temp += a[i+1][j-1];
    temp += a[i+2][j-2];
	if(temp[0] == M && temp[1] == O && temp[2] == O) {
		q += 1;
    }
    temp = "";
    temp += a[i][j];
    temp += a[i-1][j+1];
    temp += a[i-2][j+2];
	if(temp[0] == M && temp[1] == O && temp[2] == O) {
		q += 1;
    }
	return q;
}
/*
int solve(vector<string> a) {
	int q = 0;
	b = [
		'_'*(m+4),
		'_'*(m+4),
		*[padded(row) for row in a],
		'_'*(m+4),
		'_'*(m+4),
	]
    vector<string> b;
    string add = "";
    for (int i = 0; i < m+4; i++) {
        add += '_';
    }
    b.push_back(add);
    b.push_back(add);
    for (int i = 0; i < n; i++) {
        string temp = a[i].substr(0,a[i].size());
        temp = '_' + temp;
        temp = '_' + temp;
        temp = temp + '_';
        temp = temp + '_';
        b.push_back(temp);
    }
    b.push_back(add);
    b.push_back(add);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			int I = i+2;
			int J = j+2;
			q += check(b, I, J);
        }
    }
	return q;
}
*/
int32_t main(void) {
    cin >> n >> m;
    vector<string> grid;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        grid.push_back(temp);
    }
    int ans = 0;
    for (char M = 'A'; M <= 'Z'; M++) {
        for (char O = 'A'; O <= 'Z'; O++) {
            if (M == O) {
                continue;
            }
            int res = 0;
            vector<string> b;
            string add = "";
            for (int i = 0; i < m+4; i++) {
                add += '_';
            }
            b.push_back(add);
            b.push_back(add);
            for (int i = 0; i < n; i++) {
                string temp = grid[i].substr(0,grid[i].size());
                temp = '_' + temp;
                temp = '_' + temp;
                temp = temp + '_';
                temp = temp + '_';
                b.push_back(temp);
            }
            b.push_back(add);
            b.push_back(add);
            for (int i = 2; i < n+2; i++) {
                for (int j = 2; j < m+2; j++) {
                    if (b[i][j] != M) {
                        continue;
                    }
                    res += check(b,i, j,M,O);
                }
            }
            ans = max(ans,res);
        }
    }
    cout << ans << '\n';
}