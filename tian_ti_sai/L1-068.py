n = int(input())
nums = list(map(float, input().split()))
daoshu_nums = [1 / num for num in nums if num != 0]
result = n / sum(daoshu_nums)
print(f"{result:.2f}")
