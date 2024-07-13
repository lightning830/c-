from audioop import reverse
import datetime as dt

A1_7 = [] #A1->A7
A1_13 = []
A7_1 = []
A7_13 = [dt.datetime(2020,1,1,6,10)]
A13_1 = []
A13_7 = [dt.datetime(2020,1,1,22,52)]
B1_A7 = []
A7_B1 = []

# 時刻事前計算
a = dt.datetime(2020,1,1,5,55)
while(a.hour < 23):
    A1_7.append(a)
    a = a + dt.timedelta(minutes=10)

a = dt.datetime(2020,1,1,6,0)
while(a.hour < 23):
    A1_13.append(a)
    a = a + dt.timedelta(minutes=10)
A7_13 = A7_13[:-1]

a = dt.datetime(2020,1,1,6,6)
while(a.hour < 23):
    A7_1.append(a)
    a = a + dt.timedelta(minutes=10)

a = dt.datetime(2020,1,1,5,52)
while(a.hour < 23):
    A13_1.append(a)
    a = a + dt.timedelta(minutes=10)

a = dt.datetime(2020,1,1,6,0)
while(a.hour < 23):
    B1_A7.append(a)
    a = a + dt.timedelta(minutes=6)

a = dt.datetime(2020,1,1,6,11)
while(a.hour < 23):
    A7_B1.append(a)
    a = a + dt.timedelta(minutes=6)
A7_B1.append(a)

R,S,DIR,HH = map(str,input().split())

st = int(S[1:])
ans = []

A1_t = [0,0,3,8,10,13,17,20,24,26,28,31,37,39]#A1_t[4]:A1->A4までの時間
A7_t = [0,17,12,10,7,3,0,4,6,8,11,17,19]
A13_t = [0,2,8,11,13,15,19,22,26,29,31,36,39]
A13_t = A13_t.reverse()
B1_t = [0,0,4,7,10,12,15]
A7_B_t = [0,15,11,8,5,3]

a = []
# if R == 'A':
#     if st>1 and st<7:#1~7駅のとき
#         if DIR =='U':#上りの時
#             #A1_7の時刻を全て進める
#             a = []
#             for i in A1_7:
#                 a.append(i+dt.timedelta(minutes=A1_t[st]))
#     elif st>7 and st<13:
#     elif st == 1:
#     elif st == 7:
#     elif st == 13: 

if R == 'B':
    if DIR == 'U':
        for i in B1_A7:
            a.append(i+dt.timedelta(minutes=B1_t[st]))
    else:
        for i in A7_B1:
            a.append(i+dt.timedelta(minutes=A7_B_t[st]))

a.sort()
# print(A13_1)
# def Print(a, hour):
#     print(HH+': ', end='')
#     for i in range(len(a)):
#         if a[i].hour == hour:
#             if i == len(a)-1:
#                 print(a[i].minute, end='')
#                 break
#             print(str(a[i].minute)+' ', end='')

def Print(a, hour):
    ans = []
    flag = True
    for i in range(len(a)):
        if a[i].hour == hour:
            flag = False
            m = str(a[i].minute).zfill(2)
            ans.append(m)
    if flag:
        print("No train")
        return

    print(HH+': ', end='')
    for i in range(len(ans)):
        if i == len(ans)-1:
            print(ans[i], end='')
            break
        print(ans[i]+' ', end='')
Print(a, int(HH))


# Print(a, int(HH))