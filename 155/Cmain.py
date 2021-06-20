from collections import Counter
N = (int)(input())
A = [input() for i in range(N)]
B = Counter(A)
num = 0
for i in B.values():
    if(i > num):
        num = i
print(B)

for i in reversed(B.items()):
    if(num == i[1]):
        print(i)
# max = [kv for kv in B.items() if kv[1] == max(B.values())]
# for i in reversed(max):
#     print(i[0])