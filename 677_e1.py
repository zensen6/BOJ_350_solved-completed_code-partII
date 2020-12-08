n = int(input())
d = [[0]*(25) for i in range(1,25)]
f = [0]*(25)
f[1] = 1
for i in range(1,n+1):
    d[i][i] = 1
    d[i][0] = 1
    if i >= 2:
        f[i] = i*f[i-1]

for i in range(2,n+1):
    for j in range(1,i):
        d[i][j] = d[i-1][j-1] + d[i-1][j]
print((d[i][i/2]/2) * (pow(2*f[n/2]/n,2)))