from random import randint
N = 5
A = [0] * N

for i in range(N):
    A[i] = randint(0, 5)

    
for i in range(N - 1):
    for j in range(N - i - 1):
        if (A[j] > A[j + 1]):
            buf = A[j]
            A[j] = A[j + 1]
            A[j + 1] = buf
            

for i in range(N):
    print(i,")",A[i])

print(" ")

for i in range(N - 1):
    for j in range(N - i - 1):
        if (A[j] < A[j + 1]):
            buf = A[j]
            A[j] = A[j + 1]
            A[j + 1] = buf


for i in range(N):
    print(i,")",A[i])