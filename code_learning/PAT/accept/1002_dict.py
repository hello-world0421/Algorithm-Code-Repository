nums: list[int] = list(map(int, list(input())))

ans: list[str] = []

chinese_num: dict[int, str] = {
    0: 'ling',
    1: 'yi',
    2: 'er',
    3: 'san',
    4: 'si',
    5: 'wu',
    6: 'liu',
    7: 'qi',
    8: 'ba',
    9: 'jiu',
}

for num in map(int, str(sum(nums))):
    ans.append(chinese_num[num])

print(' '.join(ans))
