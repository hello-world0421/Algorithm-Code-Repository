n = int(input())
nums = [x * 10 for x in list(map(int, input().split()))]
seat = [[0] for _ in range(n)]
flag = 0

while sum(len(seat[i]) for i in range(n)) != sum(nums):
    if len(seat[0]) == nums[0] and len(seat[1]) == nums[1]:
        flag += 2
        seat[2].append(flag)
        continue
    elif len(seat[0]) == nums[0] and len(seat[2]) == nums[2]:
        flag += 2
        seat[1].append(flag)
        continue
    elif len(seat[1]) == nums[1] and len(seat[2]) == nums[2]:
        flag += 2
        seat[0].append(flag)
        continue
    
    for i in range(n):
        if len(seat[i]) == nums[i]:
            continue
        if seat[i][0] == 0:
            flag += 1
            seat[i][0] = flag
        else:
            flag += 1
            seat[i].append(flag)

for i in range(n):
    print(f"#{i+1}")
    for j in range(nums[i]//10):
        print(" ".join(map(str, seat[i][j*10:j*10+10])))
