A: list[int | float | str] = []

N, *nums = map(int, input().split())
nums = list(nums)

# (1)
nums_mod_10 = [num for num in nums if num % 10 == 0]
A.append(sum(nums_mod_10) if nums_mod_10 else 'N')

# (2)
nums_mod_5_1 = [num for num in nums if num % 5 == 1]
A.append(sum(num * (-1) ** i for i, num in enumerate(nums_mod_5_1)) if nums_mod_5_1 else 'N')

# (3)
nums_mod_5_2 = [num for num in nums if num % 5 == 2]
A.append(len(nums_mod_5_2) if nums_mod_5_2 else 'N')

# (4)
nums_mod_5_3 = [num for num in nums if num % 5 == 3]
A.append(round(sum(nums_mod_5_3) / len(nums_mod_5_3), 1) if nums_mod_5_3 else 'N')

# (5)
nums_mod_5_4 = [num for num in nums if num % 5 == 4]
A.append(max(nums_mod_5_4) if nums_mod_5_4 else 'N')

print(*A)
