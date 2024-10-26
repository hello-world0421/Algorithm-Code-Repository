def Description(n: int) -> int:
    if n == 1:
        return 1
    return n * Description(n-1)

print(Description(int(input())))
