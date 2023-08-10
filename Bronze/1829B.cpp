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
        char last;
        scanf("%c ",&last);
        if (n == 1) {
            if (last == '0') {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
            continue;
        }
        int streak = 1;
        int answer = 0;
        for (int i = 1; i < n; i++) {
            char temp;
            scanf("%c ",&temp);
            if (temp != last) {
                if (last == '0') {
                    answer = max(answer,streak);
                }
                streak = 1;
                last = temp;
            }
            else {
                streak += 1;
            }
        }
        if (last == '0') {
            answer = max(answer,streak);
        }
        printf("%d\n",answer);
    }
}