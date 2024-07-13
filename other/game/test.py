a = 100
class A:
    def __init__(self) -> None:
        self.s = 0
def test(x):
    x += 100
def test1(A):
    A.s += 100
a1 = A()
test1(a1)
print(a1.s)



x = [0,1,2]

def func(x):
    x[0] += 10

func(x)

print(x)