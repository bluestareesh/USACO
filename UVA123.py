count = 0
x = []
bad = set()
yes = 1
while 1:
    try:
        s = input()
    except EOFError:
        break
    if s[-1] == '\r':
        s = s[:-1]
    if yes:
        if s == "::":
            yes = 0
            continue
        bad.add(s)
    else:
        s = s.lower().split()
        for i in range(len(s)):
            if s[i] not in bad:
                s[i] = s[i].upper()
                answer = ''
                for j in s:
                    answer += j
                    answer += ' '
                x.append([s[i],count,answer])
                s[i] = s[i].lower()
    count += 1
for i in sorted(x):
    print(i[2][:-1])