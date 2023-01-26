theta = [0.72, 0.07, 0.12, 0.09]
X = [205, 26, 25, 19]
n= 275

T = 0
for i in range(4):
    T += ((X[i]-n*theta[i])**2)/(n*theta[i])
    
print(T)