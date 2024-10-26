import sys

n, q = map(int, input().split())
t = list(map(int, input().split()))

for i in set(t):
    if t.count(i) & 1:
        n -= 1
sys.stdout.write(str(n))