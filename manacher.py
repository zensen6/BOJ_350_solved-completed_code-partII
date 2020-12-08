def shortestPalindrome(s):
        A = [0]*1000000
        a="#"
        for i in range(len(s)):
	        a += s[i]
	        a += "#"
        l=len(a)
        r=0
        p=0
        for i in range(0,l):
            if i<=r:
                A[i]=min(r-i,A[2*p-i])
            else:
                A[i]=0
            while i-A[i]-1>=0 and i+A[i]+1<l and a[i-A[i]-1]==a[i+A[i]+1]:
                A[i]+=1
            if r<i+A[i]:
                r=i+A[i]
                p=i
            c=0


        for i in range(0,len(a)):
	        if A[i] > c and A[i]==i:
		        c=i
        if len(s)==1:
            return s
        else:
            if c % 2 == 0:
                k=0
            else:
                k=1
            z=s[int(c//2)*2+k:]
            return "".join(reversed(z))+s


s = input()
print(shortestPalindrome(s))
