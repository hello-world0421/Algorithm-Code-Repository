num = input()

for i in range(0, 10):
    if (n := num.count(str(i))) != 0:
        print(f"{i}:{n}")
