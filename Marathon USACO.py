import sys
problem = "marathon"
sys.stdin = open(problem + '.in')
sys.stdout = open(problem + '.out','w')
n = int(input())
poin = [[int(x) for x in input().split()]]
dis = []
tot = 0
for _ in range(n-1):
  temp = [int(x) for x in input().split()]
  dis.append(abs(poin[-1][0] - temp[0]) + abs(poin[-1][1] - temp[1]))
  tot += dis[-1]
  poin.append(temp)
answer = tot
for i in range(1,n-1):
  temp = dis[i-1] + dis[i] - (abs(poin[i-1][0] - poin[i+1][0]) + abs(poin[i-1][1] - poin[i+1][1])) 
  if temp > 0 and answer > (tot - temp):
    answer = tot - temp 
print(answer)
  
  
