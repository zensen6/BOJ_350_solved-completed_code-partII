
def func(a):
    res = 0
    while a >= 5:
        res += a // 5
        a //= 5
    return res

def fac(a):
    res = 1
    for i in range(1,a+1):
        res *= i
        while res % 10 == 0:
            res //= 10
        if res > 1000000000:
            res %= 1000000000    
    return res%100000

x = input()
countzero = 0
l = len(x)
for i in range(l-1,0,-1):
    if x[i] =='0':
        countzero+=1
    else:
        break

if l >= 5:
    lo = 1
    hi = 220000
    mid = (lo+hi)>>1
    while lo <= hi:
        mid = (lo+hi)>>1
        if func(mid) < countzero:
            lo = mid+1
        elif func(mid) > countzero:
            hi = mid-1
        else:
            break

    for i in range(5*(mid//5),5*(mid//5) + 6,1):
        if x[l-countzero-5:l-countzero] == str(fac(i)):
            print(i)
            break
else:
    x = int(x)
    for i in range(1,8):
        res = 1
        for j in range(1,i+1):
            res *= j
        if res == x:
            print(i)
            break