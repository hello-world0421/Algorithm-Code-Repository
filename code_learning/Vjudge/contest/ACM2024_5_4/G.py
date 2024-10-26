import sys
from math import inf

ans = []
for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    res, ans0 = [], 0
    for i in range(n - 1):
        num_sum = nums[i]
        for j in range(i + 1, n):
            num_sum += nums[j]
            if num_sum not in res and num_sum in nums:
                res.append(num_sum)
                ans0 += nums.count(num_sum)
    ans.append(str(ans0))
sys.stdout.write('\n'.join(ans))
