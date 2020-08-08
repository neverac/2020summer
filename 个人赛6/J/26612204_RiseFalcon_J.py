import math as m
n,k=map(int,input().split())
w=list(map(int,input().split()))
print(m.ceil(sum([m.ceil(it/k) for it in w])/2))
