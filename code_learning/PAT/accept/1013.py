def isprime(n: int) -> bool:
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for num in range(3, int(n ** 0.5 + 1), 2):
        if n % num == 0:
            return False
    return True

def prime_nums(n: int) -> list[int]:
    primes: list[int] = [2]
    for num in range(3, n ** 2 + 3, 2):
        if len(primes) == n:
            return primes
        if isprime(num):
            primes.append(num)

M, N = map(int, input().split())

ans = prime_nums(N)[M - 1:]
for i in range(0, len(ans), 10):
    print(*ans[i:i + 10])
