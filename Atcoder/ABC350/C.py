import sys
from random import randint

ans = []
n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))

for i in range(n-1):
    j = randint(i+1, n-1)
    if nums[j] == i+1:
        nums[i], nums[j] = nums[j], nums[i]
        ans.append(f"{i+1} {j+1}")
sys.stdout.write(str(len(ans)) + "\n")
sys.stdout.write("\n".join(ans))
