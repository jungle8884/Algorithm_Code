# 二分法
import math


def f(x):
    result = pow(x, 3) - x - 1
    return result


# 已知 f(x)=0 在[1, 1.5]有根
def Bisection():
    k = 0
    a = 1
    b = 1.5
    e = 0.01
    while True:
        temp = f(a) * f(b)
        if temp > 0:
            a = float(input())
            b = float(input())
            e = float(input())
        elif temp == 0:
            if f(a) == 0:
                print(str(a) + " " + str(k))
                break
            else:
                print(str(b) + " " + str(k))
                break
        else:
            m = (a + b) / 2
            if abs(a - b) < e:
                print(str(m) + " " + str(k))
                break
            elif f(a) * f(m) > 0:
                a = m
            else:
                b = m
        k = k + 1


Bisection()
