import sys

ans = []
n, q = map(int, input().split())
tree = {}
for _ in range(n-1):
    x, y, w = map(int, input().split())
    if x > y:
        x, y = y, x
    tree[(x, y)] = w
for _ in range(q):
    op, *nums = map(int, input().split())
    if op == 1:
        x, y, z = nums
    elif op == 2:
        x = nums
        