import sys
input = sys.stdin.readline

def Find(x):
    if x == p[x]:
        return x
    p[x] = Find(p[x])
    return p[x]

def Union(x, y):
    x1 = Find(x)
    y1 = Find(y)
    if x1 < y1:
        p[y1] = x1
    else:
        p[x1] = y1
    return


v,e = map(int,input().split())
edge = []
p = [i for i in range(v+1)]
for i in range(e):
    u,v,c = map(int,input().split())
    edge.append((u,v,c))

ans = 0
edge = sorted(edge, key=lambda x:(x[2]))
for element in edge:
    u = element[0]
    v = element[1]
    cost = element[2]
    if Find(u) != Find(v):
        Union(u,v)
        ans += cost

print(ans)
