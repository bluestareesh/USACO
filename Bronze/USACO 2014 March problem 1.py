n = int(input())
a = []
b = []
where_b = dict()
for _ in range(n):
  a.append(int(input()))
for i in range(n):
  temp = int(input())
  b.append(temp)
  where_b[temp] = i
check = set()
def find(i,le):
  global check
  if i in check:
    if le == 1:
      check.remove(i)
      return 0
    return le
  check.add(i)
  return find(a[where_b[i]],le+1)
answer = 0
answer2 = 0
cur = 0
for i in a:
  answer = max(find(i,0),answer)
  if len(check) != cur:
    answer2 += 1
    cur = len(check)
print(answer2,answer)