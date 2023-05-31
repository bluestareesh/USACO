for _ in range(int(input())):
  temp = [int(x) for x in input().split()]
  if temp == [0,0]:
    print('YES')
    continue
  if temp[0]//temp[1] == 2 or temp[1] //temp[0] == 2 or (temp[0] == temp[1] and temp[0] % 3 == 0 and temp[1] %3 == 0):
    print("YES")
  else:
    print('NO')
