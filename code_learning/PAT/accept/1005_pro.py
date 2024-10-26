n: int = int(input())
nums: list[int] = list(map(int, input().split()))
spaces: dict[int, list[int]] = {}

def collatz_sequence(num: int) -> list[int]:
    sequence = []
    while num != 1:
        if num % 2 == 0:
            num //= 2
        else:
            num = (3 * num + 1) // 2
        sequence.append(num)
    return sequence[:-1]  # 去掉最后一个元素1

for num in nums:
    if any(num in space for space in spaces.values()):
        continue
    new_space = collatz_sequence(num)
    for pre_num in list(spaces.keys()):
        if pre_num in new_space:
            spaces.pop(pre_num)
    spaces[num] = new_space

print(*sorted(spaces.keys(), reverse=True))
