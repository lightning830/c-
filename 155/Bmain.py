N = (int)(input())
A = list(map(int, input().split()))

check = True
for i in A:
    if(i % 2 == 0):
        if(i % 3 != 0 and i % 5 != 0):
            check = False

if(check):
    print("APPROVED")
else:
    print("DENIED")