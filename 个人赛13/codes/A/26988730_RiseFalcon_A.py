def slove():
  n,m,x,y=map(int,input().split())
  if x<=y:
    print(m)
  else :
    print(min((n+(m-1)*y)//x,m))
t=int(input())
for i in range(t):
  slove()
#asdasdada