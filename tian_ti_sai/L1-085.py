nums = list(map(int, input().split()))
tie = [7, 7, 7, 7, 7, 7]
n = int(input())
for i in range(n):
    for j in range(6):
        tie[j] -= 1
        if tie[j] == nums[j]:
            tie[j] -= 1
print(' '.join(map(str, tie)))
