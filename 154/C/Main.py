N = (int)(input())
A = list(map(int, input().split()))

A.sort()
# print(A)
flag = False
for i in range(len(A)):
    if(i+1 < len(A)):
        if(A[i] == A[i+1]):
            print("NO")
            flag = True
            break
if(not flag):
    print("YES")