n = int(input())
names = []
nums = []
for i in range(n):
    name, num = input().split()
    num = int(num)
    names.append(name)
    nums.append(num)
average = sum(nums) / n
S_nums = [abs(num - (average / 2)) for num in nums]
i = S_nums.index(min(S_nums))
print(f"{average / 2:.0f} {names[i]}")
