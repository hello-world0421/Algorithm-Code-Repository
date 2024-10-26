# import sys

# ans = []
# for _ in range(int(input())):
#     int(input())
#     a = list(map(int, input().split()))
#     ans.append(len(a) - len(set(a)))
# sys.stdout.write('\n'.join(map(str, ans)))

# import sys

# ans = [len(list(map(int, input().split())))-len(set(a)) for _ in range(int(input()))]
# sys.stdout.write('\n'.join(map(str, ans)))

from collections import Counter

lst = [1, 2, 3, 1, 2, 3, 4, 5, 1]
counts = Counter(lst)
duplicate_count = sum(1 for count in counts.values() if count > 1)

print(duplicate_count)  # 输出：2 (列表中有两个重复元素)
print(sorted(lst))
