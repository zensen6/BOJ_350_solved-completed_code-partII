

def solve(target):
    res = []
    lo = 1
    hi = 100000000000
    while lo<=hi:
        s = 0
        mid = (lo+hi)//2
        for e in l:
            s += (e//mid)
        if s >= target:
            res.append(mid)
            lo = mid+1
        else:
            hi = mid-1
    return res


l = []
n, k = map(int, input().split())
for i in range(n):
    x = int(input())
    l.append(x)

res = solve(k)
res.sort(reverse=True)
print(res[0])
