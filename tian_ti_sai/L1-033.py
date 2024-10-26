y, n = input().split()
n = int(n)
old = 0
while (1):
    while (len(y) < 4):
        y = '0' + y
    nums = {'0': 0,
            '1': 0,
            '2': 0,
            '3': 0,
            '4': 0,
            '5': 0,
            '6': 0,
            '7': 0,
            '8': 0,
            '9': 0}
    for i in range(4):
        if (nums[y[i]] == 0):
            nums[y[i]] += 1
    if (sum(nums.values()) == n):
        print(old, y)
        break
    else:
        old += 1
        y = str(int(y) + 1)
