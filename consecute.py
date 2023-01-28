import sys

input = sys.stdin.readline


def solution(elements):
    a = []
    d = [[0 for _ in range(2001)] for i in range(2001)]
    pSum = [0 for _ in range(2001)]
    for i in range(2):
        for e in elements:
            a.append(e)

    answer = 0
    l = len(elements)
    ans = set()
    for i in range(l):
        d[i][i] = elements[i]

    pSum[0] = elements[0]
    for i in range(1,2*l):
        pSum[i] += (pSum[i-1] + a[i])

    for s in range(1,l+1):
        for i in range(0,l):
            if i > 0:
                ans.add(pSum[i+s-1] - pSum[i-1])
            else:
                ans.add(pSum[i+s-1])

    answer = len(ans)

    return answer


n = int(input())
arr = list(map(int, input().split()))

print(solution(arr))
