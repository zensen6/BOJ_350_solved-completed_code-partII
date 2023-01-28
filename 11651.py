import sys
input = sys.stdin.readline


n = int(input())
pos = [list(map(int,input().split())) for i in range(n)]
pos = sorted(pos, key=lambda x:(x[1],x[0]))
for i in pos:
    print(i[0], i[1], sep=" ")
