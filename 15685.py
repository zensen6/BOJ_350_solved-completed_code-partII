import sys
input = sys.stdin.readline


def go(index, choose, chic, chicken_len, check, house_to_chicken):
    #print(check)
    if index == chicken_len:
        if choose > chic or choose == 0:
            return
        else:
            #print(check)
            s = 0
            h = len(house_to_chicken)
            for i in range(h):
                d = 1000000000
                for j in range(chicken_len):
                    if check[j] == 1:
                        d = min(d, house_to_chicken[i][j])
                s += d
            global ans
            ans = min(ans, s)
            return
    if choose == chic:
        go(index + 1, choose, chic, chicken_len, check, house_to_chicken)
    elif choose < chic:
        go(index + 1, choose, chic, chicken_len, check, house_to_chicken)
        check[index] = 1
        go(index + 1, choose + 1, chic, chicken_len, check, house_to_chicken)
        check[index] = 0
    return


def solution(n,m,arr):
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 1:
                house.append((i,j))
            elif arr[i][j] == 2:
                chicken.append((i,j))


    chicken_len = len(chicken)
    house_to_chicken = [[MAX for _ in range(chicken_len)] for i in range(len(house))]
    for i in range(len(house)):
        hpos = house[i]
        for j in range(len(chicken)):
            cpos = chicken[j]
            house_to_chicken[i][j] = abs(cpos[0]-hpos[0]) + abs(cpos[1] - hpos[1])

    #print(house_to_chicken)
    check = [0 for _ in range(chicken_len)]
    go(0,0,m,chicken_len,check,house_to_chicken)
    print(ans)

# 치킨집 총 k개
# choose: 여태 고른 치킨집 갯수
# chic: 골라야 하는 맥시멈 갯수

n,m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
MAX = 1000000000
ans = MAX
chicken = []
house = []
dist = []
check = []
chicken_len = 0

solution(n,m,arr)
