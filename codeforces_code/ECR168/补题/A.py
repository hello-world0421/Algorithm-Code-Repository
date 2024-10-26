"""
字符串题 | 思维题
"""
for _ in range(int(input())):
    s = list(input())
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            ans = s[:i] + ['a' if s[i] != 'a' else 'b'] + s[i:]
            break
    else:
        ans = s + ['a' if s[-1] != 'a' else 'b']
    print(''.join(ans))