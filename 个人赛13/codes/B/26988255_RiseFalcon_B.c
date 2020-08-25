def dist(a,b):
  ans=0
  for i in range(3):
    ans+=(a[i]-b[i])**2
  return ans**0.5
n=int(input())
a=[]
for i in range(n):
  a.append(list(map(int,input().split())))
ans=1E100
for i in range(n):
  ans=min(ans,dist([0,0,0],a[i]))
print('%.3f'%ans)
