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
    int n,b;
    cin >> n >> b;
    string init = "";
    unordered_map<string,int> check;
    vector<string> answer; 
    int le = 0;
    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        init += temp;
    }
    while (check.find(init) == check.end()) {
        check[init] = le;
        le += 1;
        answer.push_back(init);
        string pr = init.substr(0,init.size());
        for (int i = 0; i < n; i++) {
            int temp = i-1;
            if (i == 0) {
                temp = n-1;
            }
            if (pr[temp] == '1') {
                if (init[i] == '0') {
                    init[i] = '1';
                }
                else {
                    init[i] = '0';
                }
            }
        }
    }

    //for (auto i : answer) {
        //cout << i << '\n';
    //} 
    //cout << init << '\n';
    int lm = (find(answer.begin(),answer.end(),init)-answer.begin());
    //cout << le - lm << '\n';
    if (b -lm > 1) {
        //cout << lm + ((b-lm) % (le-lm)) << '\n';
        for (auto i : answer[lm + ((b-lm) % (le-lm))]) {
            cout << i << '\n';
        }
    }
    else {
        for (auto i : answer[lm - 1]) {
            cout << i << '\n';
        }
    }
}
