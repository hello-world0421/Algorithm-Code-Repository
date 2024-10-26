num: int = int(input())
step: int = 0

while num != 1:
    step += 1
    if num % 2 == 0:
        num /= 2
    else:
        num = ((num * 3) + 1) / 2
print(step)
