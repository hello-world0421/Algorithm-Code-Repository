import sys

ans = []
for _ in range(int(input())):
    k, q = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans0 = []
    for i in b:
        nums = [j + 1 for j in range(i)]
        while len(nums) >= min(a):
            for j in a:
                if len(nums) >= j:
                    nums.pop(j - 1)
        ans0.append(len(nums))
    ans.append(' '.join(map(str, ans0)))

sys.stdout.write('\n'.join(ans))