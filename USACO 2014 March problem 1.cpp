#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main(void) {
    vector <int> all(1000000,0);
    int n,k;
    scanf("%d %d",&n,&k);
    int look = 0;
    for (int i = 0; i<n; i++) {
        int temp,temp2;
        scanf("%d %d",&temp,&temp2);
        all[temp2] = temp;
        look= max(look,temp2);
    }
    int cur = 0;
    int answer = 0;
    for (int i = 0; i < (2 * k)+1; i++) {
        cur += all[i];
    }
    answer = max(cur,answer);
    for (int i = k; i < look-k; i++) {
        cur -= all[i-k];
        cur += all[i+k+1];
        //printf("%d %d\n",cur,i);
        answer = max(answer,cur);
    }
    printf("%d\n",answer);
}