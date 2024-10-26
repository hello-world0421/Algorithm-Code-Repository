import sys

ans = []
for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    A, i = [], 0
    B, j = [], 0
    flag = False
    while len(nums) != 0:
        if len(A) == 0:
            A.append(nums.pop(0))
        if len(A) > n // 2 or len(B) > n // 2:
            ans.append('No')
            break
        if not flag:
            if A[i] <= nums[0]:
                flag = True
                B.append(nums.pop(0))
                if len(B) != 1:
                    j += 1
            else:
                A.append(nums.pop(0))
        else:
            if B[j] <= nums[0]:
                flag = False
                A.append(nums.pop(0))
                i += 1
            else:
                B.append(nums.pop(0))
    else:
        ans.append('Yes')
sys.stdout.write('\n'.join(ans))
