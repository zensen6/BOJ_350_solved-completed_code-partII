import sys

n = int(input())
s = []
while n > 0:
    n-=1
    x = sys.stdin.readline().split()
    if x[0] == 'push':
        s.append(int(x[1]))
    elif x[0] == 'pop':
        if len(s) == 0:
            print(-1)
        else:
            print(s.pop())
    elif x[0] == 'size':
        print(len(s))
    elif x[0] == 'empty':
        if len(s) == 0:
            print(1)
        else:
            print(0)
    elif x[0] == 'top':
        if len(s) == 0:
            print(-1)
        else:
            print(s[-1])
