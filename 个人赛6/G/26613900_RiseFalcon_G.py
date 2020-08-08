import math as m
def f(a,b):
  return a if b==1 else a//b+f(b,a%b)
n,m=map(int,input().split())
print(f(n,m))
