def isprime(num: int) -> bool:
    if num <= 1:
        return False
    elif num == 2:
        return True
    elif num % 2 == 0:
        return False
    else:
        for i in range(3, int(num ** (1 / 2) + 1), 2):
            if num % i == 0:
                return False
        else:
            return True


N: int = int(input())
primes: list[int] = []
ans: int = 0

for num in range(2, N + 1):
    if isprime(num):
        primes.append(num)
        if len(primes) >= 2 and primes[-1] - primes[-2] == 2:
            print(f"({primes[-2]} {primes[-1]})")
            ans += 1

print(ans)
