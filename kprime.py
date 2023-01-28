import sys
input = sys.stdin.readline


n, k = map(int,input().split())
'''
isPrime = [1 for _ in range(1000001)]
isPrime[1] = 0
isPrime[2] = 1
i = 2
while i*i <= n:
    if isPrime[i]:
        j = i*i
        while j <= n:
            isPrime[j] = 0
            j += i
    i += 1
'''
def isPrime(a):
    if a == 1:
        return False
    i = 2
    while i*i <= a:
        if a%i == 0:
            return False
        i += 1
    return True

t = n
x = ""
while t > 0:
    x += str(t%k)
    t //= k

x = x[::-1]

#0p
#p0
#p
#0p0

l = len(x)
sol = 0

for s in range(1, l+1):
    for i in range(0, l-s+1):
        if isPrime(int(x[i:i+s])) and '0' not in x[i:i+s]:
            if i == 0 and s < l and x[i+s] == '0':
                sol += 1
            elif i == l-s and s < l and x[i-1] == '0':
                sol += 1
            elif s == l:
                sol += 1
            elif i >0 and i < l-s and x[i+s] == '0' and x[i-1] == '0':
                sol += 1
print(sol)
