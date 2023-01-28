import sys
import heapq

input = sys.stdin.readline

def dijkstra(start):
    d[start] = 0
    q = []
    heapq.heappush(q,(0,start))
    while len(q) != 0:
        cost, target = heapq.heappop(q)
        if d[target] < cost:
            continue
        for p in node[target]:
            next = p[1]
            c = p[0]
            if d[target] + c < d[next]:
                d[next] = d[target] + c
                heapq.heappush(q,(d[next],next))



v,e = map(int, input().split())
k = int(input())
node = [[] for _ in range(v+1)]
MAX = 1000000000
d = [MAX for _ in range(v+1)]


for i in range(e):
    s,t,w = map(int, input().split())
    node[s].append((w,t))

dijkstra(k)

for i in range(1,v+1):
    if d[i] == MAX:
        print("INF")
    else:
        print(d[i])
