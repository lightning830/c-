a = list(map(int, input().split()))

K = a[0]
X = a[1]
if(K*500 >= X):
    print("Yes")
else:
    print("No")