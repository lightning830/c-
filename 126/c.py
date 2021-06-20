def c():
    N, K = map(int, input().split())
    sum1 = 0
    for i in range(1, N+1):
        for j in range(1, 18):
            if i>=K:
                sum1 += 1/N
                break
            elif (2**j)*i>=K:
                sum1 += (1/N)*((1/2)**j)
                break
    print(sum1)
    return

c()