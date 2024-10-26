a1, a2, n = map(int, input().split())
nums = [a1, a2]

for i in range(n):
    new_num = nums[i] * nums[i+1]
    if len(str(new_num)) == 2:
        nums.append(int(str(new_num)[0]))
        nums.append(int(str(new_num)[1]))
    else:
        nums.append(new_num)
    if len(nums) >= n:
        break
print(' '.join(map(str, nums[0:n])))
