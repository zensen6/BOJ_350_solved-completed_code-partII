n = int(input())
isprime = [1 for _ in range(10015)]

i = 2
while i*i <= n:
    j = i*i
    if isprime[i]:
        while j <= n:
            isprime[j] = 0
            j += i
    i += 1


alpha = [0 for _ in range(n+2)]
num = [i for i in range(n+2)]

for prime in range(2,n+1):
    if isprime[prime]:
        for i in range(2,n+1):
            while num[i] % prime == 0:
                num[i] /= prime
                alpha[prime] += 1

ans = 1
for a in alpha:
    ans *= (2*a + 1)
print(ans)