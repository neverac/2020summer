def doing():
    x=input()
    while x%2==0:
        x//=2
    prime=[3,5,7]
    cnt=[1,1,1]
    for i in range(3):
        while x%prime[i]==0:
            x/=prime[i]
            cnt[i]=cnt[i]*prime[i]+1
    print(cnt[0]*cnt[1]*cnt[2])
n=input()
for i in xrange(n):
    doing()