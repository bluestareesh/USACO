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
int n,k;
int MAX_ADJ = 30;
int f_pos;
int num_choices(int pos1, int pos2,vector<int> nums)
{
  int total = 1;
  for (int p=pos1; p<=pos2; p++)
    total *= nums[p];
  return total;
}
string get_cow(int o,vector<string> fj,vector<vector<string>> all,vector<int> nums)
{
  string s = "";
  for (int p=0; p<f_pos; p++) {
    if (p>0)  {
        s += " ";
    }
    s += all[p][o / num_choices(p+1, f_pos-1,nums)];
    cout << p << ' ' << o << ' ' <<num_choices(p+1, f_pos-1,nums) << '\n';
    o = o % num_choices(p+1, f_pos-1,nums); 
  }
  return s;
}

int bef(string s,vector<string> fj)
{
  int total = 0;
  for (int i=0; i<n; i++)
    if (fj[i] <= s) total++;
  return total;
}
int32_t main(void) {
    cin >> n >> k;
    vector<vector<string>> all(MAX_ADJ,vector<string>());
    vector<int> nums(MAX_ADJ,0);
    vector<string> fj(n);
    for (int i = 0; i < n; i++) {
        string temp;
        for (int j = 0; j < 4; j++) {
            cin >> temp;
        }
        int pos = 0;
        cin >> temp;
        fj[i] = "";
        while (temp != "cow.") {
            if (pos > 0) {
                fj[i] += ' ';
            }
            fj[i] += temp;
            bool yes = 1;
            for (int i = 0; i < all[pos].size(); i++) {
                if (all[pos][i] == temp) {
                    yes = 0;
                    break;
                }
            }
            if (yes) {
                all[pos].push_back(temp);
                nums[pos] += 1;
            }
            pos += 1;
            cin >> temp;
        }
        f_pos = pos;
    }
    for (int i = 0; i < MAX_ADJ; i++) {
        sort(all[i].begin(),all[i].end());
    }
    int answer = k-1;
    while (answer- bef(get_cow(answer,fj,all,nums),fj) < k-1) {
        answer += 1;
    }
    cout << get_cow(answer,fj,all,nums) << '\n';
}