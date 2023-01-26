import math

# 6x - lnx
# 6 - 1/x
# 1/x^2

def run(iter_, x_0):
    x = x_0
    while iter_:
        iter_ -= 1
        x = x - x**2*(6-1/x)
        print(x)
    
run(1000, 0.4)
