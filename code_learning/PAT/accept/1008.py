N, M = map(int, input().split())
nums: list[int] = list(map(int, input().split()))

M = M % N
nums = nums[-M:] + nums[:-M]
print(*nums)
