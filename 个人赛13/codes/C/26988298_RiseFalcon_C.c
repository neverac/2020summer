n,m=map(int,input().split())
ss=set(input().split())
n+=1
aa=[len(s)+1 for s in ss]
aa.sort()
cnt=0
for i in range(len(aa)):
  if n>=aa[i]:
    n-=aa[i]
    cnt+=1
print(cnt)
