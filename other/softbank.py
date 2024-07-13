from cv2 import split


def num_to_str(n):
    if n == 0:
        return 'zero'
    a = ["one","two","three","four","five","six","seven","eight","nine"]
    b = ["ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
    c = ["eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]

    #100の位の計算(nを100で割った整数を求める)
    d = n // 100
    #10の位の計算(nからd * 100の値を引いた数を10で割った整数を求める)
    e = (n - d * 100) // 10
    #1の位の計算(nからd * 100の値を引いた数を10で割った余りを求める)
    f = (n - d * 100) % 10

    if n >= 11 and n <= 19:  #nが11~19の数かを調べる
        return c[n-11]
    elif d  == 0:   #100の位があるか調べる
        if  e == 0:#10の位があるか調べる
                return a[f-1]
        elif f == 0:#1の位があるか調べる
                return b[e-1]
        else:
                return b[e-1] + " " + a[f-1]
    elif e == 0:
        if f == 0:
            return a[d-1] + " hundred"
        else:
            return a[d-1] + " hundred " + a[f-1]
    else:
        if f == 0:
            return a[d-1] + " hundred " + b[e-1]
        else:
            return a[d-1] + " hundred " + b[e-1] +' '+ a[f-1]

tani = ['','thousand','million','billion']

num = input()
num = num.split('.')
seisu = int(num[0])
seisu = [int(a) for a in str(seisu)] #[1,4,3...]

part3 = len(seisu) % 3
if part3 != 0:
    if part3 == 1:
        seisu = [0,0] + seisu
    if part3 == 2:
        seisu = [0] + seisu


split3 = [seisu[i:i+3] for i in range(0,len(seisu),3)]

for i in range(len(split3)):
    n = int("".join(map(str, split3[i])))
    tani_ = len(split3) - i - 1

    if i == 0:
        print(num_to_str(n).capitalize()+' ', end='')
        if tani_ != 0:
            print(tani[tani_]+' ', end='')
    elif i == len(split3)-1:
        print(num_to_str(n)+' ', end='')
        if tani_ != 0:
            print(tani[tani_], end='')
        break
    else:
        print(num_to_str(n)+' ', end='')
        if tani_ != 0:
            print(tani[tani_]+' ', end='')

    

if len(num) >= 2:
    print('point ', end='')
    syosu = num[1]
    syosu = [int(a) for a in str(syosu)]
    for i in syosu:
        print(num_to_str(i)+' ', end='')



