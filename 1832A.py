for _ in range(int(input())):
  s = list(input())
  temp = []
  for i in range(len(s)//2):
    temp.append(s[i])
  if len(set(temp)) == 1:
    print('NO')
  else:
    print('YES')
