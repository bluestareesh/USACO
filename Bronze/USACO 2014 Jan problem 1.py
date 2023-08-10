import sys
# sys.stdin = open("moocrypt.in")
# sys.stdout = open("moocrypt.out","w")
n, m = [int(x) for x in input().split()]
grid = [list(input()) for _ in range(n)]

def cap(i):
	return chr(ord('A') + i)

def padded(row):
	return '__'+''.join(row) + '__'

def check(a, i, j):
	# horizontally
	q = 0
	if(a[i][j]+a[i+1][j]+a[i+2][j] == "MOO"):
		q += 1
	if(a[i][j]+a[i-1][j]+a[i-2][j]=="MOO"):
		q += 1
	if(a[i][j] + a[i][j+1] + a[i][j+2] == "MOO"):
		q += 1
	if(a[i][j] + a[i][j-1] + a[i][j-2] == "MOO"):
		q += 1
	if(a[i][j] + a[i+1][j+1] + a[i+2][j+2] == "MOO"):
		q += 1
	if(a[i][j] + a[i-1][j-1] + a[i-2][j-2] == "MOO"):
		q += 1
	if(a[i][j] + a[i+1][j-1] + a[i+2][j-2] == "MOO"):
		q += 1
	if(a[i][j] + a[i-1][j+1] + a[i-2][j+2] == "MOO"):
		q += 1
	return q
	
def solve(a):
	global n
	global m
	q = 0
	b = [
		'_'*(m+4),
		'_'*(m+4),
		*[padded(row) for row in a],
		'_'*(m+4),
		'_'*(m+4),
	]
	for i in range(n):
		for j in range(m):
			I = i+2
			J = j+2
			q += check(b, I, J)
	return q



ans = 0
for M in range(26):
	for O in range(26):
		if(M==O): continue
		b = [list(x) for x in grid]
		for i in range(n):
			for j in range(m):
				if(b[i][j] == cap(M)):
					b[i][j] = 'M'
				elif(b[i][j] == cap(O)):
					b[i][j] = 'O'
				else:
					b[i][j] = '_'
		ans = max(ans, solve(b))

print(ans)