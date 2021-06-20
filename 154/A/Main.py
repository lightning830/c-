a = input().split()

S = a[0]
T = a[1]

b = list(map(int, input().split()))
A = b[0]
B = b[1]

c = input()

for i in range(2):
    if(c == a[i]):
        b[i] -= 1

print("%d %d" % (b[0], b[1]))