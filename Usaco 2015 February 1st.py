s = input()
x = input()
i = 0
while i < len(s)-len(x)+1:
  temp = ''
  for j in range(i,len(x)+i):
    temp += s[j]
  if temp == x:
    s = s[:i] + s[i+len(x):]
    i = 0
  else:
    i += 1
print(s)
