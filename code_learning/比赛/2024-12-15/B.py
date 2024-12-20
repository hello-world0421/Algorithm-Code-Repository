import string

# O(|S| * 26)
s = input()
ans: int = 10 ** 9
for ch in string.ascii_lowercase:
    cnt: int = 0
    for i, si in enumerate(s):
        step = abs(ord(si) - ord(ch))
        cnt += min(step, 26 - step)
    ans = min(ans, cnt)
print(ans)
