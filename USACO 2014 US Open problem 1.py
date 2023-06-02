all = set()
for m in range(1,17):
  for i in range(m):
    for j in range(10):
      check = [j] * m
      for q in range(10):
        check[i] = q
        temp = int("".join([str(x) for x in check]))
        if len(set(str(temp))) == 1:
          continue
        all.add(temp)
temp = [int(x) for x in input().split()]
answer = 0
for i in range(temp[0],temp[1]+1):
  if i in all:
    answer += 1
print(answer)