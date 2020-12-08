n = int(input())
d = [[0]*(n+1) for i in range(n+1)]

def inrange(y,x):
    return y>=1 and y<=n and x>=1 and x<=n

while True:
    x = int(input())
    if x<=0 or x>n:
        break
    y = int(input())
    if y<=0 or y>n:
        break
    if inrange(y,x):
        d[y][x] = 1
    else:
        break


for i in range(1,n+1):
    for j in range(1,n+1):
        print(d[i][j], end = ' ')
    print()
