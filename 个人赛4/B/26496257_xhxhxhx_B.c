n = int(input())
a = 1
b = pow(2,n,5)
c = pow(3,n,5)
d = pow(4,n,5)
e = (a+b+c+d) % 5
print(e)