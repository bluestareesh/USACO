#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main(void) {
    int test;
    scanf("%d\n",&test);
    for (int t = 0; t < test; t++) {
        int n;
        scanf("%d\n",&n);
        int last;
        scanf("%d ",&last);
        int streak = 1;
        map <int,int> one;
        map <int,int> two;
        set <int> check_one;
        set <int> check_two;
        check_one.insert(last);
        for (int i = 1; i < n; i++) {
            int temp;
            scanf("%d ",&temp);
            check_one.insert(temp);
            //printf("%d %d 9\n",last,temp);
            if (temp != last) {
                one[last] = max(one[last],streak);
                streak = 1;
            }
            else {
                streak += 1;
            }
            last = temp;
        }
        one[last] = max(one[last],streak);
        scanf("%d ",&last);
        streak = 1;
        check_two.insert(last);
        for (int i = 1; i < n; i++) {
            int temp;
            scanf("%d ",&temp);
            check_two.insert(temp);
            //printf("%d %d 8\n",last,temp);
            if (temp != last) {
                two[last] = max(two[last],streak);
                streak = 1;
            }
            else {
                streak += 1;
            }
            last = temp;
        }
        two[last] = max(two[last],streak);
        int answer = 1;
        for (int i : check_one) {
            answer = max(one[i],answer);
            if (check_two.find(i) != check_two.end()) {
                //printf("%d %d\n",one[i],two[i]);
                answer = max(two[i]+one[i],answer);
            }
        }
        for (int i : check_two) {
            answer = max(two[i],answer);
        }
        printf("%d\n",answer);
    }
}