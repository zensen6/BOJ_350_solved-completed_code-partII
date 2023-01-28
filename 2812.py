n,k = map(int, input().split())
x = input()
num = list([c for c in x])

st = []
cnt = k
for i in num:
    if len(st) == 0:
        st.append(i)
    else:
        while len(st) > 0 and st[-1] < i and cnt > 0:
            cnt -= 1
            st.pop()
        st.append(i)

print(''.join(st[:len(st)-cnt]))
