l = list(map(int, input().split()))
A = l[0]
B = l[1]
C = l[2]

if(A == B):
    if(A != C):
        print("Yes")
    else:
        print("No")
else:
    if(A != C):
        if(B == C):
            print("Yes")
        else: print("No")
    else:
        print("Yes")