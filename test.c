#include <stdio.h>
int main() {
  freopen("billboard.in","r",stdin);
  freopen("billboard.out","w",stdout);
  char x[1000][1001];
  for (int i = 0; i < 1000; i++) {
    for (int j =0 ;j < 1000;j++) {
      x[i][j] = '#';
    }
    x[i][1000] = '\0';
  }
	int first[4];
  int sec[4];
  int truck[4];
  scanf("%d %d %d %d",&first[0],&first[1],&first[2],&first[3]);
  for (int i = first[1]; i < first[3]; i++) {
    for (int j = first[0]; j < first[2]; j++) {
      x[i][j] = 'F';
    }
  }
  scanf("%d %d %d %d",&sec[0],&sec[1],&sec[2],&sec[3]);
  for (int i = sec[1]; i < sec[3]; i++) {
    for (int j = sec[0]; j < sec[2]; j++) {
      x[i][j] = 'S';
    }
  }
  scanf("%d %d %d %d",&truck[0],&truck[1],&truck[2],&truck[3]);
  for (int i = truck[1]; i < truck[3]; i++) {
    for (int j = truck[0]; j < truck[2]; j++) {
      x[i][j] = 'T';
    }
  }
  int answer = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j =0 ;j < 1000;j++) {
      //printf("%c",x[i][j]);
      if (x[i][j] == '#') {
        continue;
      }
      if (x[i][j] != 'T') {
        //printf("%c %d %d\n",x[i][j],j,i);
        answer += 1;
      }
    }
    //printf("\n");
  }
  printf("%d\n",answer);
}