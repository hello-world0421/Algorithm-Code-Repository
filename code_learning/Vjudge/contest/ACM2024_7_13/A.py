n = int(input())
nums = sorted(list(map(int, input().split())))

a, b = 0, 0
while nums:
    if a > b:
        b += nums.pop()
    else:
        a += nums.pop()
print(max(a, b))
