a = int (input())
if a > 0 | 0 < a // 1000 <= 9 :
    b = a // 1000
    print(b)
    c = a // 100 % 10
    d = a // 10 % 10
    e = a % 10
    print("Сумма = ", b + c + d + e)
    print("Произведение = ", b * c * d * e)
else:
    print("Четырех значное число!!!")
