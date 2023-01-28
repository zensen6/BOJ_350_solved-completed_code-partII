import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**6)

n,m = map(int, input().split())
d = [list(map(int, input().split())) for _ in range(n)]

'''
1: ----

2: --
   --

3: -
   -
   --

4: -
   --
    -

5: ---
    -

'''

ans = 0
#1 ----
for i in range(n):
    for j in range(m-3):
        s = d[i][j] + d[i][j+1] + d[i][j+2] + d[i][j+3]
        ans = max(ans, s)
#1 rotate
for i in range(n-3):
    for j in range(m):
        s = d[i][j] + d[i+1][j] + d[i+2][j] + d[i+3][j]
        ans = max(ans, s)

#2
for i in range(n-1):
    for j in range(m-1):
        s = d[i][j] + d[i+1][j] + d[i][j+1] + d[i+1][j+1]
        ans = max(ans ,s)

#3 original
for i in range(n-2):
    for j in range(m-1):
        s = d[i][j] + d[i+1][j] + d[i+2][j] + d[i+2][j+1]
        ans = max(ans, s)

#3 rotate 90
'''
---
-
'''
for i in range(n-1):
    for j in range(m-2):
        s = d[i][j] + d[i][j+1] + d[i][j+2] + d[i+1][j]
        ans = max(ans, s)
'''
--
 -
 -

'''
#3 rotate 180
for i in range(n-2):
    for j in range(m-1):
        s = d[i][j] + d[i][j+1] + d[i+1][j+1] + d[i+2][j+1]
        ans = max(ans, s)
'''
  -
---
'''
#3 rotate 270
for i in range(n-1):
    for j in range(m-2):
        s = d[i][j+2] + d[i+1][j] + d[i+1][j+1] + d[i+1][j+2]
        ans = max(ans, s)





#3 flip
'''
 -
 -
--

'''
for i in range(n-2):
    for j in range(m-1):
        s = d[i][j+1] + d[i+1][j+1] + d[i+2][j+1] + d[i+2][j]
        ans = max(ans, s)


#3 flip 90
'''

-
---

'''
for i in range(n-1):
    for j in range(m-2):
        s = d[i][j] + d[i+1][j] + d[i+1][j+1] + d[i+1][j+2]
        ans = max(ans, s)


#3 flip 180
'''

--
-
-

'''
for i in range(n-2):
    for j in range(m-1):
        s = d[i][j] + d[i+1][j] + d[i+2][j] + d[i][j+1]
        ans = max(ans, s)

#3 flip 270
'''

---
  -

'''
for i in range(n-1):
    for j in range(m-2):
        s = d[i][j] + d[i][j+1] + d[i][j+2] + d[i+1][j+2]
        ans = max(ans, s)




#4 original
for i in range(n-2):
    for j in range(m-1):
        s = d[i][j] + d[i+1][j] + d[i+1][j+1] + d[i+2][j+1]
        ans = max(ans, s)
#4 rotate 90
'''
 --
--

'''
for i in range(n-1):
    for j in range(m-2):
        s = d[i][j+1] + d[i][j+2] + d[i+1][j] + d[i+1][j+1]
        ans = max(ans, s)


#4 flip
'''
  -
 --
 -

'''
for i in range(n-2):
    for j in range(m-1):
        s = d[i][j+1] + d[i+1][j] + d[i+1][j+1] + d[i+2][j]
        ans = max(ans, s)


#4 flip and 90
'''
--
 --

'''
for i in range(n-1):
    for j in range(m-2):
        s = d[i][j] + d[i][j+1] + d[i+1][j+1] + d[i+1][j+2]
        ans = max(ans, s)



#5 original
for i in range(n-1):
    for j in range(m-2):
        s = d[i][j] + d[i][j+1] + d[i][j+2] + d[i+1][j+1]
        ans = max(ans, s)

#5 rotate 90
'''
 -
--
 -

'''
for i in range(n-2):
    for j in range(m-1):
        s = d[i+1][j] + d[i][j+1] + d[i+1][j+1] + d[i+2][j+1]
        ans = max(ans, s)

#5 rotate 180
'''
 -
---

'''
for i in range(n-1):
    for j in range(m-2):
        s = d[i+1][j] + d[i][j+1] + d[i+1][j+1] + d[i+1][j+2]
        ans = max(ans, s)

#5 rotate 270
'''
-
--
-

'''
for i in range(n-2):
    for j in range(m-1):
        s = d[i][j] + d[i+1][j] + d[i+2][j] + d[i+1][j+1]
        ans = max(ans, s)

print(ans)
