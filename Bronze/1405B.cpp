#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(void) {
    int test;
    scanf("%d\n",&test);
    for (int t = 0; t < test; t++) {
        vector<int> a;
        long long last = 0;
        int no = 1;
        int n;
        scanf("%d\n",&n);
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d ",&temp);
            if (temp > 0) {
                last += temp;
                no = 0;
                a.push_back(temp);
                continue;
            }
            else {
                if (no) {
                    a.push_back(temp);
                    continue;
                }
                if (abs(temp) > last) {
                    temp = -(abs(temp) - last);
                    a.push_back(temp);
                    last = 0;
                    no = 1;
                }
                else {
                    last -= abs(temp);
                    a.push_back(0);
                }
            }
        }
        long long answer = 0;
        for (int i =0 ; i < n; i++) {
            if (a[i] < 0) {
                answer += -a[i];
            }
        }
        printf("%lld\n",answer);
    }
}