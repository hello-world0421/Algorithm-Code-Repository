n = int(input())
for i in range(1, n+1):
    nums = list(map(int, input()))
    if sum(nums[0:3]) == sum(nums[3:6]):
        print("You are lucky!")
    else:
        print("Wish you good luck.")
