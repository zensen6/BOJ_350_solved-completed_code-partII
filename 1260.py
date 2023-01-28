

def bfs(v):
    res  = [v]
    q = []
    q.append(v)
    check[v] = 1
    while(len(q) != 0):
        here = q[0]
        q.pop(0)
        for next in node[here]:
            if check[next] == 0:
                res.append(next)
                check[next] = 1
                q.append(next)
    return res


def dfs(here):
    res2.append(here)
    check[here] = 1
    for next in node[here]:
        if check[next] == 0:
            dfs(next)
    return


node = [[] for _ in range(1001)]
check = [0 for _ in range(1001)]


n,m,v = map(int,input().split())
for i in range(m):
    f,t = map(int,input().split())
    node[t].append(f)
    node[f].append(t)

for i in range(1001):
    node[i].sort()

res1 = bfs(v)
check = [0 for _ in range(1001)]
res2 = []
dfs(v)

print(*res2)
print(*res1)
