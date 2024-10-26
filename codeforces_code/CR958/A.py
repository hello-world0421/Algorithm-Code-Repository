import sys

for _ in range(int(input())):
    n, k = map(int, input().split())
    sys.stdout.write(str((n - 1 + k - 2) // (k - 1)) + '\n')