x = []
for _ in range(int(input())):
  x.append(int(input()))
answer = -1
for i in range(0,max(x)-16):
  temp = 0
  for j in x:
    if j >= i and j <= i+17:
      continue
    if j < i:
      temp += (i-j) * (i-j)
    else:
      temp += (j-(i+17)) * (j-(i+17))
  if answer == -1:
    answer = temp
  answer=min(answer,temp)
print(answer)