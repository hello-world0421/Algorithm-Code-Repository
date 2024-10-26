n: int = int(input())
nums: list[int] = list(map(int, input().split()))
spaces: dict[int, list[int]] = {}

for num in nums:
    for space in spaces.values():
        if num in space:
            break
    else:
        new_space: list[int] = []
        num_copy = num
        while num_copy != 1:
            if num_copy % 2 == 0:
                num_copy //= 2
            else:
                num_copy = ((3 * num_copy) + 1) // 2
            new_space.append(num_copy)
        new_space.pop()
        for pre_num in list(spaces.keys()):
            if pre_num in new_space:
                spaces.pop(pre_num)
        spaces[num] = new_space
print(*sorted(spaces.keys(), reverse=True))
